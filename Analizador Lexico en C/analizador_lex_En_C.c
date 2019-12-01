#include <stdio.h>


int main(void){
    int entero=0;
    double decimal=0;
    char cadena=0;
    char palabras_reservadas[][11]={"definir","hasta que","mientras","repetir","si","hacer","finsi","sino","leer","imprimir","cursor"};

    printf("--------------ANALIZADOR LEXICO EN C--------------");
    for (int i = 0; i < 11; i++){
       printf("En el arreglo tiene el valor %s \n",palabras_reservadas[i]);
    }


}

