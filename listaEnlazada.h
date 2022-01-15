#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMCARACT 50

typedef int tipoInfo;
typedef struct tipoNodo{
	tipoInfo info;
	struct tipoNodo *next;
}tipoNodo;
typedef tipoNodo *punteroNodo;
typedef tipoNodo *tipoLista;


void mensajeError(char *s);


//crea un nodo vacio a modo de cabeza de lista
tipoLista crearLista(tipoInfo nuevaInfo);

//añade un nodo al final de la lista
int añadirNodo(tipoLista lista, tipoInfo nuevaInfo);

int eliminarNodo(tipoInfo infoBuscada, tipoLista lista);
int liberarLista(tipoLista lista);

int recorrerLista(tipoLista lista);
