CC     = gcc
CFLAGS = -std=gnu11 -Wall -Wextra -g
SAN    = -fsanitize=address,undefined
SRC    = main.c partition.c

partition: $(SRC) partition.h
	$(CC) $(CFLAGS) $(SAN) -o partition $(SRC)

partition-plain: $(SRC) partition.h
	$(CC) $(CFLAGS) -o partition-plain $(SRC)

.PHONY: check clean
check: partition-plain
	valgrind --leak-check=full --error-exitcode=1 ./partition-plain
clean:
	rm -f partition partition-plain