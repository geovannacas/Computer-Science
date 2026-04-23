/* Teste: comparar int com car — deve gerar ERRO semantico */
principal
{
    { n: int; c: car; }
    {
        n = 10;
        c = 'Z';
        se (n > c) entao
            escreva n;
        fimse
    }
}
