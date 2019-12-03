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

{MAYUS}({MAYUS}|{MINUS}|{DIGITO})?+   { printf("Una Variable: %s \n", yytext); }

{SIGNO}?{DIGITO}+   { printf("Un Entero: %s (%d)\n", yytext, atoi(yytext)); }

{SIGNO}?{DIGITO}+\.{DIGITO}+   { printf("Un Decimal: %s (%g)\n", yytext, atof(yytext)); }

["]({DIGITO}|{MAYUS}|{MINUS}|[ ])+["]   { printf("Una Cadena: %s \n", yytext); }

(repetir|mientras|si|definir|leer|imprimir|cursor|hasta|finsi|sino) { printf("Una Palabra Reservada: %s\n", yytext); }

"{"   { printf("Se abre una instrucción %s \n", yytext); }

"}"   { printf("Se cierra una instrucción %s \n", yytext); }

Salir   { Salir(); }

.   {printf("Caracter o desconocido: %s\n", yytext ); }


%%

int main(int argc, char *argv[]){
	if (argc == 2){
		yyin= fopen(argv[1], "rt");
		if (yyin == NULL){
			printf("no se puede abrir el archivo %s ", argv[1]);
			exit(1);
		}
	}
	else{
	    yyin = stdin;
	}
	yylex();
	return 0;
}
void Salir(){
	printf("Saliendo...");
	exit(0);
}
