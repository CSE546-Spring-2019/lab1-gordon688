#makefile for hello.c

CC=gcc
CGLAGS = -g -Wall

all: count

count: count.c
	$(CC) $(CFLAGS) -o count count.c

clean:
	rm count

test:
	count testFiles/example1 "Sly Fox" exampleOutput/example1out
	count testFiles/example1 the exampleOutput/example2out
	count testFiles/example2 tomato exampleOutput/example3out
	count testFiles/example2 potato exampleOutput/example4out
	count testFiles/example3 the exampleOutput/example5out
	count testFiles/example3 "I want" exampleOutput/example6out
	count testFiles/example3 "I want to" exampleOutput/example7out
	count testFiles/example4 $$'f\xA' exampleOutput/example8out

verify:
	$(CC) $(CFLAGS) -o check check.c
