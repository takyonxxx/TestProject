#ifndef OVERLOAD_H
#define OVERLOAD_H
#include "libraries.h"

int power(int input, int e)
{
    int tmp = input;

    while(e-- > 1)
    {
        input *= tmp;
    }

    return input;
}

double power(double input, int e)
{
    double tmp = input;

    while(e-- >1)
    {
        input *= tmp;
    }

    return input;
}

#endif // OVERLOAD_H
