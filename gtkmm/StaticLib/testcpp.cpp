#include <iostream>

#include "include/test1.h"
#include "include/test2.h"

using namespace std;

int main(int argc, char* argv[])
{
	int c = 3;
    cout << "c before test2: " << c << endl;
    test2(&c);
    cout << "c after test2: " << c << endl;
    cout << "test1: " << test1(c) << endl;
    cout << "c after test1: " << c << endl;
	return 0;
}