#include <stdio.h>
#include "listaEnlazada.h"

int main(int argc, char const *argv[])
{
	tipoLista lista;

	lista=crearLista(3);
	añadirNodo(lista,5);
	añadirNodo(lista,9);
	añadirNodo(lista,10);
	añadirNodo(lista,24);
	recorrerLista(lista);

	liberarLista(lista);
	lista =NULL;
	return 0;
}