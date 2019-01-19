libtestlib.a: test1.o test2.o
	ar rsv libtestlib.a test1.o test2.o

test1.o: test1.c
	g++ -c test1.c

test2.o: test2.c
	g++ -c test2.c

clean:
	rm *.o *.a