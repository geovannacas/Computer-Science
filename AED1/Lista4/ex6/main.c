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

    OrdenarPorSelecao(&lista);
    printf("lista ordenada por selecao: ");
    ImprimirLista(&lista);

    OrdenarPorInsercao(&lista);
    printf("lista ordenada por inserção: ");
    ImprimirLista(&lista);

    return 0;
}
