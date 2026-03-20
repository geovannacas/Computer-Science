#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_PESSOAS 100
#define DB_FILE "database.txt"

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

// --- DADOS GLOBAIS COMPARTILHADOS ---
Pessoa pessoas[MAX_PESSOAS];
int num_pessoas = 0;
pthread_mutex_t lock;

// Função para salvar todos os dados da memória para o arquivo
void save_data_to_file() {
    FILE *file = fopen(DB_FILE, "w");
    if (file == NULL) {
        perror("Nao foi possivel abrir o arquivo para escrita");
        return;
    }
    for (int i = 0; i < num_pessoas; i++) {
        fprintf(file, "%s|%d\n", pessoas[i].nome, pessoas[i].idade);
    }
    fclose(file);
    printf("Dados salvos em %s\n", DB_FILE);
}

// Função para carregar os dados do arquivo para a memória na inicialização
void load_data_from_file() {
    FILE *file = fopen(DB_FILE, "r");
    if (file == NULL) {
        printf("Arquivo de banco de dados nao encontrado. Comecando do zero.\n");
        return;
    }
    // Usa strtok para separar os campos. O delimitador é "|" ou o pulo de linha "\n"
    while (num_pessoas < MAX_PESSOAS &&
           fscanf(file, "%99[^|]|%d\n", pessoas[num_pessoas].nome, &pessoas[num_pessoas].idade) == 2) {
        num_pessoas++;
    }
    fclose(file);
    printf("%d registros carregados de %s\n", num_pessoas, DB_FILE);
}


void *handle_client(void *client_socket_ptr) {
    int client_socket = *(int*)client_socket_ptr;
    free(client_socket_ptr);

    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE * 5];
    int read_size;

    if ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        char* command_str = strdup(buffer);
        char* command = strtok(command_str, "|");

        if (command != NULL) {
            if (strcmp(command, "INSERT") == 0) {
                char* nome = strtok(NULL, "|");
                char* idade_str = strtok(NULL, "|");

                pthread_mutex_lock(&lock);
                if (nome != NULL && idade_str != NULL && num_pessoas < MAX_PESSOAS) {
                    strcpy(pessoas[num_pessoas].nome, nome);
                    pessoas[num_pessoas].idade = atoi(idade_str);
                    num_pessoas++;
                    save_data_to_file(); // Salva no arquivo a cada inserção
                    snprintf(response, sizeof(response), "SUCCESS|Pessoa inserida.\n");
                } else {
                    snprintf(response, sizeof(response), "ERROR|Dados invalidos.\n");
                }
                pthread_mutex_unlock(&lock);
                
                send(client_socket, response, strlen(response), 0);

            } else if (strcmp(command, "LIST") == 0) {
                response[0] = '\0';
                pthread_mutex_lock(&lock);
                for (int i = 0; i < num_pessoas; i++) {
                    char temp_buffer[200];
                    snprintf(temp_buffer, sizeof(temp_buffer), "%s|%d\n", pessoas[i].nome, pessoas[i].idade);
                    strcat(response, temp_buffer);
                }
                pthread_mutex_unlock(&lock);
                
                strcat(response, "END\n");
                send(client_socket, response, strlen(response), 0);
            } else {
                snprintf(response, sizeof(response), "ERROR|Comando desconhecido.\n");
                send(client_socket, response, strlen(response), 0);
            }
        }
        free(command_str);
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr;

    pthread_mutex_init(&lock, NULL);
    load_data_from_file();

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind falhou"); return 1;
    }
    listen(server_socket, 10);
    printf("Servidor escutando na porta %d...\n", PORT);

    while (1) {
        client_socket = accept(server_socket, NULL, NULL);

        pthread_t thread_id;
        int *new_sock = malloc(sizeof(int));
        *new_sock = client_socket;

        if (pthread_create(&thread_id, NULL, handle_client, (void*) new_sock) < 0) {
            perror("nao foi possivel criar a thread");
            free(new_sock);
        }
    }

    pthread_mutex_destroy(&lock);
    close(server_socket);
    return 0;
}