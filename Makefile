# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

default: mabshell

utils: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c utils.h

mabshell: utils.o mabshell.c mabshell.h
	$(CC) $(CFLAGS) -o mabshell mabshell.c utils.o

clean:
	$(RM) mabshell *.o