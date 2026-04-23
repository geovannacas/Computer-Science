/* Teste: atribuir car a variavel int — deve gerar ERRO semantico */
principal
{
    { n: int; c: car; }
    {
        c = 'A';
        n = c;
    }
}
