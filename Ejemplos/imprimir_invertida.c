#include <stdio.h>

#define MAX 30

void invertir(char *cadena);

int main(){

    char s[MAX];

    printf("Ingrese una cadena\n");
    fgets(s, MAX, stdin);

    invertir(s);
    getchar();
    return 0;
}


void invertir(char *cadena){

    int fin, cont = 0;


    while (cadena[cont] != '\0') {
        cont++;
    }

    fin = cont - 1;

    for(int i = fin; i >= 0 ; i--){
        printf("%c", cadena[i]);
    }
}
