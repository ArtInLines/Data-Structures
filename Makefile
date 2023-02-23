CC := gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g
FILES := staticArray.c dynamicArray.c binaryHeap.c

test: test.c $(FILES)
	$(CC) $(CFLAGS) test.c $(FILES) -o test

clean:
	rm -f *.exe
	rm -f *.o