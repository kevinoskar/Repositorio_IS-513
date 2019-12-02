#include <stdio.h>
#include <stdlib.h>

#define MAX 100




int main(void){
    
    //Declaracioness
    char * tipos_datos[][3]={"entero","decimal","cadena"};
    char palabras_reservadas[][11]={"definir","hasta que","mientras","repetir","si","hacer","finsi","sino","leer","imprimir","cursor"};
    int estado=0;
    char * res;
    char * cadena;
    printf("--------------ANALIZADOR LEXICO EN C-------------- \n");
    //Abriendo Archivo Externo
    FILE *ptfile;
    char caracter;
    ptfile=fopen("analizador_lex.prg","r");
    if(ptfile==NULL){
        fputs("error",stderr);
        exit(1);
    }
    while ((caracter=fgetc(ptfile))!=EOF){
        printf("%c",caracter);
    *cadena=caracter;
     if(caracter >= 'a' && caracter <= 'z'){
        caracter='m';
         if (atoi(cadena) == atoi(palabras_reservadas[0]))
            {
                printf("Se reconocio definir %c",cadena);
            }
       }else if(caracter >= 'A' && caracter <= 'Z'){
            caracter='M';
       }else if(caracter >= '0' && caracter <='9' ){
           caracter='n';
       }


    ///Estados o Patrones


    ///Casos
        switch (caracter){
        case 'n':
           printf("Se ha encontrado un numero\n");
           if (estado==0)
           {
               estado=38;  //Estado de Numero entrante
           }
           
            break;
        case 'm'://Minusculas
            
        case 'M'://Mayusculas
            printf(" Se ha Encontrado una letra, es Mayuscula \n");
            break;
        case '.':
            if (estado==38)
            {
               estado=39;  //estado Punto Decimal
            }
            
            break;
        case '{':
            if (estado==0||estado==50)
            {
                estado=1;
            }
            break;
        default:
            break;
        }

        if (estado==38){
         res="Tkn_numero";
        }
        if (estado==1)
        {
            res="tkn_bloque_inicio";
        }
        
    printf("%s",res);
    }
    fclose(ptfile);
    return 0;
}