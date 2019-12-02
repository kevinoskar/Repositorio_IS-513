#include <stdio.h>
#include <stdlib.h>

#define MAX 100




int main(void){
    
    //Declaracioness
    char buf[MAX],caracter;
    char *ptr=buf;
    char palabras_reservadas[][11]={"definir","hasta que","mientras","repetir","si","hacer","finsi","sino","leer","imprimir","cursor"};
    int Estado=0;   //Estado Iniciak en 0
    
    //Estados o Patrones
    printf("--------------ANALIZADOR LEXICO EN C-------------- \n");
    gets(buf);
    if(*ptr =='\0'){
        printf("Error, no se ingreso ningun caracter",stderr);
        exit(1);
    }
    
    while (*ptr != '\0'){
        caracter=*ptr;
        printf("%c",caracter);
        //Comprobar Letra
       
       if(caracter >= 'a' && caracter <= 'z'){
        printf("-> Es minuscula \n");
        caracter='m';

       }else if(caracter >= 'A' && caracter <= 'Z'){
            printf("-> Es mayuscula \n");
            caracter='M';
       }else{
            printf("-> No es una letra \n ");
       }


        //Case Maquina de Estados
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
        case 'M':
                //AQUI IRIA EL ESTADO 
                //Y SUIS INSTRUCCIONES
                //RETORNAR TOKEN
            break;
        case 'm':
            break;
                
        default:
            break;
        }
        *ptr++;
    }
    
}