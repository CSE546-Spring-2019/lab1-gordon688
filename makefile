#makefile for hello.c

CC=gcc
CGLAGS = -g -Wall

all: count

count: count.c
	$(CC) $(CFLAGS) -o count count.c

clean:
	rm count

test:
	count testFiles/example1 "Sly Fox" example1out
	count testFiles/example1 the example2out
	count testFiles/example2 tomato example3out
	count testFiles/example2 potato example4out
	count testFiles/example3 the example5out
	count testFiles/example3 "I want" example6out
	count testFiles/example3 "I want to" example7out
	count testFiles/example4 $$'f\xA' example8out
