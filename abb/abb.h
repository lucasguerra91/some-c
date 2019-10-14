#ifndef ABB_H
#define ABB_H

#include <stdbool.h>
#include <stddef.h>


typedef struct abb abb_t;
typedef struct abb_iter abb_iter_t;


/* -----------------------------------------------------------------
             Funcion de comparación y destrucción de datos
 * -----------------------------------------------------------------*/

typedef int (*abb_comparar_clave_t) (const char *, const char *);
typedef void (*abb_destruir_dato_t) (void *);


/* -----------------------------------------------------------------
             Primitivas del ABB
 * -----------------------------------------------------------------*/

/*  Crea un árbol vacío 
*   Pre:
*   Post:
*/
abb_t* abb_crear(abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato);



/*  Guarda el par de clave-valor dentro del arbol especificado 
*   Pre:
*   Post:
*/
bool abb_guardar(abb_t *arbol, const char *clave, void *dato);


/*  Guarda el par de clave-valor dentro del arbol especificado 
*   Pre:
*   Post:
*/
void *abb_borrar(abb_t *arbol, const char *clave);


/*  Guarda el par de clave-valor dentro del arbol especificado 
*   Pre:
*   Post:
*/
void *abb_obtener(const abb_t *arbol, const char *clave);


/*  Guarda el par de clave-valor dentro del arbol especificado 
*   Pre:
*   Post:
*/
bool abb_pertenece(const abb_t *arbol, const char *clave);



/*  Guarda el par de clave-valor dentro del arbol especificado 
*   Pre:
*   Post:
*/
size_t abb_cantidad(abb_t *arbol);



/*  Guarda el par de clave-valor dentro del arbol especificado 
*   Pre:
*   Post:
*/
void abb_destruir(abb_t *arbol);


/* -----------------------------------------------------------------
             Iterador interno
 * -----------------------------------------------------------------*/

/*  Guarda el par de clave-valor dentro del arbol especificado 
*   Pre:
*   Post:
*/
void abb_in_order(abb_t *arbol, bool visitar(const char *, void *, void *), void *extra);


/* -----------------------------------------------------------------
             Iterador externo
 * -----------------------------------------------------------------*/

/*  Guarda el par de clave-valor dentro del arbol especificado 
*   Pre:
*   Post:
*/
abb_iter_t *abb_iter_in_crear(const abb_t *arbol);



/*  Guarda el par de clave-valor dentro del arbol especificado 
*   Pre:
*   Post:
*/
bool abb_iter_in_avanzar(abb_iter_t *iter);


/*  Guarda el par de clave-valor dentro del arbol especificado 
*   Pre:
*   Post:
*/
const char *abb_iter_in_ver_actual(const abb_iter_t *iter);


/*  Guarda el par de clave-valor dentro del arbol especificado 
*   Pre:
*   Post:
*/
bool abb_iter_in_al_final(const abb_iter_t *iter);


/*  Guarda el par de clave-valor dentro del arbol especificado 
*   Pre:
*   Post:
*/
void abb_iter_in_destruir(abb_iter_t* iter);



#endif // ABB_H