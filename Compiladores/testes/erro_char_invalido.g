/* Teste: caractere invalido '@' — deve gerar ERRO lexico */
principal
{
    { x: int; }
    {
        x = 5@3;
    }
}
