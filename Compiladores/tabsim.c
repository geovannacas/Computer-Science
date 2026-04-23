#include "tabsim.h"

static unsigned int hash_nome(const char* s) {
    unsigned int h = 0;
    while (*s) h = h * 31u + (unsigned char)*s++;
    return h % HASH_TABSIM;
}

PilhaTabelas* iniciaTabela(void) {
    PilhaTabelas* p = (PilhaTabelas*) malloc(sizeof(PilhaTabelas));
    if (!p) { fprintf(stderr, "ERRO: falha de alocacao de memoria\n"); exit(1); }
    p->topo             = NULL;
    p->offset_corrente  = 0;
    return p;
}

void criaEscopo(PilhaTabelas* pilha) {
    TabelaSimbolos* t = (TabelaSimbolos*) calloc(1, sizeof(TabelaSimbolos));
    if (!t) { fprintf(stderr, "ERRO: falha de alocacao de memoria\n"); exit(1); }
    t->num_vars    = 0;
    t->offset_base = pilha->offset_corrente;
    t->anterior    = pilha->topo;
    pilha->topo    = t;
}

int insereTabela(PilhaTabelas* pilha, const char* nome,
                 const char* tipo, int linha) {
    if (!pilha->topo) return 0;
    if (pesquisaEscopoAtual(pilha, nome)) return 0; /* ja declarado neste escopo */

    unsigned int h = hash_nome(nome);
    Simbolo* s = (Simbolo*) malloc(sizeof(Simbolo));
    if (!s) { fprintf(stderr, "ERRO: falha de alocacao de memoria\n"); exit(1); }
    s->nome   = strdup(nome);
    s->tipo   = strdup(tipo);
    s->linha  = linha;
    pilha->offset_corrente -= 4;
    s->offset = pilha->offset_corrente;
    s->prox   = pilha->topo->buckets[h];
    pilha->topo->buckets[h] = s;
    pilha->topo->num_vars++;
    return 1;
}

Simbolo* pesquisaEscopoAtual(PilhaTabelas* pilha, const char* nome) {
    if (!pilha->topo) return NULL;
    unsigned int h = hash_nome(nome);
    Simbolo* s = pilha->topo->buckets[h];
    while (s) {
        if (strcmp(s->nome, nome) == 0) return s;
        s = s->prox;
    }
    return NULL;
}

Simbolo* pesquisaTabela(PilhaTabelas* pilha, const char* nome) {
    TabelaSimbolos* t = pilha->topo;
    while (t) {
        unsigned int h = hash_nome(nome);
        Simbolo* s = t->buckets[h];
        while (s) {
            if (strcmp(s->nome, nome) == 0) return s;
            s = s->prox;
        }
        t = t->anterior;
    }
    return NULL;
}

int removeEscopo(PilhaTabelas* pilha) {
    if (!pilha->topo) return 0;
    TabelaSimbolos* t = pilha->topo;
    int frame_bytes = t->num_vars * 4;
    pilha->offset_corrente = t->offset_base;

    for (int i = 0; i < HASH_TABSIM; i++) {
        Simbolo* s = t->buckets[i];
        while (s) {
            Simbolo* prox = s->prox;
            free(s->nome);
            free(s->tipo);
            free(s);
            s = prox;
        }
    }
    pilha->topo = t->anterior;
    free(t);
    return frame_bytes;
}

void liberaTabela(PilhaTabelas* pilha) {
    while (pilha->topo) removeEscopo(pilha);
    free(pilha);
}
