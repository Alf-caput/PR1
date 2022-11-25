/*=============================================================================
 |   Asignatura:  Estructura de datos y lagoritmos
 |      Autores:  Alfredo Robledano Abasolo, Ruben Sierra Serrano
 |     Lenguaje:  C
 |        Clase:  2-B
 |        Fecha:  20-11-2022
 +-----------------------------------------------------------------------------
 |  Descripcion:  Lectura de fichero con geolocalizaciones y almacenamiento
 |                en lista enlazada para posteriormente realizar operaciones
 |      Entrada:  Fichero csv con latitudes y longitudes, operacion a realizar
 |       Salida:  Resultado de operar sobre la lista enlazada obtenida
 *===========================================================================*/
 
#include "ListaEnlazada.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct archivoNodo
{
	char *longitud;
	char *latitud;
	struct archivoNodo* sig;
}*cabeza;

FILE *pfich;

void insertarEntrada(char *lt, char *la);

int main()
{
	pfich = fopen("fichnum.csv", "r");
	int i;
	char longitud[MAX];
	char latitud[MAX];
	if (pfich == NULL)
	{
		printf("Error: no se puede abrir el archivo fichnum.csv");
	}
	else
	{
		do
		{
			fgets(longitud, MAX, pfich);
        	fgets(latitud, MAX, pfich);
        	i = 0;
        	while(longitud[i] != '\n')
        	{
            	i++;
        	}
        	longitud[i] = '\0';
        	i = 0;
        	while(latitud[i] != '\n')
        	{
            	i++;
        	}
        	latitud[i] = '\0';
        	insertarEntrada(longitud, latitud);
		}
		while (!feof(pfich));
	}
}

void insertarEntrada(char *lt, char *la)
{
    struct archivoNodo *aux, * iterador;
    aux = (struct archivoNodo *)malloc(sizeof(struct archivoNodo));
	aux -> longitud = (char *)malloc(strlen(lt)+1);
	strcpy(aux -> longitud, lt);
	aux -> latitud = (char *)malloc(strlen(la)+1);
	strcpy(aux -> latitud, la);
    iterador = cabeza;

    if (cabeza == NULL)
    {
        cabeza = aux;
        cabeza -> sig = NULL;
    }

    else
    {
        while(iterador->sig != NULL)
        {
            iterador = iterador -> sig;
        }
        aux -> sig = NULL;
        iterador-> sig = aux;
    }
}

