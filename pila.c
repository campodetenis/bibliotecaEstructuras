#include "listaEnlazada.c"
#include <stdlib.h>
#include <stdio.h>

typedef int tipoInfo;
typedef struct pila{
	tipoInfo info;
	struct pila *siguiente; 
}tipoPila;

typedef tipoPila *nodoPila;

nodoPila crearPila(tipoInfo nuevaInfo){
	nodoPila pila;
	if(NULL == (pila = malloc(sizeof(tipoPila)))){
		mensajeError("crearPila: error en malloc");
		exit -1;
	}

	pila->info=nuevaInfo;
	pila->siguiente = NULL;
	return pila;
}

int añadirNodoPila(nodoPila pila, tipoInfo nuevaInfo){
	nodoPila temp;

	if(NULL == (temp = malloc(sizeof(tipoPila)))){
		mensajeError("crearPila: error en malloc");
		return 0;
	}

	temp->info = nuevaInfo;
	temp->siguiente = pila;
	pila = temp;
		printf("%d\n",pila->info);
		printf("%d\n",pila->siguiente->info);
	return 1;
}

tipoInfo eliminarNodoPila(nodoPila pila){
	nodoPila aux;
	tipoInfo returnValue;

	returnValue = pila->info;
	aux = pila;
	pila = pila->siguiente;
	aux->siguiente = NULL;
	free(aux);
	return returnValue;
}

int liberarPila(nodoPila pila){
	nodoPila borrar;

	while(pila != NULL){
		borrar = pila;
		pila = pila->siguiente;
		free(borrar);
	}
	borrar = NULL;
	pila = NULL;
	return 1;
}


int main(int argc, char const *argv[])
{
	nodoPila pila;

	pila = crearPila(3);
	añadirNodoPila(pila,3);
	añadirNodoPila(pila,7);
	while(pila != NULL){
		printf("%d -> ",eliminarNodoPila(pila));
	}
	return 0;
}