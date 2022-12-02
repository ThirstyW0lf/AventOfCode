CC = gcc
CFLAGS = -Wall -W -pedantic

SRC = calories.c supplies.c
OBJ = $(SRC:.c=.o)


calories: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm *.o calories
