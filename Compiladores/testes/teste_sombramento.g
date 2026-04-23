/* Teste: shadowing — variavel interna sobrepoe a externa durante seu escopo.
   Saida esperada:
     42
     99
     42
*/
principal
{
    { n: int; }
    {
        n = 42;
        escreva n;
        novalinha;
        {
            { n: int; }
            {
                n = 99;
                escreva n;
                novalinha;
            }
        }
        escreva n;
        novalinha;
    }
}
