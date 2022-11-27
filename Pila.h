#include <stdio.h>
#include <stdlib.h>
/*Definicion del tipo de elementos de la pila*/
typedef struct
{
    double longitud;
    double latitud;
}GeoLocalizacion;

typedef GeoLocalizacion ElementoPila;

#define MAX_ELEMENTOS 100
#define ELEMENTO_NULO {.longitud = 0, .latitud = 0}

/*Definicion del tipo pila*/
typedef struct
{
    int cima;
    ElementoPila datos[MAX_ELEMENTOS];
}_Pila;

typedef _Pila* Pila;/*Ocultamos al usuario el uso de punteros definiendo el tipo Pila como un puntero a la estructura _Pila*/
typedef enum {FALSE = 0, TRUE = 1} Bool;/*Enumeracion para simular booleanos (realizado por claridad del TAD))*/

Pila crearPila();
void mostrarPila(Pila pila);
Bool esPilaVacia(Pila pila);
Bool esPilaLlena(Pila pila);
Bool apilar(ElementoPila dato, Pila pila);
ElementoPila desapilar(Pila pila);
void eliminarPila(Pila pila);

Pila crearPila()/*Crea una pila*/
{
    Pila pila = (Pila) malloc(sizeof(_Pila));
    pila -> cima = -1;
    printf("Pila creada con exito.\n");
    return pila;
}

void mostrarPila(Pila pila)/*Muestra la pila*/
{
    int i;
    if (esPilaVacia(pila))
    {
        printf("No hay elementos apilados.\n");
    }
    else
    {
        for (i = pila -> cima; i > -1; i--)
        {
            printf("geo[%d]: longitud=%lf, latitud=%lf\n", i, pila->datos[i].longitud, pila->datos[i].latitud);
        }
    }
    return;
}

Bool esPilaVacia(Pila pila)/*Comprueba si la pila esta vacia*/
{
    if (pila -> cima == -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Bool esPilaLlena(Pila pila)/*Comprueba si la pila esta llena*/
{
    if (pila -> cima == MAX_ELEMENTOS-1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Bool apilar(ElementoPila dato, Pila pila)/*Apila un elemento y devuelve 1 si fue posible y 0 si no fue posible*/
{
    if (pila -> cima < MAX_ELEMENTOS - 1)
    {
        pila -> cima++;
        pila -> datos[pila -> cima] = dato;
        return TRUE;
    }
    else
    {
        printf("No se pudo apilar el elemento, la pila estaba llena.\n");
        return FALSE;
    }
}

ElementoPila desapilar(Pila pila)/*Desapila un elemento y lo devuelve*/
{
    ElementoPila dato = ELEMENTO_NULO;
    if (esPilaVacia(pila))
    {
        printf("No habia elementos en la pila, devolviendo elemento nulo . . .\n");
    }
    else
    {
        dato = pila -> datos[pila -> cima];
        pila -> cima--;
    }
    return dato;
}

void eliminarPila(Pila pila)/*Elimina la pila y libera la memoria*/
{
    free(pila);
    pila = NULL;
    printf("Pila eliminada de memoria.");
    return;
}
