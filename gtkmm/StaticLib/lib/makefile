libtestlib.a: test1.o test2.o
	ar rsv libtestlib.a test1.o test2.o

test1.o: test1.c ../include/test1.h
	g++ -c test1.c -g

test2.o: test2.c ../include/test2.h
	g++ -c test2.c -g

clean:
	rm *.o *.a