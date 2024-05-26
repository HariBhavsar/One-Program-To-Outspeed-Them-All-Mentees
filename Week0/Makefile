# Makefile for compiling a1.cpp and a2.cpp with b.h

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra

# Source files
SRCS = pragma.cpp naive.cpp

# Header file
HEADER = b.h

# Executables
EXECS = $(SRCS:.cpp=)

# Targets
all: $(EXECS)

%: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -o0 $@ $<

clean:
	rm -f $(EXECS)
