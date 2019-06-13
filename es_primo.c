#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void es_primo(int numero);

int main(void){
    char ingreso[MAX];

    printf("Control de numeros primos. \n");
    printf("Ingrese el numero que desea verificar. \n");
    fgets(ingreso, MAX, stdin);

    int numero = atoi(ingreso);
    es_primo(numero);
    getchar();
    return 0;
}

void es_primo(int numero){

    if (numero > 1){
        for(int i=2; i < numero; i++){
            if ((numero % i) == 0){
                printf("No es primo.");
                return;
            }
        }
        printf("Es primo.");
    } else {
        printf("No es primo.");
    }
}
