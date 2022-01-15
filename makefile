main: listaEnlazada.o main.c
	gcc -g 	listaEnlazada.o main.c -o main

listaEnlazada.o: listaEnlazada.c listaEnlazada.h
	gcc -c -g listaEnlazada.c

pila.o: pila.c pila.h
	gcc -c -g pila.c
