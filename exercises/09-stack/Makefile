CC     = gcc
CFLAGS = -std=gnu11 -Wall -Wextra -g
SAN    = -fsanitize=address,undefined
SRC    = main.c stack.c

stack: $(SRC) stack.h
	$(CC) $(CFLAGS) $(SAN) -o stack $(SRC)

stack-plain: $(SRC) stack.h
	$(CC) $(CFLAGS) -o stack-plain $(SRC)

.PHONY: check clean
check: stack-plain
	valgrind --leak-check=full --error-exitcode=1 ./stack-plain
clean:
	rm -f stack stack-plain
