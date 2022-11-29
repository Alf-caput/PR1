#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*Definicion del tipo de elementos de la pila*/
typedef struct
{
    double longitud;
    double latitud;
}ElementoPila;

#define ELEMENTO_NULO {.longitud = 0, .latitud = 0}

/*Definicion del tipo pila*/
typedef struct
{
    int cima;
    int capacidad;
    ElementoPila *datos;
}_Pila;

typedef _Pila* Pila;/*Ocultamos al usuario el uso de punteros definiendo el tipo Pila como un puntero a la estructura _Pila*/

Pila crearPila(int capacidad);
void mostrarPila(Pila pila);
bool esPilaVacia(Pila pila);
bool esPilaLlena(Pila pila);
bool apilar(ElementoPila dato, Pila pila);
ElementoPila desapilar(Pila pila);
void vaciarPila(Pila pila);
void eliminarPila(Pila pila);


Pila crearPila(int capacidad)/*Crea una pila*/
{
    Pila pila = (Pila) malloc(sizeof(_Pila));
    pila -> cima = -1;
    pila -> capacidad = capacidad;
    pila -> datos = (ElementoPila*) malloc(sizeof(ElementoPila) * capacidad);
    //printf("Pila creada con exito.\n");
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

bool esPilaVacia(Pila pila)/*Comprueba si la pila esta vacia*/
{
    if (pila -> cima == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool esPilaLlena(Pila pila)/*Comprueba si la pila esta llena*/
{
    if (pila -> cima == pila -> capacidad - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool apilar(ElementoPila dato, Pila pila)/*Apila un elemento y devuelve 1 si fue posible y 0 si no fue posible*/
{
    if (!esPilaLlena(pila))
    {
        pila -> cima++;
        pila -> datos[pila -> cima] = dato;
        return true;
    }
    else
    {
        printf("No se pudo apilar el elemento, la pila estaba llena.\n");
        return false;
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

void vaciarPila(Pila pila)
{
    if (!esPilaVacia(pila))
    {
        while (!esPilaVacia(pila))
        {
            desapilar(pila);
        }
        printf("Pila vaciada con exito.\n");
    }
    else
    {
        printf("La pila ya estaba vacia.");
    }
    return;
}

void eliminarPila(Pila pila)/*Elimina la pila y libera la memoria*/
{
    free(pila -> datos);
    pila -> datos = NULL;
    free(pila);
    pila = NULL;
    //printf("Pila eliminada de memoria.");
    return;
}
