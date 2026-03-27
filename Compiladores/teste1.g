/* **Teste de lógica, repetição e entrada:**
 * - Uso de 'leia' para entrada e 'enquanto' para laços de repetição[cite: 20].
 * - Expressões lógicas complexas (OU, E, NÃO) e operadores relacionais[cite: 22, 24, 58].
 * - Validação de precedência em expressões aritméticas e lógicas[cite: 35, 39, 58].
 */

principal
val1, val2, contador : int;
continua : car;
{
    escreva "Digite dois valores:";
    leia val1;
    leia val2;
    
    contador = 0;
    continua = 's';
    
    /* Teste de expressao logica complexa */
    enquanto (contador < 10 && (continua == 's' || continua == 'S'))
    {
        se (val1 != val2) entao
            se (val1 >= val2) entao
                val1 = val1 - 1;
            senao
                val1 = val1 + 1;
            fimse;
        fimse;
        
        contador = contador + 1;
        
        /* Simula uma verificacao de parada */
        se (!(val1 == val2)) entao
            escreva "Ainda nao sao iguais";
        senao
            continua = 'n';
        fimse;
    }
    
    escreva "Fim do laco";
}