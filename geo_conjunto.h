#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct _geo_localizacion
{
    double longitud;
    double latitud;
}geo_localizacion_t;

typedef struct Conjunto
{
    geo_localizacion_t contenido[N];
    int ultimo; /*Indice del ultimo elemento*/
}tConjunto;

typedef enum boolean {FALSE = 0, TRUE = 1} tBool; /*Simula booleanos*/

tConjunto cjtoVacio();
tConjunto unit(geo_localizacion_t elemento);
tBool esConjuntoVacio(tConjunto conjunto);
tBool esta(geo_localizacion_t elemento, tConjunto conjunto);
void aniadir(geo_localizacion_t elemento, tConjunto *conjunto);
int cardinal(tConjunto conjunto);
void quitar(geo_localizacion_t elemento, tConjunto *conjunto);
void mostrar_conjunto(tConjunto conjunto);
tConjunto unir_conjuntos(tConjunto conjunto1, tConjunto conjunto2);

tConjunto cjtoVacio()   /*Devuelve un conjunto vacio*/
{
    tConjunto conjunto;
    conjunto.ultimo = -1;    /*Conjunto vacio si ultimo elemento esta en posicion -1.*/
    return conjunto;
}

tConjunto unit(geo_localizacion_t elemento) {
    tConjunto conjunto;
    conjunto.ultimo = 0;    // El primer elemento del array en posicion 0. En diapositivas array con indices 1 a N
    conjunto.contenido[conjunto.ultimo] = elemento; // Se pone el elemento en la primera posicion del array
    return conjunto;
}

tBool esConjuntoVacio(tConjunto conjunto) {
    return conjunto.ultimo==-1;     // Si el ultimo elemento esta en posicion -1 es que el conjunto esta vacio. Ver cjtoVacio()
}

tBool esta(geo_localizacion_t elemento, tConjunto conjunto){
    tBool encontrado = FALSE;
    int i = 0;
    while(!encontrado && i<=conjunto.ultimo) {
        encontrado = (
            conjunto.contenido[i].longitud == elemento.longitud &&
            conjunto.contenido[i].latitud == elemento.latitud);
        i++;    // Se incrementa indice para seguir iterando...
    }
    return encontrado;
}

void aniadir(geo_localizacion_t elemento, tConjunto *conjunto){
    if (!esta(elemento, *conjunto)) {
        // Elemento no esta dentro
        if (conjunto->ultimo < (N-1) )  { // Con 'conjunto->ultimo < N' desbordabamos la capacidad
            // Cabe en el conjuntos
            conjunto->ultimo++;
            conjunto->contenido[conjunto->ultimo] = elemento;
        }
        else { // No cabe en el conjunto
            printf("ERROR - aniadir: No cabe la geolocalizacion (longitud=%lf, latitud=%lf).\n", elemento.longitud, elemento.latitud);
        }
    }
    else { // elemento ya estaba dentro
        printf("ERROR - aniadir: No se puede aniadir la geolocalizacion (longitud=%lf, latitud=%lf), ya estaba dentro.\n", elemento.longitud, elemento.latitud);
    }
}

int cardinal(tConjunto conjunto){  /*Devuelve el numero de elementos del conjunto*/
    return conjunto.ultimo+1;
}

void quitar(geo_localizacion_t elemento, tConjunto *conjunto){
    int i = 0;
    // Bucle que simplemente itera hasta encontar elemento en conjunto.
    //   Si lo encuentra, i almacenara su posicion.
    //   Si no lo encuentra, i será mayor que ultimo por la ultima iteracion.
    while(
        i<=conjunto->ultimo &&
        conjunto->contenido[i].longitud!=elemento.longitud &&
        conjunto->contenido[i].latitud!=elemento.latitud) {
        i++;    // Se incrementa indice para seguir iterando...
    }

    if (i <= conjunto->ultimo) {
        conjunto->contenido[i].longitud = conjunto->contenido[conjunto->ultimo].longitud;
        conjunto->contenido[i].latitud = conjunto->contenido[conjunto->ultimo].latitud;

        conjunto->ultimo--;
    }
    else { // elemento no estaba dentro del conjunto
        printf("INFO - quitar: No se puede quitar, NO estaba dentro.\n");
    }
}

void mostrar_conjunto(tConjunto conjunto)
{
    int i;
    geo_localizacion_t elemento;
    if (esConjuntoVacio(conjunto))
    {
        printf("No hay elementos en el conjunto\n");
    }
    else
    {
        for (i = 0; i <= conjunto.ultimo; i++)
        {
            printf("geo[%d]: longitud=%lf, latitud=%lf\n", i, conjunto.contenido[i].longitud, conjunto.contenido[i].latitud);
        }
    }
    return;
}

tConjunto unir_conjuntos(tConjunto conjunto1, tConjunto conjunto2)
{
    tConjunto union_conjuntos = conjunto1;
    int i;
    for (i = 0; i < cardinal(conjunto2); i++)
    {
        aniadir(conjunto2.contenido[i], &union_conjuntos);
    }
    return union_conjuntos;
}