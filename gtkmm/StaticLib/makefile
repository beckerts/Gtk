all: testcpp

testcpp: testcpp.o libs
	g++ -o testcpp testcpp.o -L./lib -ltestlib -g

testcpp.o: testcpp.cpp
	g++ -c testcpp.cpp -g

libs:
	$(MAKE) -C lib

clean:
	rm *.o testcpp
	$(MAKE) -C lib clean