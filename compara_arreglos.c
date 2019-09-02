#include <stdio.h>


#define VACIO NULL
#define NVACIO 0

/* Compara dos arreglos de longitud especificada.
 *
 * Devuelve -1 si el primer arreglo es menor que el segundo; 0 si son
 * iguales; o 1 si el primero es el mayor.
 *
 * Un arreglo es menor a otro cuando al compararlos elemento a elemento,
 * el primer elemento en el que difieren no existe o es menor.
 */
int comparar(int vector1[], int n1, int vector2[], int n2);


int main(void){

    int a[] = { 1, 2, -3, -4 };
    int b[] = { 1, 2, -3 };
    //int c[] = { 1, 2, -5 };
    int len_a = 4;
    int len_b = 3;
    //int len_c = 3;

    //int vector1[];
    //int vector2[] = {1};

    int mayor = comparar(a, len_a, b, len_b);

    if (mayor == 0){
        printf("Son iguales. \n");
    }

    if (mayor == 1){
        printf("El primero es mayor. \n");
    }

    if (mayor == -1){
        printf("El primero es menor. \n");
    }


    return 0;
}


int comparar(int vector1[], int n1, int vector2[], int n2) {

    if (n1 == 0){
        if (n2 == 0){
            return 0;
        } else{
            return -1;
        }
    }

    if (n2 == 0){
        return 1;
    }


    int limite, limite_menor;

    if (n1 > n2){
        limite = n1;
        limite_menor = n2;
    }else{
        limite = n2;
        limite_menor = n1;
    }

    printf("limite menor %d, limite %d \n", limite_menor, limite);

    for (int i = 0; i < limite; i++) {
        printf("compara %d y %d \n", vector1[i], vector2[i]);

        if (i < limite_menor){

            if (vector1[i] > vector2[i]){
                return 1;
            }

            if (vector1[i] < vector2[i]){
                return -1;
            }

            continue;
        } else{
            printf("entro al else del limite menor \n");
            if (n1 == limite){
                return 1;
            }

            if (n2 == limite){
                return -1;
            }
        }


    }

    return 0;
}
