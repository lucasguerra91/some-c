build: lista.c lista.h testing.c testing.h pruebas_alumno_lista.c
	gcc -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -o pruebas *.c

run: build
	./pruebas

valgrind:
	valgrind --leak-check=full --tool=memcheck  --read-var-info=yes --track-origins=yes --show-reachable=yes -v ./pruebas
