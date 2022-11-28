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

void leerGeolocalizacion(Lista *lista);

int main()
{
	Lista lista;
	int line_count;
	ElementoLista aux;
	int opc;
	float longitud, latitud;
	FILE *pfich;
	pfich = fopen("fichnum.csv", "r");
	int i;
	if (pfich == NULL)
	{
		printf("Error: no se puede abrir el archivo fichnum.csv");
	}
	else
	{
		printf("Leyendo el fichero...\n");
		for(
			line_count = 0; 
			fscanf(pfich,"%lf;%lf",&aux.longitud, &aux.latitud) == 2;
			line_count++)
		{
			insertarInicio(aux,lista);
		}
	}
	do{
		printf("==========================================================================\
	    \n                                     MENU\
	    \n==========================================================================");
	    printf("\n  1.  Introducir geolocalizacion.\
	    \n  2.  Eliminar geolocalizacion.\
	    \n  3.  Mostrar lista.\
	    \n  4.  Salir del programa.\n");
	    printf("----------------------------------------------------------------------------------------------\n");
	    printf("Introduzca opcion (1-4): ");
	    scanf("%d", &opc);
	    printf("----------------------------------------------------------------------------------------------\n");
		switch(opc)
		{
			case 1:
				printf("Introduzca la longitud y la latitud de la coordenada: ");
				scanf("%f , %f \n",&longitud,&latitud);
				//leerGeolocalizacion(longitud,latitud);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				printf("Saliendo del programa...\n");
				break;
			default:
				printf("Opcion no reconocida, repita la operacion.\n");
		}        
		printf("\n\nPulse enter para continuar . . .");
		fflush(stdin);
		getchar();
	    system("cls");
    }while (opc != 4);    
	return 0;
}
