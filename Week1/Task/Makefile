CC=g++
CFLAGS=-Wall
LDFLAGS=

all: Naive Parallel

Naive: driver.cpp Naive.cpp matrix.h
	$(CC) $(CFLAGS) driver.cpp Naive.cpp -o Naive

Parallel: driver.cpp Parallel.cpp matrix.h
	$(CC) $(CFLAGS) driver.cpp Parallel.cpp -o Parallel

clean:
	rm -f Naive Parallel
