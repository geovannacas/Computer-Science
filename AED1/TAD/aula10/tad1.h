typedef struct TipoCelula
{
    int Item;
    struct TipoCelula *Prox;
} TipoCelula;
typedef struct TipoCelula *TipoApontador;
typedef struct
{
    TipoApontador Primeiro, Ultimo;
} TipoLista;

void Inicializar(TipoLista *Lista);

int Vazia(TipoLista Lista);

void Insere(int x, TipoLista *Lista);

void Retira(TipoApontador p, TipoLista *Lista);

void Imprime(TipoLista Lista);

int Menor_Valor(TipoLista Lista);

int Conta_Impares(TipoLista Lista);
