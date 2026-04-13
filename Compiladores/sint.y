%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

NoAST* raiz = NULL;

void yyerror(char const *s);
%}

%code requires {
    #include "tipos.h"
}

%union {
    int   valor_int;
    char* id;
    NoAST* node;
}

%token PRINCIPAL SE ENTAO SENAO FIMSE ENQUANTO LEIA ESCREVA NOVALINHA
%token INT CAR OU E IGUAL DIFERENTE MAIORIGUAL MENORIGUAL
%token <id> IDENTIFICADOR CADEIACARACTERES CARCONST INTCONST

%type <node> Bloco VarSection ListaDeclVar DeclVarTail Tipo
%type <node> ListaComando Comando
%type <node> Expr OrExpr AndExpr EqExpr DesigExpr AddExpr MulExpr UnExpr PrimExpr

%%

Programa : PRINCIPAL Bloco
             { raiz = $2; }
;

/*
 * Bloco sem declaracoes:   '{' ListaComando '}'
 * Bloco com declaracoes:   VarSection '{' ListaComando '}'
 *   onde VarSection ja envolve a secao de declaracoes com '{' '}'
 *
 * AST: NO_BLOCO
 *        filho1 = lista de NO_DECL_VAR  (NULL se sem declaracoes)
 *        filho2 = lista de comandos
 */
Bloco : '{' ListaComando '}'
          { $$ = criaNo(NO_BLOCO, NULL, yylineno, NULL, $2, NULL); }
      | VarSection '{' ListaComando '}'
          { $$ = criaNo(NO_BLOCO, NULL, yylineno, $1, $3, NULL); }
;

/* VarSection inclui as chaves conforme a gramatica: '{' ListaDeclVar '}' */
VarSection : '{' ListaDeclVar '}'
               { $$ = $2; }
;

/*
 * ListaDeclVar: uma ou mais linhas de declaracao.
 * Cada linha: IDENTIFICADOR [, IDENTIFICADOR]* : Tipo ;
 * Todos os IDs da mesma linha compartilham o mesmo Tipo.
 * Nos NO_DECL_VAR sao encadeados por ->proximo.
 */
ListaDeclVar : IDENTIFICADOR DeclVarTail ':' Tipo ';' ListaDeclVar
                 {
                     NoAST* decl = criaNo(NO_DECL_VAR, $1, yylineno, $4, NULL, NULL);
                     free($1);
                     /* propaga copia do tipo para os extras e encadeia */
                     NoAST* extra = $2;
                     while (extra != NULL) {
                         extra->filho1 = criaNo(NO_TIPO, $4->lexema, $4->linha, NULL, NULL, NULL);
                         extra = extra->proximo;
                     }
                     if ($2 != NULL) adicionaIrmao(decl, $2);
                     if ($6 != NULL) adicionaIrmao(decl, $6);
                     $$ = decl;
                 }
             | IDENTIFICADOR DeclVarTail ':' Tipo ';'
                 {
                     NoAST* decl = criaNo(NO_DECL_VAR, $1, yylineno, $4, NULL, NULL);
                     free($1);
                     NoAST* extra = $2;
                     while (extra != NULL) {
                         extra->filho1 = criaNo(NO_TIPO, $4->lexema, $4->linha, NULL, NULL, NULL);
                         extra = extra->proximo;
                     }
                     if ($2 != NULL) adicionaIrmao(decl, $2);
                     $$ = decl;
                 }
;

/* Zero ou mais ", IDENTIFICADOR" extras na mesma linha de declaracao */
DeclVarTail : /* vazio */
                { $$ = NULL; }
            | ',' IDENTIFICADOR DeclVarTail
                {
                    /* tipo sera preenchido pelo pai apos reducao */
                    NoAST* decl = criaNo(NO_DECL_VAR, $2, yylineno, NULL, NULL, NULL);
                    free($2);
                    if ($3 != NULL) adicionaIrmao(decl, $3);
                    $$ = decl;
                }
;

Tipo : INT  { $$ = criaNo(NO_TIPO, "int", yylineno, NULL, NULL, NULL); }
     | CAR  { $$ = criaNo(NO_TIPO, "car", yylineno, NULL, NULL, NULL); }
;

/* Comandos encadeados por ->proximo */
ListaComando : Comando
                 { $$ = $1; }
             | Comando ListaComando
                 {
                     if ($1 == NULL) {
                         $$ = $2;
                     } else {
                         adicionaIrmao($1, $2);
                         $$ = $1;
                     }
                 }
;

/*
 * Comando: conforme a gramatica da spec.
 * SE/ENQUANTO recebem Comando (singular), nao ListaComando.
 */
