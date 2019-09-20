#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void imprime_cuadrados(int min, int max, int n);

int main(void){
    char min[MAX];
    char max[MAX];
    char n[MAX];


    printf("Ingrese el valor minimo:\n");
    fgets(min, MAX, stdin);

    printf("Ingrese el valor maximo:\n");
    fgets(max, MAX, stdin);

    printf("Ingrese el del salto (n):\n");
    fgets(n, MAX, stdin);

    int min_int = atoi(min);
    int max_int = atoi(max);
    int n_int = atoi(n);

    imprime_cuadrados(min_int, max_int, n_int);
    getchar();

    return 0;
}

void imprime_cuadrados(int min, int max, int n){
    int i;
    for(i = min; i <= max; i += n){
        printf("%d : %d \n", i, i * i);

    }

}

