#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEnlazada.h"


void mensajeError(char *s){
	perror(s);
}

//crea un nodo vacio a modo de cabeza de lista
tipoLista crearLista(tipoInfo nuevaInfo){
	tipoLista lista;
	char etiqueta[NUMCARACT];
	if(NULL == (lista = malloc(sizeof(tipoNodo)))){
		sprintf(etiqueta,"error al hacer malloc");
		exit -1;
	}
	lista->info = nuevaInfo;
	lista->next = NULL;
	return lista;
}

//añade un nodo al final de la lista
int añadirNodo(tipoLista lista, tipoInfo nuevaInfo){
	punteroNodo pt;

	if(lista == NULL){
		mensajeError("añadirNodo:lista vacia");
		return 0;
	}

	if(NULL == (pt = malloc(sizeof(tipoNodo)))){
		mensajeError("malloc:error creando nodo");
		return 0;
	}


	pt->info = nuevaInfo;
	pt->next = NULL;
	while(lista->next != NULL){
		lista = lista->next;
	}
	if(lista->next == NULL){
		lista->next = pt;
	}

	return 1;
}

int eliminarNodo(tipoInfo infoBuscada, tipoLista lista){
	punteroNodo borrar;

	if(lista == NULL){
		mensajeError("eliminarNodo:lista vacia");
		return 0;
	}

	//si la cabeza es donde está la info
	if(lista->info == infoBuscada){
		borrar = lista;
		lista = lista->next;
		free(borrar);
		return 1;
	}

	//si el elemento a borrar no es la cabeza
	while(lista != NULL){
		if(lista->next->info == infoBuscada){
			borrar = lista->next;
			lista = borrar->next;
			free(borrar);
			return 1;
		}
	}

	//si el elemento a borrar no esta devolvemos 0
	return 0;
}

int liberarLista(tipoLista lista){
	tipoLista aux;
	tipoLista borrar;

	aux = lista->next;
	while(aux !=NULL){
		borrar = aux;
		aux = aux->next;
		free(borrar);
		borrar=NULL;
	}
	free(lista);
	lista =NULL;
	return 1;
}

int recorrerLista(tipoLista lista){

	if(lista == NULL){
		mensajeError("recorrerLista:la lista está vacia");
		return 0;
	}

	while(lista !=NULL){
		printf("%d\n",lista->info);
		lista=lista->next;
	}
	return 1;
}

