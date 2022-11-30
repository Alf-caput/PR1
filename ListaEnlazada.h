#include <stdlib.h>
#include <stdio.h>

typedef struct nodo Nodo;

typedef struct lista Lista;

typedef struct
{
	double longitud;
	double latitud;
}ElementoLista;

struct nodo
{
	ElementoLista elemento;
	struct nodo* sig;
};

struct lista
{
	Nodo* cabeza;
};
/*Ruben haz que las funciones devuelvan Nodo pero que no se sepan que es un puntero*/
Nodo *crearNodo(ElementoLista elemento)
{
	Nodo* nuevoNodo = malloc(sizeof(Nodo));
	if (!nuevoNodo) 
	{
    	return NULL;
  	}
	nuevoNodo -> elemento = elemento;
	nuevoNodo -> sig = NULL;
	return nuevoNodo;
}

Lista* hacerLista()
{
	Lista* lista = malloc(sizeof(Lista));
	if (!lista) 
	{
    	return NULL;
  	}
	lista->cabeza = NULL;
	return lista;
}

void mostrarLista(Lista* lista)
{
	Nodo* actual = lista->cabeza;
	if(lista->cabeza == NULL) 
    	return;
	for(; actual != NULL; actual = actual->sig) 
	{
		printf("%d\n", actual->elemento);
	}
}

void insertarElemento(ElementoLista elemento, Lista* lista)
{
	Nodo* actual = NULL;
	if(lista -> cabeza == NULL)
	{
		lista -> cabeza = crearNodo(elemento);
	}
	else 
	{
    	actual = lista -> cabeza; 
    	while (actual -> sig != NULL)
		{
      		actual = actual -> sig;
    	}
		actual -> sig = crearNodo(elemento);
	}
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
