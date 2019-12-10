#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void){
    
    //Declaracioness
    char * tipos_datos[][3]={"entero","decimal","cadena"};
    char palabras_reservadas[][11]={"definir","hasta que","mientras","repetir","si","hacer","finsi","sino","leer","imprimir","cursor"};
    int estado=0; //ESTADO INICIAL
    //Respuesta
    char * res;

    char cadena;
    
    //Respuesta a Imprimir en Array
    char imprimir[100];
    
    
    printf("--------------ANALIZADOR LEXICO EN C--------------\n");
    //Abriendo Archivo Externo
    FILE *ptfile;
    char caracter;
    ptfile=fopen("archivo_entrada.prg","r");
    if(ptfile==NULL){
        fputs("error",stderr);
        exit(1);
    }
    while ((caracter=fgetc(ptfile))!=EOF){        
    //FILTRAR letra(Mayuscula o Minuscula) o numero 
        if(caracter >= 'a' && caracter <= 'z'){
            caracter='m';
            
        }else if(caracter >= 'A' && caracter <= 'Z'){
            caracter='M';
        }else if(caracter >= '0' && caracter <= '9' ){
            caracter='n';
        }

    ///Estados o Patrones

    

    ///Casos
    switch (caracter){
        case 'n':
           if (estado==1 || estado==2 ||estado==70)
           {
               estado=3;  //Estado de Numero entrante
           }else if (estado==0)
           {
              printf("No se permiten numeros al inicio del programa \n");
           }
           
           
            break;
        case 'm'://Minusculas
            if(estado==0||estado==2||estado==70) 
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
    
        case '.':
            if (estado==3 ||estado==1)
            {
               estado=4;  //estado Punto Decimal
            }
        case ' ':
            estado=70;
            break;
        default:
            break;
        }

        //FIN DEL SWITCH
        //DECISIONES
        if (estado==3){
            res="Tkn_numero\n";
        }
        if (estado==70){
            res="Tkn_espacio\n";
        }
        if (estado==1){
            res="Tkn_letra_minuscula\n";
        }
        if (estado==2)
        {
            res="Tkn_letra_mayuscula\n";
        }

        
        strcat(imprimir,res);
    }
    printf("%s",imprimir);
    fclose(ptfile);

    fopen("archivo_salida","w");
    fwrite()
    return 0;
}