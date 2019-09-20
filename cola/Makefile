build: cola.c cola.h testing.c testing.h pruebas_alumno_cola.c
	clear ; echo Compilado con éxito.. ; gcc -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -o pruebas *.c

run: build
	clear ; echo Ejecutando.. ; ./pruebas

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes -v ./pruebas
