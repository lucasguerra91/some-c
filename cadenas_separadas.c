/* 9) Escribir en C un programa que pida al usuario dos palabras. El programa debe impri-
mir ambas palabras en una l´ınea, separadas por una secuencia de puntos de forma tal que la
longitud total de la l´ınea sea de 30 caracteres. Ejemplo:
Primera palabra: Hola
Segunda palabra: Mundo
Hola.....................Mundo */


#include <stdio.h>
#include <string.h>

#define MAX 30

void imprime_palabras(char *a, char *b);
void remover_salto_linea(char *a);

int main(void){

    char palabra1[MAX];
    char palabra2[MAX];

    printf("Ingrese la primer palabra:\n");
    fgets(palabra1, MAX, stdin);

    printf("Ingrese la segunda palabra:\n");
    fgets(palabra2, MAX, stdin);

    imprime_palabras(palabra1, palabra2);
    getchar();

    return 0;
}


void imprime_palabras(char *a, char *b){

    int cont1 = strlen(a);
    int cont2 = strlen(b);
    int cont3 =  29 - (cont1 + cont2);

    remover_salto_linea(a);
    remover_salto_linea(b);

    char puntos[cont3];

    for (int i = 0; i < cont3 ; ++i) {
        puntos[i] = '.';
    }
    printf("%s", a);
    printf("%s", b);
    printf("%s%s%s", a, puntos, b);

}


void remover_salto_linea(char *a){
    int i = 0;
    while (a[i] != '\0'){
        if (a[i] == '\n'){
            a[i] = '\0';
        }
        i++;
    }
}