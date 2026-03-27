/* * Teste de Cobertura:
 * - Declarações múltiplas e constantes com sinal (+/-)
 * - Comandos vazios (;), cadeias de caracteres e novalinha
 * - Decisões (se/entao/senao) e expressões lógicas complexas
 */

principal
a, b, c : int;
letra : car;
{
    ;
    ;
    
    a = -50;
    b = +100;
    
    escreva "Teste de String direta"; /* Token CADEIACARACTERES */
    escreva (a + b);                /* Token Expr */
    novalinha;
    
    se (a < b) entao
        escreva "Caminho A";
    senao
        escreva "Caminho B";
    fimse;
    
    se (!((a == b) || (c != a))) entao
        ;
    fimse;
}