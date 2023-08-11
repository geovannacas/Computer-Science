#include "tad.h"

int main() {
    Vetor vetor1, vetor2, vetor3, resultado;
    
    Inicializar(&vetor1);
    Inicializar(&vetor2);
    Inicializar(&vetor3);
    Inicializar(&resultado);
    
    Inserir(&vetor1, 1);
    Inserir(&vetor1, 3);
    Inserir(&vetor1, 5);
    
    Inserir(&vetor2, 2);
    Inserir(&vetor2, 4);
    Inserir(&vetor2, 6);
    
    Inserir(&vetor3, 7);
    Inserir(&vetor3, 8);
    Inserir(&vetor3, 9);
    
    MergeSort(&resultado, &vetor1, &vetor2, &vetor3);
    
    printf("Vetor resultante: ");
    Imprime(resultado);
    
    return 0;
}
