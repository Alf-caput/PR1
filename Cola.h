#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*Definicion del tipo de elementos de la cola*/
typedef struct
{
    double longitud;
    double latitud;
}ElementoCola;

#define ELEMENTO_NULO {.longitud = 0, .latitud = 0}

/*Definicion del tipo Cola*/
typedef struct
{
    int ultimo;
    int capacidad;
    ElementoCola *datos;
}_Cola;

typedef _Cola* Cola;/*Ocultamos al usuario el uso de punteros definiendo el tipo Cola como un puntero a la estructura _Cola*/

Cola crearCola(int capacidad);
void mostrarCola(Cola cola);
bool esColaVacia(Cola cola);
bool esColaLlena(Cola cola);
bool encolar(ElementoCola dato, Cola cola);
ElementoCola desencolar(Cola cola);
void vaciarCola(Cola cola);
void eliminarCola(Cola cola);

Cola crearCola(int capacidad)/*Crea una cola*/
{
    Cola cola = (Cola) malloc(sizeof (_Cola));
    cola -> ultimo = -1;
    cola -> capacidad = capacidad;
    cola -> datos = (ElementoCola*) malloc(sizeof(ElementoCola) * capacidad);
    //printf("Cola creada con exito.\n");
    return cola;
}

void mostrarCola(Cola cola)/*Muestra la cola*/
{
    int i;
    if (esColaVacia(cola))
    {
        printf("No hay elementos en cola.\n");
    }
    else
    {
        for (i = 0; i < cola -> ultimo + 1; i++)
        {
            printf("geo[%d]: longitud=%lf, latitud=%lf\n", i, cola->datos[i].longitud, cola->datos[i].latitud);
        }
    }
    return;
}

bool esColaVacia(Cola cola)/*Comprueba si la cola esta vacia*/
{
    if (cola -> ultimo == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool esColaLlena(Cola cola)/*Comprueba si la pila esta llena*/
{
    if (cola -> ultimo == cola -> capacidad - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool encolar(ElementoCola dato, Cola cola)/*Apila un elemento y devuelve 1 si fue posible y 0 si no fue posible*/
{
    if (!esColaLlena(cola))
    {
        cola -> ultimo++;
        cola -> datos[cola -> ultimo] = dato;
        return true;
    }
    else
    {
        printf("No se pudo encolar el elemento, la cola estaba llena.\n");
        return false;
    }
}

ElementoCola desencolar(Cola cola)/*Saca al primer elemento que entro y lo devuelve*/
{
    int i;
    ElementoCola dato = ELEMENTO_NULO;
    if (esColaVacia(cola))
    {
        printf("No habia elementos en la cola, devolviendo elemento nulo . . .\n");
    }
    else
    {
        dato = cola -> datos[0];
        for (i = 0; i < cola -> ultimo; i++)
        {
            cola -> datos[i] = cola -> datos[i+1];
        }
        cola -> ultimo--;
    }
    return dato;
}

void vaciarCola(Cola cola)
{
    int i;
    if (!esColaVacia(cola))
    {
        for (i = 0; i <= cola -> ultimo; i++)
        {
            desencolar(cola);
        }
        printf("Cola vaciada con exito.\n");
    }
    else
    {
        printf("La cola ya estaba vacia.");
    }
    return;
}

void eliminarCola(Cola cola)/*Elimina la cola y libera la memoria*/
{
    free(cola->datos);
    cola -> datos = NULL;
    free(cola);
    cola = NULL;
    //printf("Cola eliminada de memoria.\n");
    return;
}