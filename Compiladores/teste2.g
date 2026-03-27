/* **Teste de escopo e blocos aninhados:**
 * - Declaração de variáveis locais em diferentes níveis de profundidade
 * - Uso de blocos como comandos dentro de outros blocos
 * - Validação da visibilidade de variáveis entre escopos internos e externos
 */

principal
global : int;
{
    global = 100;
    escreva "Valor global:";
    escreva global;
    novalinha;

    /* Inicio de um bloco interno (Comando -> Bloco) */
    local : int;
    {
        local = 50;
        escreva "Valor local interno:";
        escreva local;
        
        /* Mais um nível de aninhamento */
        {
            escreva "Acessando global de dentro de dois blocos:";
            escreva global;
        }
    }
    
    escreva "De volta ao bloco principal";
}