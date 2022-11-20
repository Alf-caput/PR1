#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

struct nodo
{
    int data;
    struct nodo* sig;
}nodo;

struct cola
{
    struct nodo *primero, *ultimo;
}cola;

struct nodo* crearNodo(int data)
{
    struct nodo* nuevo = (struct nodo*) malloc(sizeof(struct nodo));
    nuevo -> data = data;
    nuevo -> sig = NULL;
    return nuevo;
}

struct cola* crearCola()
{
    struct cola* c = (struct cola*) malloc(sizeof(struct cola));
    c -> primero = c -> ultimo = NULL;
    return c;
}

void encolar(int data, struct cola** c)
{
    struct nodo* nuevo = crearNodo(data);
    // Si la cola esta vacia = NULL
    if ((*c) -> primero == NULL)
    {
        (*c) -> primero = (*c) -> ultimo = nuevo; // Sera el primero y el ultimo
        return;
    } 
    // Si la cola NO esta vacia
    (*c) -> ultimo -> sig = nuevo;
    (*c) -> ultimo = nuevo;
    return;
}

int desencolar (struct cola** c)
{
    // Si no hay ningun elemento en la cola
    if ((*c) -> primero==NULL) return INT_MIN;
    // Si la cola esta vacia
    struct nodo* eliminado = (*c)->primero;
    int data = eliminado -> data;
    // Eliminamos elemento (Nodo) cola
    (*c)->primero = eliminado->sig;
    // Si la cola tiene 1 elemento
    if ((*c) -> primero == NULL)
    {
        (*c) -> ultimo == NULL;
    }
    free(eliminado); // Liberamos el nodo
    return data;
}

void mostrar (struct cola** c)
{
    if ((*c) -> primero == NULL) return; // Si no hay elementos no hago nada
    printf("Primero: %d\nUltimo: %d\n", (*c)->primero->data, (*c)->ultimo->data); // Imprimo elementos
    struct nodo* actual = (*c) -> primero; // Guardo en variable actual
    while (actual)
    {
        printf("%d ", actual->data);
        actual = actual -> sig;
    }
    printf("\n----------------------\n");
    return;
}
