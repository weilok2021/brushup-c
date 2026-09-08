CC     = gcc
CFLAGS = -std=gnu11 -Wall -Wextra -g
SAN    = -fsanitize=address,undefined
SRC    = main.c ints.c

owned-ints: $(SRC) ints.h
	$(CC) $(CFLAGS) $(SAN) -o owned-ints $(SRC)

# valgrind cannot run a sanitized binary, so it gets a plain one
owned-ints-plain: $(SRC) ints.h
	$(CC) $(CFLAGS) -o owned-ints-plain $(SRC)

.PHONY: check clean
check: owned-ints-plain
	valgrind --leak-check=full --error-exitcode=1 ./owned-ints-plain
clean:
	rm -f owned-ints owned-ints-plain