Comando : ';'
            { $$ = NULL; }
        | Expr ';'
            { $$ = $1; }
        | LEIA IDENTIFICADOR ';'
            {
                NoAST* id = criaNo(NO_IDENTIFICADOR, $2, yylineno, NULL, NULL, NULL);
                free($2);
                $$ = criaNo(NO_LEIA, NULL, yylineno, id, NULL, NULL);
            }
        | ESCREVA Expr ';'
            { $$ = criaNo(NO_ESCREVA, NULL, yylineno, $2, NULL, NULL); }
        | ESCREVA CADEIACARACTERES ';'
            {
                NoAST* str = criaNo(NO_CADEIACARACTERES, $2, yylineno, NULL, NULL, NULL);
                free($2);
                $$ = criaNo(NO_ESCREVA, NULL, yylineno, str, NULL, NULL);
            }
        | NOVALINHA ';'
            { $$ = criaNo(NO_NOVALINHA, NULL, yylineno, NULL, NULL, NULL); }
        | SE '(' Expr ')' ENTAO Comando FIMSE
            { $$ = criaNo(NO_SE, NULL, yylineno, $3, $6, NULL); }
        | SE '(' Expr ')' ENTAO Comando SENAO Comando FIMSE
            { $$ = criaNo(NO_SE, NULL, yylineno, $3, $6, $8); }
        | ENQUANTO '(' Expr ')' Comando
            { $$ = criaNo(NO_ENQUANTO, NULL, yylineno, $3, $5, NULL); }
        | Bloco
            { $$ = $1; }
;

Expr : OrExpr
         { $$ = $1; }
     | IDENTIFICADOR '=' Expr
         {
             NoAST* id = criaNo(NO_IDENTIFICADOR, $1, yylineno, NULL, NULL, NULL);
             free($1);
             $$ = criaNo(NO_ATRIBUICAO, NULL, yylineno, id, $3, NULL);
         }
;

OrExpr : OrExpr OU AndExpr
           { $$ = criaNo(NO_OU, NULL, yylineno, $1, $3, NULL); }
       | AndExpr
           { $$ = $1; }
;

AndExpr : AndExpr E EqExpr
            { $$ = criaNo(NO_E, NULL, yylineno, $1, $3, NULL); }
        | EqExpr
            { $$ = $1; }
;

EqExpr : EqExpr IGUAL DesigExpr
           { $$ = criaNo(NO_IGUAL, NULL, yylineno, $1, $3, NULL); }
       | EqExpr DIFERENTE DesigExpr
           { $$ = criaNo(NO_DIFERENTE, NULL, yylineno, $1, $3, NULL); }
       | DesigExpr
           { $$ = $1; }
;

DesigExpr : DesigExpr '<' AddExpr
              { $$ = criaNo(NO_MENOR, NULL, yylineno, $1, $3, NULL); }
          | DesigExpr '>' AddExpr
              { $$ = criaNo(NO_MAIOR, NULL, yylineno, $1, $3, NULL); }
          | DesigExpr MAIORIGUAL AddExpr
              { $$ = criaNo(NO_MAIORIGUAL, NULL, yylineno, $1, $3, NULL); }
          | DesigExpr MENORIGUAL AddExpr
              { $$ = criaNo(NO_MENORIGUAL, NULL, yylineno, $1, $3, NULL); }
          | AddExpr
              { $$ = $1; }
;

AddExpr : AddExpr '+' MulExpr
            { $$ = criaNo(NO_SOMA, NULL, yylineno, $1, $3, NULL); }
        | AddExpr '-' MulExpr
            { $$ = criaNo(NO_SUBTRACAO, NULL, yylineno, $1, $3, NULL); }
        | MulExpr
            { $$ = $1; }
;

MulExpr : MulExpr '*' UnExpr
            { $$ = criaNo(NO_MULTIPLICACAO, NULL, yylineno, $1, $3, NULL); }
        | MulExpr '/' UnExpr
            { $$ = criaNo(NO_DIVISAO, NULL, yylineno, $1, $3, NULL); }
        | UnExpr
            { $$ = $1; }
;

UnExpr : '-' PrimExpr
           { $$ = criaNo(NO_NEGACAO_ARITMETICA, NULL, yylineno, $2, NULL, NULL); }
       | '!' PrimExpr
           { $$ = criaNo(NO_NEGACAO_LOGICA, NULL, yylineno, $2, NULL, NULL); }
       | PrimExpr
           { $$ = $1; }
;

PrimExpr : IDENTIFICADOR
             { $$ = criaNo(NO_IDENTIFICADOR, $1, yylineno, NULL, NULL, NULL); free($1); }
         | CARCONST
             { $$ = criaNo(NO_CARCONST, $1, yylineno, NULL, NULL, NULL); free($1); }
         | INTCONST
             { $$ = criaNo(NO_INTCONST, $1, yylineno, NULL, NULL, NULL); free($1); }
         | '(' Expr ')'
             { $$ = $2; }
;

%%

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "ERRO: Uso correto: ./g-v1 arquivo.g\n");
        exit(1);
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "ERRO: arquivo nao pode ser aberto: %s\n", argv[1]);
        exit(1);
    }

    if (yyparse() == 0 && raiz != NULL) {
        imprimeArvore(raiz, 0);
    }

    fclose(yyin);
    return 0;
}

void yyerror(char const *s) {
    fprintf(stderr, "ERRO: %s na linha %d\n", s, yylineno);
    exit(1);
}
