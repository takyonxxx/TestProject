#ifndef OVERLOAD_H
#define OVERLOAD_H
#include "libraries.h"

class Overload {
public:

    // Member Object
    int feet, inch;

    // Constructor to initialize the object's value
    Overload(int f, int i)
    {
        this->feet = f;
        this->inch = i;
    }

    // Overloading(-) operator to perform decrement
    // operation of Distance object
    void operator-()
    {
        feet--;
        inch--;
        cout << "\nFeet & Inches(Decrement): " << feet << "'" << inch << endl;
    }

    void operator+()
    {
        feet++;
        inch++;
        cout << "\nFeet & Inches(Increment): " << feet << "'" << inch << endl;
    }
};
#endif // OVERLOAD_H
