CC     = gcc
CFLAGS = -std=gnu11 -Wall -Wextra -g
SAN    = -fsanitize=address,undefined
SRC    = main.c rect.c

rects: $(SRC) rect.h
	$(CC) $(CFLAGS) $(SAN) -o rects $(SRC)

# valgrind cannot run a sanitized binary, so it gets a plain one
rects-plain: $(SRC) rect.h
	$(CC) $(CFLAGS) -o rects-plain $(SRC)

.PHONY: check clean
check: rects-plain
	valgrind --leak-check=full --error-exitcode=1 ./rects-plain
clean:
	rm -f rects rects-plain