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

#define N 100

void gestionarPilasColas(Pila pila1, Pila pila2, Cola cola1, Cola cola2);
void mostrarGeoPilas(Pila pila1, Pila pila2);
void intercambiarPilaPosParImpar(Pila pila);
void eliminarPilaPosPares(Pila pila);
void limpiarPilas(Pila pila1, Pila pila2);

void mostrarGeoColas(Cola cola1, Cola cola2);
void intercambiarColaPosParImpar(Cola cola);
void limpiarColas(Cola cola1, Cola cola2);

int main()
{
    int opc;
    Pila pila1 = crearPila(N), pila2 = crearPila(N);
    Cola cola1 = crearCola(N), cola2 = crearCola(N);
    do
    {
        printf("==============================================================================================\
        \n                                     MENU\
        \n==============================================================================================");
        printf("\n  1.  Gestionar pilas y colas.\
        \n  2.  Mostrar pilas.\
        \n  3.  Intercambiar posiciones pares e impares en pila 1 y pila 2.\
        \n  4.  Eliminar posiciones pares en pila.\
        \n  5.  Limpiar pilas.\
        \n  6.  Mostar colas.\
        \n  7.  Intercambiar posiciones pares e impares en cola 1 y cola 2.\
        \n  8.  Eliminar posiciones pares en cola.\
        \n  9.  Limpiar colas.\
        \n 10.  Salir\n");

        printf("----------------------------------------------------------------------------------------------\n");
        printf("Introduzca opcion (1-10): ");
        scanf("%d", &opc);
        printf("----------------------------------------------------------------------------------------------\n");

        switch (opc)
        {
        case 1:
            gestionarPilasColas(pila1, pila2, cola1, cola2);
            break;
        case 2:
            mostrarGeoPilas(pila1, pila2);
            break;
        case 3:
            intercambiarPilaPosParImpar(pila1);
            intercambiarPilaPosParImpar(pila2);
            break;
        case 4:
            eliminarPilaPosPares(pila1);
            eliminarPilaPosPares(pila2);
            break;
        case 5:
            limpiarPilas(pila1, pila2);
            break;
        case 6:
            mostrarGeoColas(cola1, cola2);
            break;
        case 7:
            intercambiarColaPosParImpar(cola1);
            intercambiarColaPosParImpar(cola2);
            break;
        case 8:
            /* code */
            break;
        case 9:
            limpiarColas(cola1, cola2);
            break;
        case 10:
            printf("\nSaliendo del programa . . .");
            eliminarPila(pila1);eliminarPila(pila2);
            eliminarCola(cola1);eliminarCola(cola2);
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
    ElementoPila paux;
    ElementoCola caux;

    FILE *pfich = fopen("fichnum.csv", "r");

    if (pfich == NULL) {
        printf("Error al abrir el fichero \"fichnum.csv\"\n");
    }
    else
    {   
        printf("Leyendo el fichero . . .\n");
        for (
            line_count = 0;
            fscanf(pfich, "%lf;%lf", &paux.longitud, &paux.latitud) == 2;
            line_count++
        )
        {
            caux.longitud = paux.longitud;
            caux.latitud = paux.latitud;
            if ((int)paux.longitud % 2 == 0 && (int)paux.longitud)/*La parte entera de la longitud es par*/
            {
                apilar(paux, pila1);
            }
            else/*La parte entera de la longitud es impar o 0*/
            {
                apilar(paux, pila2);
            }
            if ((int)caux.longitud % 2 == 0 && (int)caux.longitud)/*La parte entera de la longitud es par*/
            {
                encolar(caux, cola1);
            }
            else/*La parte entera de la longitud es impar o 0*/
            {
                encolar(caux, cola2);
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

void mostrarGeoPilas(Pila pila1, Pila pila2)
{
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Mostrando pila con geolocalizaciones cuya parte entera de la longitud es par (pila 1)\n");
    printf("----------------------------------------------------------------------------------------------\n");
    mostrarPila(pila1);
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Mostrando pila con geolocalizaciones cuya parte entera de la longitud es impar o cero (pila 2)\n");
    printf("----------------------------------------------------------------------------------------------\n");
    mostrarPila(pila2);
    return;
}

void intercambiarPilaPosParImpar(Pila pila)
{
    int i;
    Pila pares = crearPila(longitudPila(pila) / 2 + (longitudPila(pila) % 2));/*Sumamos uno si la pila a reordenar tiene longitud impar*/
    Pila impares = crearPila(longitudPila(pila) / 2);
    ElementoPila aux;
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Reordenando pila . . .\n");
    printf("----------------------------------------------------------------------------------------------\n");
    for (i = longitudPila(pila); !esPilaVacia(pila); i++)
    {
        aux = desapilar(pila);
        if (i % 2 == 0)
        {
            apilar(aux, pares);
        }
        else
        {
            apilar(aux, impares);
        }
    }
    for (i = 0; !esPilaVacia(pares); i++)
    {
        if (i % 2 == 0)
        {
            aux = desapilar(pares);
        }
        else
        {
            aux = desapilar(impares);
        }
        apilar(aux, pila);
    }
    eliminarPila(pares);
    eliminarPila(impares);
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Pila reordenada con exito\n");
    printf("----------------------------------------------------------------------------------------------\n");
    return;
}

void eliminarPilaPosPares(Pila pila)
{
    int i;
    Pila pares = crearPila(longitudPila(pila) / 2 + longitudPila(pila) % 2);
    ElementoPila aux;
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Eliminando posiciones pares de la pila. . .\n");
    printf("----------------------------------------------------------------------------------------------\n");
    for (i = longitudPila(pila); !esPilaVacia(pila); i++)
    {
        aux = desapilar(pila);
        if (i % 2 == 0)
        {
            apilar(aux, pares);
        }
    }
    while (!esPilaVacia(pares))
    {
        aux = desapilar(pares);
        apilar(aux, pila);
    }
    eliminarPila(pares);
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Elementos eliminados con exito.\n");
    printf("----------------------------------------------------------------------------------------------\n");
    return;
}

void limpiarPilas(Pila pila1, Pila pila2)
{
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Borrando elementos de las pilas\n");
    printf("----------------------------------------------------------------------------------------------\n");
    vaciarPila(pila1);
    vaciarPila(pila2);
    return;
}

void mostrarGeoColas(Cola cola1, Cola cola2)
{
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Mostrando cola con geolocalizaciones cuya parte entera de la longitud es par (cola 1)\n");
    printf("----------------------------------------------------------------------------------------------\n");
    mostrarCola(cola1);
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Mostrando cola con geolocalizaciones cuya parte entera de la longitud es impar o cero (cola 2)\n");
    printf("----------------------------------------------------------------------------------------------\n");
    mostrarCola(cola2);
    return;
}

void intercambiarColaPosParImpar(Cola cola)
{
    int i;
    Cola pares = crearCola(longitudCola(cola) / 2 + (longitudCola(cola) % 2));/*Sumamos uno si la cola a reordenar tiene longitud impar*/
    Cola impares = crearCola(longitudCola(cola) / 2);
    ElementoCola aux;
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Reordenando cola . . .\n");
    printf("----------------------------------------------------------------------------------------------\n");
    for (i = 0; !esColaVacia(cola); i++)
    {
        aux = desencolar(cola);
        if (i % 2 == 0)
        {
            encolar(aux, pares);
        }
        else
        {
            encolar(aux, impares);
        }
    }
    for (i = 0; !esColaVacia(pares); i++)
    {
        if (i % 2 == 0)
        {
            aux = desencolar(impares);
        }
        else
        {
            aux = desencolar(pares);
        }
        encolar(aux, cola);
    }
    eliminarCola(pares);
    eliminarCola(impares);
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Cola reordenada con exito\n");
    printf("----------------------------------------------------------------------------------------------\n");
    return;
}

void limpiarColas(Cola cola1, Cola cola2)
{
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Borrando elementos de las colas\n");
    printf("----------------------------------------------------------------------------------------------\n");
    vaciarCola(cola1);
    vaciarCola(cola2);
    return;
}
