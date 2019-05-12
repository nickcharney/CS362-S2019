CFLAGS= -Wall -fpic -coverage -lm -std=c99

all: testme.c
	gcc -o testme testme.c $(CFLAGS)

testmeresults.out: testme.c
	echo "testme.c" >> testmeresults.out
	gcc -o testme testme.c $(CFLAGS)
	./testme >> testmeresults.out
	gcov testme.c -b >> testmeresults.out

clean:
	rm -f *.gcno *.gcda testme testmeresults.out
