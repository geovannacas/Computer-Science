%{
/*********** Este arquivo Define a implementação do esquema de traducaoo da figura 2.39, 
************ secao 2.8.2 doDragon book. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sint.h"

extern int yylex();
extern int yylineno; 
extern char* yytext;
extern FILE* yyin;

void yyerror(char const *s);

%}

%token PRINCIPAL IDENTIFICADOR INT CAR
%token LEIA ESCREVA NOVALINHA
%token SE ENTAO SENAO FIMSE ENQUANTO
%token CADEIACARACTERES OU E IGUAL DIFERENTE
%token MAIORIGUAL MENORIGUAL CARCONST INTCONST

%%  

/* Secao de regras - Gramatica  */

Programa : PRINCIPAL Bloco 
;           

Bloco	: '{' ListaComando '}' | VarSection'{' ListaComando '}' 
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

ListaComando: Comando
            | Comando ListaComando
;

Comando: ';'
        | Expr ';'
        | LEIA IDENTIFICADOR ';'
        | ESCREVA Expr ';'
        | ESCREVA CADEIACARACTERES ';'
        | NOVALINHA ';'
        | SE '(' Expr ')' ENTAO ListaComando FIMSE
        | SE '(' Expr ')' ENTAO ListaComando SENAO ListaComando FIMSE
        | ENQUANTO '(' Expr ')' Comando 
        | Bloco
;

Expr:   OrExpr
        | IDENTIFICADOR '=' Expr
;

OrExpr: OrExpr OU AndExpr
        | AndExpr
;

AndExpr: AndExpr E EqExpr
       | EqExpr
;

EqExpr: EqExpr IGUAL DesigExpr
        | EqExpr DIFERENTE DesigExpr
        | DesigExpr
;

DesigExpr: DesigExpr '<' AddExpr
        | DesigExpr '>' AddExpr
        | DesigExpr MAIORIGUAL AddExpr
        | DesigExpr MENORIGUAL AddExpr
        | AddExpr
;

AddExpr: AddExpr '+' MulExpr
        | AddExpr '-' MulExpr
        | MulExpr
;

MulExpr: MulExpr '*' UnExpr
        | MulExpr '/' UnExpr
        | UnExpr
;

UnExpr: '-' PrimExpr
        | '!' PrimExpr
        | PrimExpr
;

PrimExpr: IDENTIFICADOR
        | CARCONST
        | INTCONST
        | '(' Expr ')'
;

%% /* Secao Epilogo*/	

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

        fclose(yyin); 
        
        return 0;
}

void yyerror( char const *s) {
        // ERRO: [MENSAGEM] [LINHA]
        fprintf(stderr, "ERRO: %s %d\n", s, yylineno);
        exit(1);
}



