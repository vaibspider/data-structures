list: main.o list.o
	gcc main.o list.o -Wall -o list
list.o: list.c list.h
	gcc -c -Wall list.c
main.o: main.c list.h
	gcc -c -Wall main.c
