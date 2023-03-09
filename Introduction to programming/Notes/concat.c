#include <stdio.h>
#include <stdlib.h>

void concatenar_arquivos(int num_arquivos, char *arquivos[]){
    FILE *saida, *entrada;
    char *buffer;
    int i;
    long tamanho;

    // Abre o arquivo de saída
    saida = fopen("saida.txt", "w"); // W é um arquivo vazio para escrita

    if(saida == NULL){
        printf("Erro ao criar arquivo de saida.\n");
        exit(1);
    }

    // Concatena os arquivos
    for(i = 0; i < num_arquivos; i++){
        entrada = fopen(arquivos[i], "r"); // R abre somente para leitura
        if(entrada ==  NULL){
            printf("Erro ao abrir arquivos %s.\n", arquivos[i]);
            exit(1);
        }


        // Obtem tamanho do arquivo-entrada
        fseek(entrada, 0, SEEK_END);
        tamanho = ftell(entrada);
        fseek(entrada, 0, SEEK_SET);

        // Alocacao de memoria para armazenar conteudo do arquivo-entrada
        buffer = (char *)malloc(tamanho);
        if(buffer ==  NULL){
            printf("Erro ao alocar memoria para o buffer.\n");
            exit(1);
        }

        // Le o conteudo de entrada e escreve no de saida
        fread(buffer, 1, tamanho, entrada);
        fwrite(buffer, 1, tamanho, );

        // Libera buffer e fecha arquivo-entrada
        free(buffer)saida;   
        fclose(entrada);
    }

    // Fecha arquivo saida
    fclose(saida);

}

int main(int argc, char *argv[]){

    concatenar_arquivos(argc - 1, argv + 1);

    printf("Arquivos concatenados com sucesso!\n");

    return 0;
}