#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	double longitud;
	double latitud;
}ElementoLista;

typedef struct
{
	ElementoLista dato;
	_Nodo* sig;
}_Nodo;

typedef _Nodo* Nodo;

typedef struct
{
	Nodo cabeza;
}_Lista;

typedef _Lista* Lista;

Nodo crearNodo(ElementoLista dato);
Lista crearLista();
void mostrarLista(Lista lista);

Nodo crearNodo(ElementoLista dato)
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
	for(
		actual = lista -> cabeza, i = 0;
		actual != NULL;
		actual = actual -> sig, i++
		)
	{
		printf("geo[%d]: longitud=%lf, latitud=%lf\n", i, actual->dato.longitud, actual->dato.longitud);
	}
	return;
}
/*
void insertarElemento(ElementoLista dato, Lista lista)
{
	Nodo actual = lista -> cabeza;
	if(actual == NULL)
	{
		lista -> cabeza = crearNodo(elemento);
	}
	else 
	{
    	while (actual -> sig != NULL)
		{
      		actual = actual -> sig;
    	}
		actual -> sig = crearNodo(elemento);
	}
	return;
}

void eliminarElemento(ElementoLista elemento, Lista* lista)
{
	Nodo* actual = lista -> cabeza;            
	Nodo* ant = actual;           
	while(actual != NULL)
	{
		if(actual -> elemento == elemento)
		{      
			ant -> sig = actual -> sig;
      		if(actual == lista -> cabeza)
        		lista -> cabeza = actual -> sig;
      		free(actual);
      		return;
		}
    	ant = actual;             
    	actual = actual -> sig;        
  	}                                 
}                 
*/