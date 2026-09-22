CC     = gcc
CFLAGS = -std=gnu11 -Wall -Wextra -g
SAN    = -fsanitize=address,undefined
SRC    = main.c list.c

list: $(SRC) list.h
	$(CC) $(CFLAGS) $(SAN) -o list $(SRC)

list-plain: $(SRC) list.h
	$(CC) $(CFLAGS) -o list-plain $(SRC)

.PHONY: check clean
check: list-plain
	valgrind --leak-check=full --error-exitcode=1 ./list-plain
clean:
	rm -f list list-plain