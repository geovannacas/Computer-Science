/* **Teste básico de sucesso:**
 * - Validação da estrutura obrigatória: 'principal' e bloco de comandos
 * - Declaração de variáveis de tipos simples (int e car)
 * - Atribuições básicas e comandos de saída (escreva, novalinha)
 * - Estrutura de decisão simples (se-entao-fimse)
 */
principal
x, y : int;
c : car;
{
    x = 10;
    y = 20;
    c = 'A';
    escreva x + y;
    novalinha;
    se (x > 0) entao
        escreva "positivo";
    fimse;
}
