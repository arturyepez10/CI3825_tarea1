frecpal: main.o linkedList.o
	gcc main.o linkedList.o -o frecpal

linkedList.o: linkedList.c
	gcc -c linkedList.c -o linkedList.o

main.o: main.c
	gcc -c main.c -o main.o