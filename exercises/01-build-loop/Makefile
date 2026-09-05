CC     = gcc
CFLAGS = -std=gnu11 -Wall -Wextra -g
SAN    = -fsanitize=address,undefined
SRC    = main.c vec.c

sum: $(SRC) vec.h
	$(CC) $(CFLAGS) $(SAN) -o sum $(SRC)

# valgrind cannot run a sanitized binary, so it gets a plain one
sum-plain: $(SRC) vec.h
	$(CC) $(CFLAGS) -o sum-plain $(SRC)

.PHONY: check clean
check: sum-plain
	valgrind --leak-check=full --error-exitcode=1 ./sum-plain
clean:
	rm -f sum sum-plain
