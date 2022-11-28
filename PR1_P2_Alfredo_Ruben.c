/*=============================================================================
 |   Asignatura:  Estructura de datos y algoritmos
 |      Autores:  Alfredo Robledano Abasolo, Ruben Sierra Serrano
 |     Lenguaje:  C
 |        Clase:  2-B
 |        Fecha:  20-11-2022
 +-----------------------------------------------------------------------------
 |  Descripcion:  Lectura de fichero con geolocalizaciones y almacenamiento
 |                en pilas y colas para posteriormente realizar operaciones
 |      Entrada:  Fichero csv con latitudes y longitudes, operacion a realizar
 |       Salida:  Resultado de operar sobre las pilas y colas obtenidas
 *===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "cola.h"

void gestionarPilasColas(Pila pila1, Pila pila2, Cola cola1, Cola cola2);

int main()
{
    int opc;
    Pila pila1 = crearPila(), pila2 = crearPila();
    Cola cola1 = crearCola(), cola2 = crearCola();
    do
    {
        printf("==========================================================================\
        \n                                     MENU\
        \n==========================================================================");
        printf("\n  1.  Gestionar pilas y colas.\
        \n  2.  Mostrar pilas.\
        \n  3.  Intercambiar posiciones pares e impares en pila 1 y pila 2.\
        \n  4.  Eliminar posiciones pares en pila.\
        \n  5.  Limpiar pilas.\
        \n  6.  Mostar colas.\
        \n  7.  Intercambiar posiciones pares e impares en cola 1 y cola2.\
        \n  8.  Eliminar posiciones pares en cola.\
        \n  9.  Limpiar colas.\
        \n 10.  Salir");

        printf("----------------------------------------------------------------------------------------------\n");
        printf("\nIntroduzca opcion (1-10): ");
        scanf("%d", &opc);
        printf("----------------------------------------------------------------------------------------------\n");

        switch (opc)
        {
        case 1:
            gestionarPilasColas(pila1, pila2, cola1, cola2);
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        case 8:
            /* code */
            break;
        case 9:
            /* code */
            break;
        case 10:
            printf("\nSaliendo del programa . . .");
            break;
        default:
            printf("\nOpcion no reconocida, por favor repita la operacion.");
            break;
        }
        printf("\n\n\nPulse enter para continuar . . .");
	    fflush(stdin);
	    getchar();

        system("cls");
    } while (opc != 10);

    return 0;
}

void gestionarPilasColas(Pila pila1, Pila pila2, Cola cola1, Cola cola2)
{
    int line_count;
    ElementoPila aux;

    FILE *pfich = fopen("fichnum.csv", "r");

    if (pfich == NULL) {
        printf("Error al abrir el fichero \"fichnum.csv\"\n");
    }
    else
    {   
        printf("Leyendo el fichero . . .\n");
        for (
            line_count = 0;
            fscanf(pfich, "%lf;%lf", &aux.longitud, &aux.latitud) == 2;
            line_count++
        )
        {
            if ((int)aux.longitud % 2 == 0)/*La parte entera de la longitud es par*/
            {
                apilar(aux, pila1);
            }
            if ((int)aux.latitud % 2 != 0)/*La parte entera de la latitud es impar*/
            {
                apilar(aux, pila2);
            }
        }
        if (fclose(pfich) != 0) {
            printf("Error al cerrar el fichero \"fichnum.csv\"\n");
        }
        printf("----------------------------------------------------------------------------------------------\n");
        printf("Fichero leido con exito\n");
        printf("----------------------------------------------------------------------------------------------\n");
    }
    return;
}