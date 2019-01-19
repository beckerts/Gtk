all: test

test: test.o libs
	g++ -o test test.o -L./lib -ltestlib

test.o: test.c
	g++ -c test.c

libs:
	$(MAKE) -C lib

clean:
	rm *.o test
	$(MAKE) -C lib clean