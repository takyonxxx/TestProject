#ifndef COSTRUCTORS_H
#define COSTRUCTORS_H
#include "libraries.h"

class TestConstructorClass
{
    int id;
    string name;

public:

    TestConstructorClass(): id(0), name(""){}

    TestConstructorClass(int id, string name): id(id), name(name)
    {
    }

    void print() const
    {
        cout << id << ": " << name << endl;
    }

    //Assignment operator;
    const TestConstructorClass &operator=(const TestConstructorClass &other)
    {
        cout << "Assignment running" << endl;
        id = other.id;
        name = other.name;
        return *this;
    }

    //Copy Costructor
    TestConstructorClass(const TestConstructorClass &other)
    {
        cout << "Copy costructor running" << endl;
        id = other.id;
        name = other.name;
        *this = other;
    }

    //allow access private methods
    friend ostream &operator<<(ostream &out, const TestConstructorClass &test)
    {
        out << test.id << ": " << test.name;
        return  out;
    }

};
#endif // COSTRUCTORS_H
