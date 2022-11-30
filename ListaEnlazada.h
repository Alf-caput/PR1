#include <stdlib.h>
#include <stdio.h>

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
void borrarElemento(ElementoLista dato, Lista lista);
void eliminarLista(Lista lista);

Nodo _crearNodo(ElementoLista dato)
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

Lista crearLista()
{
	Lista lista = (Lista) malloc(sizeof(_Lista));
	if (!lista) 
	{
    	return NULL;
  	}
	lista -> cabeza = NULL;
	return lista;
}

void mostrarLista(Lista lista)
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

void insertarAlFinal(ElementoLista dato, Lista lista)
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

void borrarElemento(ElementoLista dato, Lista lista)
{
	Nodo temp;
	if (
		lista -> cabeza -> dato.longitud == dato.longitud && 
		lista -> cabeza -> dato.latitud == dato.latitud)
	{
		temp = lista -> cabeza;
		lista -> cabeza = lista -> cabeza -> sig;
		free(temp);
	}
	Nodo actual = lista -> cabeza;
	while (actual -> sig != NULL)
	{
		if (actual -> sig -> dato.longitud == dato.longitud && 
			actual -> sig -> dato.latitud == dato.latitud)
		{
			temp = actual -> sig;
			actual -> sig = actual -> sig -> sig;
			free(temp);
			temp = NULL;
		}
		else
		{
			actual = actual -> sig;
		}
	}
	return;
}  

void eliminarLista(Lista lista)
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