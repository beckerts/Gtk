#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include <iostream>
#include <sstream>
#include <string>

#include "gpio.hpp"

using namespace std;

static GPIO gpio;

int main(int argc, char* argv[])
{
    GPIO::IO io;
    int gpno,er;
    string pparm = "-p";

    if ( gpio.get_error() ) {
        fprintf(stderr,
            "%s: Opening gpio\n",
            strerror(gpio.get_error()));
        exit(3);
    }

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
    if ( (er = gpio.configure(gpno,GPIO::Output)) != 0 ) {
                fprintf(stderr,
                    "%s: Setting -g %d -o\n",
                    strerror(er),
                    gpno);
                exit(2);
            }
    cout << "value: " << gpio.read(gpno) << endl;
    
	return 0;
}