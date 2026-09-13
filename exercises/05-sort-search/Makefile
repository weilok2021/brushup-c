CC     = gcc
CFLAGS = -std=gnu11 -Wall -Wextra -g
SAN    = -fsanitize=address,undefined
SRC    = main.c sort.c

sort-search: $(SRC) sort.h
	$(CC) $(CFLAGS) $(SAN) -o sort-search $(SRC)

sort-search-plain: $(SRC) sort.h
	$(CC) $(CFLAGS) -o sort-search-plain $(SRC)

.PHONY: check clean
check: sort-search-plain
	valgrind --leak-check=full --error-exitcode=1 ./sort-search-plain
clean:
	rm -f sort-search sort-search-plain
