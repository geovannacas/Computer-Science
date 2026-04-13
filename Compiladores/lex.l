%{ /*DEFINICOES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sint.h"

/*MENSAGEM DE ERRO*/
void erro_lexico(const char* msg, int linha) {
    printf("ERRO: %s %d\n", msg, linha);
    exit(1);
}
%}

%option yylineno
%option noyywrap

DIGITO [0-9]
LETRA  [a-zA-Z]
ID     ({LETRA}|_)({LETRA}|{DIGITO}|_)*
ESPACO [ \t\r]+

%x COMENTARIO
%x CADEIA

/*REGRAS*/
%%

{ESPACO}        { }
"\n"            { }

"principal"     { return PRINCIPAL; }
"int"           { return INT; }
"car"           { return CAR; }
"leia"          { return LEIA; }
"escreva"       { return ESCREVA; }
"novalinha"     { return NOVALINHA; }
"se"            { return SE; }
"entao"         { return ENTAO; }
"senao"         { return SENAO; }
"fimse"         { return FIMSE; }
"enquanto"      { return ENQUANTO; }

"||"            { return OU; }
"&&"            { return E; }
"=="            { return IGUAL; }
"!="            { return DIFERENTE; }
">="            { return MAIORIGUAL; }
"<="            { return MENORIGUAL; }

"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"="             { return '='; }
"<"             { return '<'; }
">"             { return '>'; }
"!"             { return '!'; }
"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }
";"             { return ';'; }
","             { return ','; }
":"             { return ':'; }

{ID}            { yylval.id = strdup(yytext); return IDENTIFICADOR;}
[+-]?{DIGITO}+  { yylval.id = strdup(yytext); return INTCONST; }

"'"({LETRA}|{DIGITO}|"\\n"|"\\t"|.)"'" { yylval.id = strdup(yytext); return CARCONST; }

"\""            { BEGIN(CADEIA); }
<CADEIA>[^\"\n]* { yylval.id = strdup(yytext); }
<CADEIA>\"      { BEGIN(INITIAL); return CADEIACARACTERES; }
<CADEIA>\n      { erro_lexico("CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA", yylineno - 1); }
<CADEIA><<EOF>> { erro_lexico("CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA", yylineno); }

"/*"            { BEGIN(COMENTARIO); }
<COMENTARIO>[^*\n]* { }
<COMENTARIO>"*"+[^*/\n]* { }
<COMENTARIO>\n  { }
<COMENTARIO>"*"+"/" { BEGIN(INITIAL); }
<COMENTARIO><<EOF>> { erro_lexico("COMENTÁRIO NAO TERMINA", yylineno); }

.               { erro_lexico("CARACTERE INVÁLIDO", yylineno); }

<<EOF>>         { return -1; }

%%