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
void insertarPosicionElemento(ElementoLista dato, Lista lista,int pos);
void eliminarLista(Lista lista);
// void eliminarElemento(ElementoLista dato, Lista lista);

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
			printf("geo[%d]: longitud=%lf, latitud=%lf -> \n", i, actual->dato.longitud, actual->dato.longitud);
		}
		printf("NULL");
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
