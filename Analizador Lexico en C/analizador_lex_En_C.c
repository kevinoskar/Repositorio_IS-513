#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void){
    
    //Declaracioness
    char * tipos_datos[][3]={"entero","decimal","cadena"};
    char palabras_reservadas[][11]={"definir","hasta_que","mientras","repetir","si","hacer","finsi","sino","leer","imprimir","cursor"};
    char operador_logico[][3]={"||","&&","!"};
	char operador_relacional[][6]={"<",">","==","!=","<=",">="};

    int estado=0; //ESTADO INICIAL
    int contador=0;
    char cadena[20]="",res[20]="<Tkn_";
    
    //Respuesta a Imprimir en Array
    char imprimir[1000]="";
    
    
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
        
        if(caracter != ' '){
            cadena[contador]=caracter;
            contador++;

         //FILTRAR letra(Mayuscula o Minuscula) o numero 
            if(caracter >= 'a' && caracter <= 'z'){
                caracter='m';
                
            }else if(caracter >= 'A' && caracter <= 'Z'){
                caracter='M';
                }else if(caracter >= '0' && caracter <= '9' ){
                caracter='n';
            }   
        }else{
            printf("%s\n",cadena);
            strcpy(res,"<Tkn_");
            
            if(estado==5){
                caracter='v';
            }else{

            //Busqueda de Palabra reservada
            for(int i=0;i<=(sizeof(palabras_reservadas)/sizeof(palabras_reservadas[0]));i++){
                if (strcmp(cadena,palabras_reservadas[i])==0)
                {
                    printf("Palabra Reservada Encontrada %s \n",palabras_reservadas[i]);
                    caracter='p';
                    strcat(res,cadena);
                    strcat(res,">");
                }else{
                    for (int i=0;i<=(sizeof(operador_relacional)/sizeof(operador_logico[0]));i++)
                    {
                      if (strcmp(cadena,operador_relacional[i])==0)
                      {
                         printf("Operador Relacional Encontrada %s \n",operador_relacional[i]); 
                      }    
                    }
                }
                
            }
            memset(cadena,0,sizeof cadena);
            contador=0;
            }
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
                if(estado==0||estado==1|estado==70) 
                {
                estado=1;  
                }
                if(estado==2){
                    estado=5;
                }
                break;
            case 'M'://Mayusculas
                if(estado==0||estado==70) 
                {
                estado=2;  
                }
                break;
        
            case '.':
                if (estado==3 ||estado==1)
                {
                estado=4;  //estado Punto Decimal
                }
                break;
            case 'p':
                if(estado==1||estado==0)
                {
                    strcat(imprimir,res);
                    estado=0;
                }
                break;
            case 'v':
                if(estado==5){
                    strcat(res,"variable>");
                    strcat(imprimir,res);
                    estado=0;
                }
                break;
            case '<':
                
                break;
            default:
                break;
        }
        //FIN DEL SWITCH
        //DECISIONES
        
    }

    printf("%s",imprimir);
    fclose(ptfile);
    ptfile=NULL;


    ptfile=fopen("archivo_salida.prg","w");
    fwrite(imprimir,1,strlen(imprimir) ,ptfile);
    fclose(ptfile);
    return 0;
}
