typedef struct cubo Cubo;

Cubo* criar_cubo(float aresta);
void destruir_cubo (Cubo* c);
float comprimento_aresta(Cubo* c);
float area_face(Cubo* c);
float area_total(Cubo* c);
float volume(Cubo* c);