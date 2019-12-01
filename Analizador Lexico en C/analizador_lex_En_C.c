#include <stdio.h>
#include <stdlib.h>

#define MAX 100




int main(void){
    
    //Declaracioness
    char buf[MAX],caracter;
    char *ptr=buf;
    char palabras_reservadas[][11]={"definir","hasta que","mientras","repetir","si","hacer","finsi","sino","leer","imprimir","cursor"};
    char letras_minusculas[][25]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    int Estado=0;   //Estado Iniciak en 0
    
    
    //Estados o Patrones
    printf("--------------ANALIZADOR LEXICO EN C-------------- \n");
    gets(buf);
    if(*ptr =='\0'){
        printf("Error, no se ingreso ningun caracter",stderr);
        exit(1);
    }
    
    while (*ptr != '\0'){
        //printf("%c",*ptr);
        caracter=*ptr;
        //Case Maquina de Estados
        for (int i = 0; i < (sizeof(letras_minusculas)/sizeof(letras_minusculas[0])); i++)
        {
            if (caracter == letras_minusculas[i])
            {
                printf("Encontre la letra %s %c \n",letras_minusculas[i],caracter);
            }

        }
        


        switch (caracter){
        case '0':
           printf("Se ha encontrado un numero: %i \n",0);
            break;
        case '1':
           printf("Se ha encontrado un numero: %i \n",1);
            break;
        case '2':
           printf("Se ha encontrado un numero: %i \n",2);
            break;
        case '3':
           printf("Se ha encontrado un numero: %i \n",3);
            break;
        case '4':
           printf("Se ha encontrado un numero: %i \n",4);
            break;
        case '5':
           printf("Se ha encontrado un numero: %i \n",5);
            break;
        case '6':
           printf("Se ha encontrado un numero: %i \n",6);
            break;
        case '7':
           printf("Se ha encontrado un numero: %i \n",7);
            break;
        case '8':
           printf("Se ha encontrado un numero: %i \n",8);
            break;
        case '9':
           printf("Se ha encontrado un numero: %i \n ",9);
            break;
        










        default:
           // printf("Se ha encontrado una letra: %c \n ",caracter);
            break;
        }
        *ptr++;
    }
    
}