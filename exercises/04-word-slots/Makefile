CC     = gcc
CFLAGS = -std=gnu11 -Wall -Wextra -g
SAN    = -fsanitize=address,undefined
SRC    = main.c words.c

word-slots: $(SRC) words.h
	$(CC) $(CFLAGS) $(SAN) -o word-slots $(SRC)

word-slots-plain: $(SRC) words.h
	$(CC) $(CFLAGS) -o word-slots-plain $(SRC)

.PHONY: check clean
check: word-slots-plain
	valgrind --leak-check=full --error-exitcode=1 ./word-slots-plain
clean:
	rm -f word-slots word-slots-plain