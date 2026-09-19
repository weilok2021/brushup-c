CC     = gcc
CFLAGS = -std=gnu11 -Wall -Wextra -g
SAN    = -fsanitize=address,undefined
SRC    = main.c recur.c

recursion: $(SRC) recur.h
	$(CC) $(CFLAGS) $(SAN) -o recursion $(SRC)

recursion-plain: $(SRC) recur.h
	$(CC) $(CFLAGS) -o recursion-plain $(SRC)

.PHONY: check clean
check: recursion-plain
	valgrind --leak-check=full --error-exitcode=1 ./recursion-plain
clean:
	rm -f recursion recursion-plain