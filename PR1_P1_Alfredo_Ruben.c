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
#include "geo_conjunto.h"

void leer_fichero(tConjunto *p_conjunto1, tConjunto *p_conjunto2);
void mostrar(tConjunto conjunto1, tConjunto conjunto2);
void unir(tConjunto conjunto1, tConjunto conjunto2);
void intersectar(tConjunto conjunto1, tConjunto conjunto2);
void cardinales_conjuntos(tConjunto conjunto1, tConjunto conjunto2);

int main()
{
    int opc;
    tConjunto conjunto1 = cjtoVacio(), conjunto2 = cjtoVacio();
    do
    {
        printf("==========================================================================\
        \n                                     MENU\
        \n==========================================================================");
        printf("\n  1.  Leer fichero.\
        \n  2.  Mostrar conjuntos 1, 2.\
        \n  3.  Unir conjuntos 1, 2.\
        \n  4.  Interseccion de conjuntos 1 y 2.\
        \n  5.  Cardinal de conjuntos 1 y 2.\
        \n  6.  Salir del programa.\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("Introduzca opcion (1-6): ");
        scanf("%d", &opc);
        printf("----------------------------------------------------------------------------------------------\n");

        switch (opc)
        {
        case 1:
            leer_fichero(&conjunto1, &conjunto2);
            break;
        case 2:
            mostrar(conjunto1, conjunto2);
            break;
        case 3:
            unir(conjunto1, conjunto2);
            break;
        case 4:
            intersectar(conjunto1, conjunto2);
            break;
        case 5:
            cardinales_conjuntos(conjunto1, conjunto2);
            break;
        case 6:
            printf("Saliendo del programa . . .\n");
            break;
        default:
            printf("Opcion no reconocida, por favor repita la operacion.\n");
            break;
        }
        printf("\n\nPulse enter para continuar . . .");
	    fflush(stdin);
	    getchar();

        system("cls");
    } while (opc != 6);
    return 0;
}

void leer_fichero(tConjunto *p_conjunto1, tConjunto *p_conjunto2)
{
    int line_count;
    geo_localizacion_t aux;

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
                aniadir(aux, p_conjunto1);
            }
            if ((int)aux.latitud % 2 != 0)/*La parte entera de la latitud es impar*/
            {
                aniadir(aux, p_conjunto2);
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

void mostrar(tConjunto conjunto1, tConjunto conjunto2)
{
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Mostrando conjunto con geolocalizaciones cuya parte entera de la longitud es par (conjunto 1)\n");
    printf("----------------------------------------------------------------------------------------------\n");
    mostrar_conjunto(conjunto1);
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Mostrando conjunto con geolocalizaciones cuya parte entera de la latitud es impar (conjunto 2)\n");
    printf("----------------------------------------------------------------------------------------------\n");
    mostrar_conjunto(conjunto2);
    return;
}

void unir(tConjunto conjunto1, tConjunto conjunto2)
{
    tConjunto geo_union = unir_conjuntos(conjunto1, conjunto2);
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Mostrando conjunto union (conjunto1 + conjunto2)\n");
    printf("----------------------------------------------------------------------------------------------\n");
    mostrar_conjunto(geo_union);
    return;
}

void intersectar(tConjunto conjunto1, tConjunto conjunto2)
{
    tConjunto geo_interseccion = intersectar_conjuntos(conjunto1, conjunto2);
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Mostrando conjunto interseccion (conjunto1 ^ conjunto2)\n");
    printf("----------------------------------------------------------------------------------------------\n");
    mostrar_conjunto(geo_interseccion);
    return;
}

void cardinales_conjuntos(tConjunto conjunto1, tConjunto conjunto2)
{
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Mostrando cardinales(conjunto1, conjunto2)\n");
    printf("----------------------------------------------------------------------------------------------\n"); 
    printf("Cardinal conjunto1 = %d, Cardinal conjunto2 = %d\n",cardinal(conjunto1), cardinal(conjunto2));
    return;
}