#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int main(void){
    
    //Declaracioness
    char buf[MAX];
    char *ptr=buf;
    char palabras_reservadas[][11]={"definir","hasta que","mientras","repetir","si","hacer","finsi","sino","leer","imprimir","cursor"};


    //Estados o Patrones
    printf("--------------ANALIZADOR LEXICO EN C-------------- \n");
    gets(buf);
    if(*ptr =='\0'){
        printf("Error, no se ingreso ningun caracter",stderr);
        exit(1);
    }
    
    while (*ptr != '\0'){
        printf("%c",*ptr);


        //Case Maquina de Estados
        switch (expression)
        {
        case /* constant-expression */:
            /* code */
            break;
        
        default:
            break;
        }
        *ptr++;
    }

}