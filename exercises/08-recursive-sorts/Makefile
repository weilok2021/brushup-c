CC     = gcc
CFLAGS = -std=gnu11 -Wall -Wextra -g
SAN    = -fsanitize=address,undefined
SRC    = main.c sort.c

recursive-sorts: $(SRC) sort.h
	$(CC) $(CFLAGS) $(SAN) -o recursive-sorts $(SRC)

recursive-sorts-plain: $(SRC) sort.h
	$(CC) $(CFLAGS) -o recursive-sorts-plain $(SRC)

.PHONY: check clean
check: recursive-sorts-plain
	valgrind --leak-check=full --error-exitcode=1 ./recursive-sorts-plain
clean:
	rm -f recursive-sorts recursive-sorts-plain