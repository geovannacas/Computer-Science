#include <stdio.h>

// Definição da union para permitir a interpretação de 32 bits
// como um float ou como um unsigned int.
typedef union {
    float f;
    unsigned int i;
} myfloatpoint_union;

// Função para extrair o bit de sinal (o bit mais à esquerda, 31)
unsigned int getsig(unsigned int i) {
    // Desloca 31 bits para a direita, movendo o bit de sinal para a posição 0,
    // e aplica uma máscara para isolá-lo.
    return (i >> 31) & 0x1;
}

// Função para extrair os 8 bits do expoente (bits 30 a 23)
unsigned int getexp(unsigned int i) {
    // Desloca 23 bits para a direita para alinhar o expoente,
    // e aplica uma máscara (0xFF = 11111111 em binário) para isolar os 8 bits.
    return (i >> 23) & 0xFF;
}

// Função para extrair os 23 bits da fração (bits 22 a 0)
unsigned int getfrac(unsigned int i) {
    // Aplica uma máscara (0x7FFFFF) para zerar todos os bits exceto os 23 da fração.
    return i & 0x7FFFFF;
}

// Função para reconstruir o unsigned int a partir de suas partes
unsigned int makefloat(unsigned int s, unsigned int e, unsigned int f) {
    // Combina as partes usando deslocamento de bits e a operação OR.
    return (s << 31) | (e << 23) | (f & 0x7FFFFF);
}

// Função principal do exercício
void myfloatpoint() {
    myfloatpoint_union u;

    // Linha 08: Atribui o valor inicial
    u.f = 42.1875f; // O 'f' no final garante que é um literal float
    printf("Valor inicial: %f (Representação int: 0x%X)\n\n", u.f, u.i);

    // Linhas 10-12: Extrai os componentes
    unsigned int s = getsig(u.i);
    unsigned int e = getexp(u.i);
    unsigned int f = getfrac(u.i);
    printf("--- 1. Extração dos Componentes ---\n");
    printf("Sinal (s)    : %u\n", s);
    printf("Expoente (e) : %u (0x%X)\n", e, e);
    printf("Fração (f)   : %u (0x%X)\n\n", f, f);

    // Linha 14: Calcula 'v' com a operação XOR
    unsigned int v = e ^ 0x27;
    printf("--- 2. Cálculos Intermediários ---\n");
    printf("v = e ^ 0x27   : %u (0x%X)\n", v, v);

    // Linha 15: Calcula 'm' com deslocamento de bits
    int shift_amount = 'T' / 6; // ASCII 'T' é 84. 84 / 6 = 14.
    unsigned int m = v << shift_amount;
    printf("m = v << %d    : %u (0x%X)\n", shift_amount, m, m);

    // Linha 16: Atualiza 'f' com a operação AND
    f = f & m;
    printf("f = f & m      : %u (0x%X)\n\n", f, f);

    // Linha 18: Reconstrói o número
    u.i = makefloat(s, e, f);
    printf("--- 3. Reconstrução ---\n");
    printf("Novo int (u.i) : 0x%X\n\n", u.i);


    // Linha 20: Imprime o resultado final
    printf("=======================================\n");
    printf(">> Valor impresso na linha 20: %f\n", u.f);
    printf("=======================================\n");
}

int main() {
    myfloatpoint();
    return 0;
}