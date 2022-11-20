/*=============================================================================
 |   Asignatura:  Estructura de datos y algoritmos
 |      Autores:  Alfredo Robledano Abasolo, Ruben Sierra Serrano
 |     Lenguaje:  C
 |        Clase:  2-B
 |        Fecha:  20-11-2022
 +-----------------------------------------------------------------------------
 |  Descripcion:  Lectura de fichero con geolocalizaciones y almacenamiento
 |                en conjuntos para posteriormente realizar operaciones
 |      Entrada:  Fichero csv con latitudes y longitudes, operacion a realizar
 |       Salida:  Resultado de operar sobre los conjuntos obtenidos
 *===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opc;
    do
    {
        printf("==========================================================================\
        \n                                     MENU\
        \n==========================================================================");
        printf("\n  1. Leer fichero.\
        \n  2.  Mostrar conjuntos 1, 2.\
        \n  3.  Unir conjuntos 1, 2.\
        \n  4.  Interseccion de conjuntos 1 y 2.\
        \n  5.  Cardinal de conjuntos 1 y 2.\
        \n  6.  Salir del programa.");

        printf("\nIntroduzca opcion (1-6): ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            /* code */
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
    } while (opc != 6);
    return 0;
}