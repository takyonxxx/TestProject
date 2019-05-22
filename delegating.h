#ifndef DELAGATING_H
#define DELAGATING_H

#include "libraries.h"

/*
Constructor Delegation in C++
Sometimes it is useful for a constructor to be able to call another constructor of the same class.
This feature, called Constructor Delegation, was introduced in C++ 11.

 */

class A {
    int x, y, z;
public:
    A()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    // Constructor delegation
    A(int z) : A()
    {
        this->z = z; // Only update z
    }

    void show()
    {
        cout << x << '\n'
             << y << '\n'
             << z;
    }
};

class ParentD
{
    int dogs{5};
    string text{"hello"};
public:

    // Constructor delegation
    ParentD(): ParentD("hello")//we define which constructor will be use
    {
        cout << "Parent No parameter constructor" << endl;
    }

    ParentD(string text)
    {
        this->text = text;
        cout << "Parent String parent constructor" << endl;
    }

    virtual ~ParentD(){}
};


class ChildD : public ParentD
{
public:
    ChildD() = default;
};


void testDelegating()
{
    ParentD parent("Hello");
    ChildD child;

    A obj(3);
    obj.show();
}

#endif // DELAGATING_H
