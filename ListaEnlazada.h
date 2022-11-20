#include <stdlib.h>
#include <stdio.h>

typedef struct nodo
{
    int dato;
    struct nodo *sig;
}nodo;

nodo *CrearNodo(int dato);
int InsertarInicio(nodo **cabeza, int dato);
int InsertarFinal(nodo **cabeza, int dato);
void ImprimirLista(nodo *cabeza);
int estaVacia(nodo *cabeza);
int Busqueda(nodo *cabeza, int dato);
void Borrar(struct nodo **cabeza, int dato);

struct nodo *CrearNodo(int dato)
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

int InsertarInicio(nodo **cabeza, int dato)
{
    nodo *nuevo = NULL;
    nuevo = CrearNodo(dato);
    if (nuevo != NULL)
    {
        nuevo -> sig = *cabeza;
        *cabeza = nuevo;
        return 1;
    }
    return 0;
}

void ImprimirLista(nodo *cabeza)
{
    nodo *nAux = cabeza;
    while (nAux != NULL)
    {
        printf("%d ", nAux -> dato);
        nAux = nAux -> sig;
    }
    return;
}

int InsertarFinal(nodo **cabeza, int dato)
{
    nodo *nuevo = NULL, *nAux = *cabeza;
    nuevo = CrearNodo(dato);
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

int Busqueda(nodo *cabeza, int dato)
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
void Borrar (struct nodo**cabeza, int dato)
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
