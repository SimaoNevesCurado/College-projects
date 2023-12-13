OBJS	= main.o funcoes_reservas.o
SOURCE	= main.c funcoes_reservas.c
HEADER	= funcoes_reservas.h
OUT	= a.out
CC	 = gcc
FLAGS	 = -g -c -Wall -Wextra -pedantic -pedantic-errors -Wmissing-declarations -Wredundant-decls -Wfloat-equal -Wmain -Wshadow
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

funcoes_reservas.o: funcoes_reservas.c
	$(CC) $(FLAGS) funcoes_reservas.c 


clean:
	rm -f $(OBJS) $(OUT)
