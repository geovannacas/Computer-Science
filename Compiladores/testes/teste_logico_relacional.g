/* Teste: operadores logicos e relacionais combinados.
   a=5, b=3, c=7
   Saida esperada:
     (a>b) & (c>a)  => 1
     (a==b) || (c>a) => 1
     !(a==b)         => 1
     (a>=5) & !(b>a) => 1
*/
principal
{
    { a, b, c, res: int; }
    {
        a = 5;
        b = 3;
        c = 7;

        res = (a > b) & (c > a);
        escreva res;
        novalinha;

        res = (a == b) || (c > a);
        escreva res;
        novalinha;

        res = !(a == b);
        escreva res;
        novalinha;

        res = (a >= 5) & !(b > a);
        escreva res;
        novalinha;
    }
}
