CC = gcc
CFLAGS = -Wall -W -pedantic

SRC = rockPaperScissors.c strategyGuide.c
OBJ = $(SRC:.c=.o)


rockPaperScissors: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm *.o rockPaperScissors
