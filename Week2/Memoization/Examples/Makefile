CC=g++
CFLAGS=-Wall

all: R M

R: Fibonacci_R.cpp
	$(CC) $(CFLAGS) Fibonacci_R.cpp -o Fibonacci_R
	./Fibonacci_R
M: Fibonacci_M.cpp
	$(CC) $(CFLAGS) Fibonacci_M.cpp -o Fibonacci_M
	./Fibonacci_M
Test: Fibonacci.cpp
	$(CC) $(CFLAGS) Fibonacci.cpp -o Fibonacci
	./Fibonacci
clean:
	rm Fibonacci Fibonacci_M Fibonacci_R