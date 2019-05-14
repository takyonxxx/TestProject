#ifndef ENCAPSULATION_H
#define ENCAPSULATION_H
#include "libraries.h"
/*
Encapsulation lead to data abstraction or hiding.
As using encapsulation also hides the data.
In the above example the data of any of the section like sales, finance or accounts is hidden from any other section.
In C++ encapsulation can be implemented using Class and access modifiers.
*/
class Encapsulation
{
    private:
        // data hidden from outside world
        int x;

    public:
        // function to set value of
        // variable x
        void set(int a)
        {
            x =a;
        }

        // function to return value of
        // variable x
        int get()
        {
            return x;
        }
};

#endif // ENCAPSULATION_H
