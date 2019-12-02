#include <stdio.h>
#include <stdlib.h>

#define MAX 100




int main(void){
    
    //Declaracioness
    char * tipos_datos[][3]={"entero","decimal","cadena"};
    char palabras_reservadas[][11]={"definir","hasta que","mientras","repetir","si","hacer","finsi","sino","leer","imprimir","cursor"};
    int estado=0; //ESTADO INICIAL
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
    
    
    //FILTRAR letra(Mayuscula o Minuscula) o numero 
        if(caracter >= 'a' && caracter <= 'z'){
            caracter='m';
            /*if (atoi(cadena) == atoi(palabras_reservadas[0]))
                {
                    printf("Se reconocio definir %s \n",palabras_reservadas[0]);
                }*/
        }else if(caracter >= 'A' && caracter <= 'Z'){
            caracter='M';
        }else if(caracter >= '0' && caracter <='9' ){
            caracter='n';
        }


    ///Estados o Patrones


    ///Casos
        switch (caracter){
        case 'n':
           if (estado==1 || estado==2)
           {
               estado=3;  //Estado de Numero entrante
           }else if (estado==0)
           {
             //  printf("No se permiten numeros al inicio del programa \n");
           }
           
           
            break;
        case 'm'://Minusculas
            if(estado==0||estado==2) 
            {
               estado=1;  
            }
            break;
        case 'M'://Mayusculas
            if(estado==0||estado==1) 
            {
               estado=2;  
            }
            break;
        case ' '://Espacio En Blanco
            estado=0;
            break;
        case '.':
            if (estado==3 ||estado==1)
            {
               estado=4;  //estado Punto Decimal
            }else if (estado==0)
            {
               // printf("No se permiten puntos al inicio del programa \n");
            }
            
            
            break;
        
        default:
            break;
        }

        //FIN DEL SWITCH
        //DECISIONES
        if (estado==3){
            res=" Tkn_numero\n";
        }
        if (estado==40){
            res=" Tkn_bloque_inicio\n";
        }
        if (estado==1){
            res=" Tkn_letra_minuscula\n";
        }
        if (estado==2)
        {
            res=" Tkn_letra_mayuscula\n";
        }
        
        printf("%s",res);
    }
    fclose(ptfile);
    return 0;
}