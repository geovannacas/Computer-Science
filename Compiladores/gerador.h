#ifndef GERADOR_H
#define GERADOR_H

#include "tipos.h"

/*
 * Gera codigo assembly MIPS para SPIM/MARS a partir da AST.
 * O programa deve estar semanticamente correto antes de chamar esta funcao.
 * A saida e escrita em stdout.
 *
 * Convencoes de registradores:
 *   $fp  - frame pointer fixo no inicio do programa (nunca muda)
 *   $sp  - stack pointer, ajustado na entrada/saida de blocos com declaracoes
 *   $t0  - resultado de expressoes
 *   $t1  - auxiliar em operacoes binarias
 *
 * Layout de variaveis:
 *   Cada variavel tem um offset negativo a partir de $fp.
 *   Escopos aninhados acumulam offsets sequencialmente.
 */
void geraCodigoMIPS(NoAST* raiz);

#endif
