%{
/* Chamadas externas e definicoes de funcoes auxiliares, variaveis globais, etc. */        
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sint.h"
#include "tipos.h"

extern int yylex();
extern int yylineno; 
extern char* yytext;
extern FILE* yyin;

struct no* raiz; // Ponteiro para a raiz da arvore sintatica

void yyerror(char const *s);

%}

// Definicao dos tokens

%token PRINCIPAL IDENTIFICADOR INT CAR
%token LEIA ESCREVA NOVALINHA
%token SE ENTAO SENAO FIMSE ENQUANTO
%token CADEIACARACTERES OU E IGUAL DIFERENTE
%token MAIORIGUAL MENORIGUAL CARCONST INTCONST

// Definicao dos tipos de simbolos e ponteiro para a arvore 

%union {
    int valor_int;      
    char* id;          
    struct no* node;    
}

// Definicao de quais simbolos vao retornar nós

%type <node> Bloco ListaComando Comando Expr OrExpr AndExpr EqExpr DesigExpr AddExpr MulExpr UnExpr PrimExpr

%%  

// Substituir TODOS o AST por sua definicao de nó, ou seja, o tipo de nó que cada simbolo vai retornar

/* Regras da gramatica  */

Programa : PRINCIPAL Bloco { raiz = $2; }
;           

Bloco	: '{' ListaComando '}' { $$ = $2; }
        | VarSection'{' ListaComando '}'  { $$ = $3; }
;

VarSection : ListaDeclVar
;

ListaDeclVar: IDENTIFICADOR DeclVar ':' Tipo ';' ListaDeclVar
            | IDENTIFICADOR DeclVar ':' Tipo ';'
;

DeclVar: /* vazio */
        | ',' IDENTIFICADOR DeclVar

Tipo:   INT 
        | CAR
;

ListaComando: Comando { $$ = $1; }
            | Comando ListaComando { $$ = CriaNo(AST, NULL, yylineno, $1, $2); }
;

Comando: ';' 
        | Expr ';' { $$ = $1; }
        | LEIA IDENTIFICADOR ';' { $$ = CriaNo(AST, $2, yylineno, NULL, NULL); }
        | ESCREVA Expr ';' { $$ = CriaNo(AST, NULL, yylineno, $2, NULL); }
        | ESCREVA CADEIACARACTERES ';' { $$ = CriaNo(AST, yytext, yylineno, NULL, NULL); }
        | NOVALINHA ';' { $$ = CriaNo(AST, NULL, yylineno, NULL, NULL); }
        | SE '(' Expr ')' ENTAO ListaComando FIMSE { $$ = CriaNo(AST, NULL, yylineno, $3, $6); }
        | SE '(' Expr ')' ENTAO ListaComando SENAO ListaComando FIMSE { $$ = CriaNo(AST, NULL, yylineno, $3, CriaNo(AST, NULL, yylineno, $6, $8)); }
        | ENQUANTO '(' Expr ')' Comando  { $$ = CriaNo(AST, NULL, yylineno, $3, $5); }
        | Bloco { $$ = $1; }
;

Expr:   OrExpr { $$ = $1; }
        | IDENTIFICADOR '=' Expr { $$ = CriaNo(AST, NULL, yylineno,  $1, $3); }
;

OrExpr: OrExpr OU AndExpr { $$ = CriaNo(AST, NULL, yylineno,  $1, $3); }
        | AndExpr { $$ = $1; }
;

AndExpr: AndExpr E EqExpr { $$ = CriaNo(AST, NULL, yylineno,  $1, $3); }
       | EqExpr { $$ = $1; }
;

EqExpr: EqExpr IGUAL DesigExpr { $$ = CriaNo(AST, NULL, yylineno,  $1, $3); }
        | EqExpr DIFERENTE DesigExpr { $$ = CriaNo(AST, NULL, yylineno,  $1, $3); }
        | DesigExpr { $$ = $1; }
;

DesigExpr: DesigExpr '<' AddExpr { $$ = CriaNo(AST, NULL, yylineno,  $1, $3); }
        | DesigExpr '>' AddExpr { $$ = CriaNo(AST, NULL, yylineno,  $1, $3); }
        | DesigExpr MAIORIGUAL AddExpr { $$ = CriaNo(AST, NULL, yylineno,  $1, $3); }
        | DesigExpr MENORIGUAL AddExpr { $$ = CriaNo(AST, NULL, yylineno,  $1, $3); }
        | AddExpr { $$ = $1; }
;

AddExpr: AddExpr '+' MulExpr { $$ = CriaNo(AST, NULL, yylineno,  $1, $3); }
        | AddExpr '-' MulExpr { $$ = CriaNo(AST, NULL, yylineno,  $1, $3); }
        | MulExpr { $$ = $1; }
;

MulExpr: MulExpr '*' UnExpr { $$ = CriaNo(AST, NULL, yylineno,  $1, $3); }
        | MulExpr '/' UnExpr { $$ = CriaNo(AST, NULL, yylineno,  $1, $3); }
        | UnExpr { $$ = $1; }
;

UnExpr: '-' PrimExpr { $$ = CriaNo(AST, NULL, yylineno,  $2, NULL); }
        | '!' PrimExpr { $$ = CriaNo(AST, NULL, yylineno,  $2, NULL); }
        | PrimExpr { $$ = $1; }
;

PrimExpr: IDENTIFICADOR {$$ = CriaNo(AST, yytext, yylineno, NULL, NULL);}
        | CARCONST { $$ = CriaNo(AST, yytext, yylineno, NULL, NULL); }
        | INTCONST { $$ = CriaNo(AST, yytext, yylineno, NULL, NULL); }
        | '(' Expr ')' { $$ = $2; }
;

%% /* Epilogo */	

int main(int argc, char** argv){

        if(argc != 2) {
                // ERRO: [MENSAGEM] [LINHA]
                fprintf(stderr, "ERRO: Uso correto: ./g-v1 arquivo.g %d\n", 0); 
                exit(1);
        } 

        yyin=fopen(argv[1], "r");
        
        if(!yyin)
        {
                // ERRO: [MENSAGEM] [LINHA]
                fprintf(stderr, "ERRO: arquivo não pode ser aberto %d\n", 0);
                exit(1);
        }

        yyparse();  

        imprimirArvore(raiz); // Imprime a árvore sintática para verificação  

        fclose(yyin); 
        
        return 0;
}

void yyerror( char const *s) {
        // ERRO: [MENSAGEM] [LINHA]
        fprintf(stderr, "ERRO: %s %d\n", s, yylineno);
        exit(1);
}



