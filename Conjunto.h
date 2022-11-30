#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    double longitud;
    double latitud;
}ElementoConjunto;

typedef struct
{
    int ultimo;
    int capacidad;
    ElementoConjunto *datos;
}_Conjunto;

typedef _Conjunto* Conjunto;

Conjunto crearConjunto(int capacidad);
void mostrarConjunto(Conjunto conjunto);
void mostrarPagConjunto(Conjunto conjunto, int num_datos_pag);
bool esConjuntoVacio(Conjunto conjunto);
bool esConjuntoLleno(Conjunto conjunto);
bool aniadirAlConjunto(ElementoConjunto dato, Conjunto conjunto);
bool estaEnConjunto(ElementoConjunto dato, Conjunto conjunto);
int cardinalConjunto(Conjunto conjunto);
bool quitarDelConjunto(ElementoConjunto elemento, Conjunto conjunto);
Conjunto unirConjuntos(Conjunto conjunto1, Conjunto conjunto2);
Conjunto intersectarConjuntos(Conjunto conjunto1, Conjunto conjunto2);
Conjunto copiaConjunto(Conjunto conjunto);
void eliminarConjunto(Conjunto conjunto);

Conjunto crearConjunto(int capacidad)
{
    Conjunto conjunto = (Conjunto) malloc(sizeof(_Conjunto));
    conjunto -> ultimo = -1;
    conjunto -> capacidad = capacidad;
    conjunto -> datos = (ElementoConjunto*) malloc(sizeof(ElementoConjunto) * capacidad);
    //printf("Conjunto creado con exito.\n");
    return conjunto;
}

void mostrarConjunto(Conjunto conjunto)/*Muestra el conjunto*/
{
    int i;
    ElementoConjunto elemento;
    if (esConjuntoVacio(conjunto))
    {
        printf("No hay elementos en el conjunto\n");
    }
    else
    {
        for (i = 0; i < cardinalConjunto(conjunto); i++)
        {
            printf("geo[%d]: longitud=%lf, latitud=%lf\n", i, conjunto -> datos[i].longitud, conjunto -> datos[i].latitud);
        }
    }
    return;
}

void mostrarPagConjunto(Conjunto conjunto, int num_datos_pag)/*Muestra el conjunto por paginas*/
{
    int i, opc;
    ElementoConjunto elemento;
    if (esConjuntoVacio(conjunto))
    {
        printf("No hay elementos en el conjunto\n");
    }
    else
    {
        for (i = 0; i < cardinalConjunto(conjunto); i++)
        {
            printf("geo[%d]: longitud=%lf, latitud=%lf\n", i, conjunto -> datos[i].longitud, conjunto -> datos[i].latitud);
            if ((i+1) % num_datos_pag == 0 || i == cardinalConjunto(conjunto)-1)
            {
                do
                {
                    printf("\nPulse 0 para salir del conjunto actual y 1 para ir a la siguiente pagina: ");
                    fflush(stdin);
                    scanf("%d", &opc);
                    printf("\n");
                    if (opc != 0 && opc != 1)   
                    {
                        printf("Opcion no valida, por favor vuelva a introducir.\n");
                    }
                    else
                    {
                        break;
                    }
                } while (true);
                if (!opc)
                {
                    break;
                }
            }
        }
    }  
    return;
}

bool esConjuntoVacio(Conjunto conjunto) /*Devuelve true si esta vacio sino devuelve false*/
{
    if (conjunto -> ultimo == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool esConjuntoLleno(Conjunto conjunto)/*Devuelve true si esta lleno sino devuelve false*/
{
    if (conjunto -> ultimo == conjunto -> capacidad - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool aniadirAlConjunto(ElementoConjunto dato, Conjunto conjunto)/*Aniade un elemento al conjunto devuelve true si pudo sino devuelve false*/
{
    if (!estaEnConjunto(dato, conjunto)) 
    {
        if (!esConjuntoLleno(conjunto)) 
        {
            conjunto->ultimo++;
            conjunto->datos[conjunto->ultimo] = dato;
            return true;
        }
        else {
            printf("ERROR - aniadir: No cabe la geolocalizacion (longitud=%lf, latitud=%lf).\n", dato.longitud, dato.latitud);
            return false;
        }
    }
    else {
        printf("ERROR - aniadir: No se puede aniadir la geolocalizacion (longitud=%lf, latitud=%lf), ya estaba dentro.\n", dato.longitud, dato.latitud);
        return false;
    }
}

bool estaEnConjunto(ElementoConjunto dato, Conjunto conjunto)/*Devuelve true si el elemento esta en el conjunto*/
{
    bool encontrado = false;
    int i = 0;
    for (i = 0; i < cardinalConjunto(conjunto) && !encontrado; i++)
    {
        encontrado = 
            conjunto -> datos[i].longitud == dato.longitud &&
            conjunto -> datos[i].latitud == dato.latitud;
    }
    return encontrado;
}

int cardinalConjunto(Conjunto conjunto)/*Devuelve el numero de elementos del conjunto*/
{
    return conjunto -> ultimo + 1;
}

bool quitarDelConjunto(ElementoConjunto dato, Conjunto conjunto)/*Borra un elemento del conjunto*/
{
    if (estaEnConjunto(dato, conjunto))
    {
        conjunto -> ultimo--;
        return true;
    }
    else 
    {
        printf("INFO - quitar: No se puede quitar, NO estaba dentro.\n");
        return false;
    }
}


Conjunto unirConjuntos(Conjunto conjunto1, Conjunto conjunto2)/*Devuelve el conjunto union*/
{
    Conjunto union_conjuntos = copiaConjunto(conjunto1);
    int i;
    for (i = 0; i < cardinalConjunto(conjunto2); i++)
    {
        if (!estaEnConjunto(conjunto2 -> datos[i], conjunto1))
        {
            aniadirAlConjunto(conjunto2 -> datos[i], union_conjuntos);
        }
    }
    return union_conjuntos;
}

Conjunto intersectarConjuntos(Conjunto conjunto1, Conjunto conjunto2)/*Devuelve el conjunto interseccion*/
{
    Conjunto interseccion_conjuntos = crearConjunto(conjunto1 -> capacidad);
    int i;
    for (i = 0; i < cardinalConjunto(conjunto2); i++)
    {
        if (estaEnConjunto(conjunto2 -> datos[i], conjunto1))
        {
            aniadirAlConjunto(conjunto2 -> datos[i], interseccion_conjuntos);
        }
    }
    return interseccion_conjuntos;
}

Conjunto copiaConjunto(Conjunto conjunto)/*Devuelve una copia del conjunto*/
{
    Conjunto copia = crearConjunto(conjunto -> capacidad);
    int i;
    for (i = 0; i < cardinalConjunto(conjunto); i++)
    {
        aniadirAlConjunto(conjunto -> datos[i], copia);
    }
    return copia;
}

void eliminarConjunto(Conjunto conjunto)/*Elimina el conjunto de memoria*/
{
    free(conjunto -> datos);
    conjunto -> datos = NULL;
    free(conjunto);
    conjunto = NULL;
    //printf("Conjunto eliminado de memoria.\n");
    return;
}