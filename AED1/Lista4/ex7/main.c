
#include "tad.h"

int main() {
    Lista lista;
    Inicializar(&lista);

    Inserir(&lista, "Maria");
    Inserir(&lista, "Joao");
    Inserir(&lista, "Ana");
    Inserir(&lista, "Pedro");

    printf("lista original: ");
    ImprimirLista(&lista);

    Quicksort(&lista, 0, lista.indice - 1);
    printf("lista ordenada por quick-sort: ");
    ImprimirLista(&lista);

    return 0;
}