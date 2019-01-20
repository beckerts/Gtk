#include <iostream>
#include <sstream>

#include "gpio.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    GPIO gpio;
    GPIO::IO io;
    int gpno=5;
    string pparm = "-p";

    cout << "argc = " << argc << endl;
    for (int i =0; i<argc; i++)
    {
        cout << "argv[" << i<< "] = " << argv[i] << endl;
    }
    if (argc >= 3 && pparm.compare( argv[1]) == 0)
    {
        cout << "converting " << argv[2] << " to int." << endl;
        istringstream convert(argv[2]);
        if (!(convert >> gpno)) gpno = 0;
    }
    cout << "gpio declared" << endl;
    cout << "io declared"<< endl;
    cout << "gpno declared: " << gpno << endl;
    cout << "value: " << gpio.read(gpno) << endl;
    
	return 0;
}