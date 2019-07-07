all: test

test: test.o 
	g++ -o test test.o -L./lib -lrpi2

test.o: test.cpp
	g++ -c test.cpp -I./include

clean:
	rm *.o test
