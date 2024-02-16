#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct Funcionario
 * @brief Estrutura para representar um funcionário.
 */
struct Funcionario{
    char especializacao[50];
    char nome[50];
    int id;
    int horas_trabalhadas;
    int disponibilidade[3];
    int manha;
    int tarde;
    int noite;
    float salario;
    struct Funcionario *prox;
};
typedef struct Funcionario Funcionario;

/**
 * @brief Estruturas para representar os departamentos
 */
typedef struct{
    Funcionario *inicio;
    Funcionario *final;
}Neurologia;

typedef struct{
    Funcionario *inicio;
    Funcionario *final;
}Cardiologia;

typedef struct{
    Funcionario *inicio;
    Funcionario *final;
}Trauma;

typedef struct{
    Funcionario *inicio;
    Funcionario *final;
}Pediatria;

typedef struct{
    Funcionario *inicio;
    Funcionario *final;
}Enfermagem;

typedef struct{
    Funcionario *inicio;
    Funcionario *final;
}Pneumologia;

typedef struct{
    Funcionario *inicio;
    Funcionario *final;
}Ortopedia;

typedef struct{
    Funcionario *inicio;
    Funcionario *final;
}Tecnico_de_enfermeagem;

/**
 * @struct Lista_funcionarios
 * @brief Estrutura para representar uma lista de departamentos e funcionários.
 */
typedef struct{
    Neurologia *neurologia;
    Cardiologia *cardiologia;
    Trauma *trauma;
    Pediatria *pediatria;
    Enfermagem *enfermagem;
    Pneumologia *pneumologia;
    Ortopedia *ortopedia;
    Tecnico_de_enfermeagem *tecnico_de_enfermagem;
}Lista_funcionarios;

/**
 * @struct Lista_funcionarios_estatica
 * @brief Estrutura para representar uma lista estática de funcionários.
 */
typedef struct{
    int horas_trabalhadas[10];
    int disponibilidade_m[10];
    int disponibilidade_t[10];
    int disponibilidade_n[10]; // disponibilidade nos turnos manha, tarde e noite
    char nome[100][100];
    int id[10];
    int inicio;
}Lista_funcionarios_estatica;

void inicia_lista(Lista_funcionarios *lista_funcionarios);

Funcionario *aloca_funcionario();

void insercao_funcionario(Lista_funcionarios *lista_funcionarios, Funcionario funcionario);

void insere_turno(Lista_funcionarios *lista_funcionarios, Funcionario Funcionario, char turno[]); // botar a pessoa pra trabalhar hj

void remove_turno(Lista_funcionarios *lista_funcionarios, Funcionario funcionario, char turno[]);

void troca_turno(Lista_funcionarios *lista_funcionarios, Funcionario funcionario, char turno[], char turno_trocado[]);

int lista_vazia(Lista_funcionarios *lista_funcionarios, Funcionario funcionario);

void restricao(Lista_funcionarios *lista_funcionarios, Funcionario funcionario);

void troca(int *x, int *y);

int particionar(Lista_funcionarios_estatica *vetor, int inicio, int fim);

void quickSort(Lista_funcionarios_estatica *lista, int inicio, int fim);

int busca_binaria(Lista_funcionarios_estatica *busca, int left, int right, int id, int n);

void consulta_disponibilidade(Lista_funcionarios *lista_funcionarios, Funcionario funcionario);

void imprime(Lista_funcionarios *lista, Funcionario funcionario);

void adicionar_horas(Lista_funcionarios *lista, Funcionario funcionario, int horas);

void limpa_buffer();

int ja_foi_inserido(Lista_funcionarios *lista_funcionarios, Funcionario funcionario);

void libera_memoria(Lista_funcionarios *lista_funcionarios);

void calcula_salario (Lista_funcionarios *lista_funcionarios, Funcionario funcionario);

void merge(Lista_funcionarios_estatica *vetor, int inicio, int meio, int fim);

void mergeSort(Lista_funcionarios_estatica *vetor, int inicio, int fim);

void ordena_nome(Lista_funcionarios *lista_funcionarios, Funcionario funcionario);

void bubbleSort(Funcionario **arr, int n);