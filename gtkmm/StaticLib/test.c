#include <stdio.h>

#include "include/test1.h"
#include "include/test2.h"

int main()
{
    int c = 3;
    printf("c before test2: %d\n", c);
    test2(&c);
    printf("c after test2: %d\n", c);
    printf("test1: %d\n", test1(c));
    printf("c after test1: %d\n", c);

    return 0;
}