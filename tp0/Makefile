build: tp0.c tp0.h testing.c testing.h tp0_pruebas.c
	gcc -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -o pruebas *.c

run: build
	./pruebas

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes -v ./pruebas
