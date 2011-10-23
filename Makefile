CC=clang
FLAGS=-Wall -Wextra -fwrapv -pedantic -g

all: tigger

clean:
	rm -f tigger
	rm -f *.o

tigger: tigger.o
	${CC} -o tigger ${FLAGS} tigger.o

tigger.o: tigger.c tigger.h
	${CC} -o tigger.o ${FLAGS} -c tigger.c
