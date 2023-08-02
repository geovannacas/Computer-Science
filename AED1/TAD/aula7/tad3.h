typedef struct retangulo Retangulo;
Retangulo* criar_retangulo(int largura_entry, int altura_entry);
void apresentar(Retangulo* r);
int perimetro(Retangulo* r);
int area(Retangulo* r);
void liberar(Retangulo* r);
