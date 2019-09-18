build: pila.c pila.h testing.c testing.h pruebas_alumno_pila.c
	gcc -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -o pruebas *.c

run: build
	./pruebas

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas
