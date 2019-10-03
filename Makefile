main: main.o readFile.o
	gcc main.o readFile.o -o main

readFile.o: readFile.c
	gcc -c readFile.c -o readFile.o

main.o: main.c
	gcc -c main.c -o main.o