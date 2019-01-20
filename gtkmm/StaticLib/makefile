all: testcpp

testcpp: testcpp.o libs
	g++ -o testcpp testcpp.o -L./lib -ltestlib

testcpp.o: testcpp.cpp
	g++ -c testcpp.cpp

libs:
	$(MAKE) -C lib

clean:
	rm *.o testcpp
	$(MAKE) -C lib clean