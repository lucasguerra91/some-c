build: hash.c hash.h testing.c testing.h pruebas_alumno_hash.c
	gcc -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -o pruebas *.c

run: build
	./pruebas

valgrind:
	valgrind --leak-check=full --error-limit=no --tool=memcheck  --track-origins=yes --show-reachable=yes -v ./pruebas
