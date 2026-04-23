/* Teste: mesma variavel declarada duas vezes no mesmo escopo — deve gerar ERRO semantico */
principal
{
    { x, x: int; }
    {
        x = 5;
        escreva x;
        novalinha;
    }
}
