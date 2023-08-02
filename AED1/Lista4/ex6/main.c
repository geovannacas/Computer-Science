#include "tad.h"

int main() {
    Fila fila;
    Inicializar(&fila);

    Inserir(&fila, "Maria");
    Inserir(&fila, "Joao");
    Inserir(&fila, "Ana");
    Inserir(&fila, "Pedro");

    printf("Fila original: ");
    ImprimirFila(&fila);

    // Ordenar por seleção
    OrdenarPorSelecao(&fila);
    printf("Fila ordenada por selecao: ");
    ImprimirFila(&fila);

    // Ordenar por inserção
    OrdenarPorInsercao(&fila);
    printf("Fila ordenada por inserção: ");
    ImprimirFila(&fila);

    // Liberar a fila antes de terminar o programa
    LiberarFila(&fila);
    return 0;
}
