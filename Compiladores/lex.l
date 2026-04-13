%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sint.h"

void erro_lexico(const char* msg, int linha) {
    fprintf(stdout, "ERRO: %s %d\n", msg, linha);
    exit(1);
}
%}

%option yylineno
%option noyywrap

DIGITO  [0-9]
LETRA   [a-zA-Z]
ID      ({LETRA}|_)({LETRA}|{DIGITO}|_)*
ESPACO  [ \t\r]+

%x COMENTARIO
%x CADEIA

%%

{ESPACO}    { }
\n          { }

"principal"   { return PRINCIPAL; }
"int"         { return INT; }
"car"         { return CAR; }
"leia"        { return LEIA; }
"escreva"     { return ESCREVA; }
"novalinha"   { return NOVALINHA; }
"se"          { return SE; }
"entao"       { return ENTAO; }
"senao"       { return SENAO; }
"fimse"       { return FIMSE; }
"enquanto"    { return ENQUANTO; }

"||"          { return OU; }
"&"           { return E; }
"=="          { return IGUAL; }
"!="          { return DIFERENTE; }
">="          { return MAIORIGUAL; }
"<="          { return MENORIGUAL; }

"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"="         { return '='; }
"<"         { return '<'; }
">"         { return '>'; }
"!"         { return '!'; }
"("         { return '('; }
")"         { return ')'; }
"{"         { return '{'; }
"}"         { return '}'; }
";"         { return ';'; }
","         { return ','; }
":"         { return ':'; }

{ID}            { yylval.id = strdup(yytext); return IDENTIFICADOR; }

{DIGITO}+       { yylval.id = strdup(yytext); return INTCONST; }

'(\\n|\\t|\\\\|\\\'|[^\'\n])' { yylval.id = strdup(yytext); return CARCONST; }
'[^\'\n]+'                     { erro_lexico("CARACTERE INVALIDO", yylineno); }

"\""                {
                        BEGIN(CADEIA);
                        yylval.id = strdup("");
                    }
<CADEIA>[^\"\n]+   {
                        char* tmp = malloc(strlen(yylval.id) + yyleng + 1);
                        strcpy(tmp, yylval.id);
                        strcat(tmp, yytext);
                        free(yylval.id);
                        yylval.id = tmp;
                    }
<CADEIA>"\""        { BEGIN(INITIAL); return CADEIACARACTERES; }
<CADEIA>\n          { erro_lexico("CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA", yylineno - 1); }

"/*"                { BEGIN(COMENTARIO); }
<COMENTARIO>[^*\n]* { }
<COMENTARIO>\*+[^*/\n]* { }
<COMENTARIO>\n      { }
<COMENTARIO>\*+\/   { BEGIN(INITIAL); }

.           { erro_lexico("CARACTERE INVALIDO", yylineno); }

<<EOF>>     {
                if (YY_START == CADEIA)
                    erro_lexico("CADEIA DE CARACTERES NAO TERMINA", yylineno);
                if (YY_START == COMENTARIO)
                    erro_lexico("COMENTARIO NAO TERMINA", yylineno);
                return 0;
            }

%%