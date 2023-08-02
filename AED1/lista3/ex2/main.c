#include "tad.h"

int main(){
    Fila fila;
    Inicializar(&fila);

    Enfileirar(&fila, 10);
    Enfileirar(&fila, 20);
    Enfileirar(&fila, 30);
    
    Imprime(&fila);

    Desenfileirar(&fila);
    
    Imprime(&fila);

    return 0;
}