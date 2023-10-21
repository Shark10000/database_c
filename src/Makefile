FLAGS = -c
#-Wall -Werror -Wextra
CC = gcc

all: build

rebuild: clean_o build

build: general_functions.o main.o crud.o metadata.o
	$(CC) main.o general_functions.o crud.o metadata.o -o program

main.o: main.c
	$(CC) $(FLAGS) -o main.o main.c

general_functions.o: general_functions.c
	$(CC) $(FLAGS) -o general_functions.o general_functions.c

crud.o: crud.c
	$(CC) $(FLAGS) -o crud.o crud.c

metadata.o: metadata.c
	$(CC) $(FLAGS) -o metadata.o metadata.c

clean:
	rm *.o program ../tables/*

clean_o:
	rm *.o program
