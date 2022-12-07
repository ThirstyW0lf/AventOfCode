CC = gcc
CFLAGS = -Wall -W -pedantic

SRC = supplyStacks.c cargo.c linkedList.c
OBJ = $(SRC:.c=.o)


supplyStacks: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm *.o supplyStacks
