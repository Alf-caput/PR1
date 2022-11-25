#include <stdlib.h>
#include <stdio.h>

typedef struct nodo
{
    int dato;
    struct nodo *sig;
}nodo;

nodo *crearNodo(int dato);
int insertarInicio(nodo **cabeza, int dato);
int insertarFinal(nodo **cabeza, int dato);
void imprimirLista(nodo *cabeza);
int estaVacia(nodo *cabeza);
int busqueda(nodo *cabeza, int dato);
void borrar(struct nodo **cabeza, int dato);

struct nodo *crearNodo(int dato)
{
    nodo *nuevo = NULL;
    nuevo = (nodo*)malloc(sizeof(nodo));
    if (nuevo != NULL)
    {
        nuevo -> dato = dato;
        nuevo -> sig = NULL;
    }
    return nuevo;
}

int insertarInicio(nodo **cabeza, int dato)
{
    nodo *nuevo = NULL;
    nuevo = crearNodo(dato);
    if (nuevo != NULL)
    {
        nuevo -> sig = *cabeza;
        *cabeza = nuevo;
        return 1;
    }
    return 0;
}

void imprimirLista(nodo *cabeza)
{
    nodo *nAux = cabeza;
    while (nAux != NULL)
    {
        printf("%d ", nAux -> dato);
        nAux = nAux -> sig;
    }
    return;
}

int insertarFinal(nodo **cabeza, int dato)
{
    nodo *nuevo = NULL, *nAux = *cabeza;
    nuevo = crearNodo(dato);
    if (nuevo != NULL)
    {
        while (nAux -> sig != NULL)
        {
            nAux = nAux -> sig;
        }
        nAux -> sig = nuevo;
        return 1;
    }
    return 0;
}

int estaVacia(nodo *cabeza)
{
    if (cabeza == NULL)
    return 1;
    else
    return 0;
}

int busqueda(nodo *cabeza, int dato)
{
    nodo *nAux = cabeza;
    while (nAux != NULL)
    {
        if (nAux -> dato == dato)
        return 1;

        nAux = nAux -> sig; 
    }
    return 0;
}
void borrar (struct nodo**cabeza, int dato)
{
	struct nodo *aux = *cabeza, *prev;
	if (aux != NULL && aux ->dato == dato)
	{
		*cabeza = aux -> sig;
		free(aux);
		return;
	}
	while (aux != NULL && aux->dato != dato) 
	{
		prev = aux;
		aux = aux->sig;
	}
	if (aux == NULL)
    	return;
    prev->sig = aux->sig;
    free(aux);
}
