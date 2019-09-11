#include "vector.h"


vector_t* vector_crear(size_t tam){
    vector_t* vector = malloc(sizeof(vector_t));

    if (vector == NULL){
        return NULL;
    }

    vector->datos = malloc(tam * sizeof(int));

    if (tam > 0 && vector->datos == NULL){
        free(vector);
        return NULL;
    }

    vector->tam = tam;
    return vector;
}


void vector_destruir(vector_t* vector){
    if (vector != NULL){
        free(vector->datos);
        free(vector);
    }
}


bool vector_redimensionar(vector_t* vector, size_t nuevo_tam){

    if (vector == NULL || nuevo_tam == vector->tam){ // si tiene el mismo tamaño, me voy
        return false;
    }

    int* ptr_temp = realloc(vector->datos, nuevo_tam * sizeof(int));

    if (nuevo_tam > 0 && ptr_temp == NULL){ //uno puede querer que sea 0
        return false;
    }

    vector->datos = ptr_temp;
    vector->tam = nuevo_tam;
    return true;
}


bool vector_obtener(vector_t* vector, size_t pos, int* valor){

    // para verificar la pre condicion
    if (vector == NULL || vector->tam == 0){
        return false;
    }

    // pos >= 0
    if (pos <= (vector->tam - 1)){
        *valor = vector->datos[pos];
        return true;
    }
    return false;
}

size_t vector_largo(vector_t* vector){
    size_t largo = vector->tam;
    return largo;
}

bool vector_guardar(vector_t* vector, size_t pos, int valor){
    if (vector == NULL || vector->tam == 0){
        return false;
    }
    //pos >= 0 no es estrictamente necesario, el compilador lo corrige
    if (pos <= vector->tam - 1){
        vector->datos[pos] = valor;
        return true;
    }
    return false;
}
