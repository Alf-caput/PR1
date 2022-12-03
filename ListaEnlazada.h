#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
	double longitud;
	double latitud;
}ElementoLista;

typedef struct _Nodo
{
	ElementoLista dato;
	struct _Nodo* sig;
}_Nodo;

typedef _Nodo* Nodo;

typedef struct
{
	Nodo cabeza;
}_Lista;

typedef _Lista* Lista;

Nodo _crearNodo(ElementoLista dato);
Lista crearLista();
void mostrarLista(Lista lista);
void insertarAlFinal(ElementoLista dato, Lista lista);
void insertarEnPos(ElementoLista dato, int pos, Lista lista);
bool estaEnLista(ElementoLista dato, Lista lista);
void borrarElemento(ElementoLista dato, Lista lista);
void eliminarLista(Lista lista);

Nodo _crearNodo(ElementoLista dato)/*Crea un nodo*/
{
	Nodo nuevoNodo = (Nodo) malloc(sizeof(_Nodo));
	if (!nuevoNodo)
	{
    	return NULL;
  	}
	nuevoNodo -> dato = dato;
	nuevoNodo -> sig = NULL;
	return nuevoNodo;
}

Lista crearLista()/*Crea una lista vacia*/
{
	Lista lista = (Lista) malloc(sizeof(_Lista));
	if (!lista) 
	{
    	return NULL;
  	}
	lista -> cabeza = NULL;
	return lista;
}

void mostrarLista(Lista lista)/*Muestra la lista*/
{
	int i;
	Nodo actual;
	if(lista -> cabeza == NULL)
	{
		printf("No habia elementos en la lista.\n");
	}
	else
	{
		for(
			actual = lista -> cabeza, i = 0;
			actual != NULL;
			actual = actual -> sig, i++
			)
		{
			printf("geo[%d]: longitud=%lf, latitud=%lf -> \n", i, actual->dato.longitud, actual->dato.latitud);
		}
		printf("NULL\n");
	}
	return;
}

void insertarAlFinal(ElementoLista dato, Lista lista)/*Inserta un elemento al final de la lista*/
{
	Nodo actual = lista -> cabeza;
	if(actual == NULL)
	{
		lista -> cabeza = _crearNodo(dato);
	}
	else 
	{
    	while (actual -> sig != NULL)
		{
      		actual = actual -> sig;
    	}
		actual -> sig = _crearNodo(dato);
	}
	return;
}

void insertarEnPos(ElementoLista dato, int pos, Lista lista)/*Inserta un elemento en la posicion introducida por el ususario*/
{
	int i = 0;
	Nodo actual = lista -> cabeza;
	Nodo aux;
	if (pos == 0)
	{
		actual = _crearNodo(dato);
		actual -> sig = lista -> cabeza;
		lista -> cabeza = actual;
	}
	else
	{
		while (actual -> sig != NULL && i < pos-1)
		{
			i++;
			actual = actual -> sig;
		}
		aux = actual -> sig;
		actual -> sig = _crearNodo(dato);
		actual -> sig -> sig = aux;
	}
	return;
}

void borrarElemento(ElementoLista dato, Lista lista)/*Borra un elemento de la lista*/
{
	Nodo actual;
	Nodo aux;
	if (esListaVacia(lista))
	{
		printf("No habia elementos en la lista.\n");
	}
	else
	{
		for (
			actual = lista -> cabeza;
			actual != NULL;
			aux = actual, actual = actual -> sig)
		{
			if (actual -> dato.longitud == dato.longitud && 
				actual -> dato.latitud == dato.latitud)
			{
				if (actual == lista -> cabeza)
				{
					lista -> cabeza = lista -> cabeza -> sig;
				}
				else
				{
					aux -> sig = actual -> sig;
					
				}
				free(actual);
				actual = aux;
			}
		}
	}
	return;
}  

bool estaEnLista(ElementoLista dato, Lista lista)/*Devuelve true si el elemento estaba en la lista sino devuelve false*/
{
	Nodo aux = lista -> cabeza;
	while (aux != NULL)
	{
		if (aux -> dato.longitud == dato.longitud && 
			aux -> dato.latitud == dato.latitud)
		{
			return true;
		}
		aux = aux -> sig;
	}
	return false;
}

void eliminarLista(Lista lista)/*Elimina la lista de memoria*/
{
	Nodo aux;
	while (lista -> cabeza != NULL)
	{
		aux = lista -> cabeza;
		lista -> cabeza = lista -> cabeza -> sig;
		free(aux);
		aux = NULL;
	}
}  