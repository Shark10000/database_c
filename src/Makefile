FLAGS = -c
#-Wall -Werror -Wextra
CC = gcc

all: build

build: main.o create_table.o
	$(CC) main.o create_table.o -o controler

main.o: main.c
	$(CC) $(FLAGS) -o main.o main.c

create_table.o: create_table.c
	$(CC) $(FLAGS) -o create_table.o create_table.c

clean:
	rm *.o controler ./tables/*