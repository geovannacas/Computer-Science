#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct No{
    char caractere;
    struct No *proximo;
} No;

typedef struct Pilha{
    No *topo;
} Pilha;

void Inicializar(Pilha *pilha);

int PilhaVazia(Pilha* pilha);

void Empilhar(Pilha* pilha, char caractere);

void Imprime(Pilha *pilha);

void VerificarPalindromo(Pilha *pilha);