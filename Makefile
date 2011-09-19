.PHONY: all clean

all: stringy_test

clean:
	rm -f stringy_test
	rm -f stringy_test.o
	rm -f stringy.o

stringy_test: stringy.o stringy_test.o
	gcc -o stringy_test stringy_test.o stringy.o

stringy_test.o: stringy_test.c stringy.h
	gcc -o stringy_test.o -c stringy_test.c

stringy.o: stringy.c stringy.h
	gcc -o stringy.o -c stringy.c
