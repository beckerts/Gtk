#include <iostream>

#include "gpio.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    GPIO gpio;
    GPIO::IO io;
    int gpno=5;
    cout << "gpio declared" << endl;
    cout << "io declared"<< endl;
    cout << "gpno declared: " << gpno << endl;
    cout << "value: " << gpio.read(gpno) << endl;
    gpio.alt_function(gpno,io);
    cout << GPIO::alt_name(io) << endl;
	return 0;
}