CC = gcc 
CFLAGS = -Wall -Wextra -std=c11



SRC = makef.c
OBJ = $(SRC:.c=.o)


all: makef

makef: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) makef
