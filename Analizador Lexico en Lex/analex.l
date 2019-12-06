%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void Salir();
%}

DIGITO [0-9]
MAYUS [A-Z]
MINUS [a-z]
SIGNO [+-]

%%

Salir   { Salir(); }

{MAYUS}({MAYUS}|{MINUS}|{DIGITO})*   { printf("Una Variable: %s\n", yytext); }

{SIGNO}?{DIGITO}+   { printf("Un Entero: %s (%d)\n", yytext, atoi(yytext)); }

{SIGNO}?{DIGITO}+\.{DIGITO}+   { printf("Un Decimal: %s (%g)\n", yytext, atof(yytext)); }

["]({DIGITO}|{MAYUS}|{MINUS}|[ ])+["]   { printf("Una Cadena: %s\n", yytext); }

repetir		{ printf("Inicia o Finaliza Ciclo de Repeticion: %s\n", yytext); }
mientras	{ printf("Inicia Ciclo de Repeticion: %s\n", yytext); }
si		{ printf("Inicia Ciclo de Decision: %s\n", yytext); }
definir		{ printf("Se definira una variable: %s\n", yytext); }
leer		{ printf("Se leera la variable: %s\n", yytext); }
imprimir	{ printf("Se imprimira: %s\n", yytext); }
cursor		{ printf("Se define coordenadas de puntero: %s\n", yytext); }
hasta		{ printf("Finaliza Ciclo de Repeticion: %s\n", yytext); }
finsi		{ printf("Finaliza Ciclo de Decision: %s\n", yytext); }
sino 		{ printf("Define otra instruccion: %s\n", yytext); }

"{"   { printf("Se abre una instrucción %s\n", yytext); }

"}"   { printf("Se cierra una instrucción %s\n", yytext); }

"{"[^}\n]*"}"     /* se come una linea de comentarios */

.+   {printf("Comando Incorrecto: %s\n", yytext ); }


%%

int main(void){
	yyin = stdin;
	yylex();
	return 0;
}
void Salir(){
	printf("Saliendo...");
	exit(0);
}
