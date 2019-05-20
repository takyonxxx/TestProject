#ifndef OVERLOADOPERATOR_H
#define OVERLOADOPERATOR_H
#include "libraries.h"
/*Operator Overloading in C++
In C++, we can make operators to work for user defined classes.
This means C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading.
For example, we can overload an operator ‘+’ in a class like String so that we can concatenate two strings by just using +.
Other example classes where arithmetic operators may be overloaded are Complex Number, Fractional Number, Big Integer, etc.*/

class OverloadOperator
{
   private:
      int count;

   public:
       OverloadOperator(): count(5){}

       void operator ++()
       {
          count = count+1;
       }

       void operator --()
       {
          count = count-1;
       }

       void operator *()
       {
          count = count * count;
       }

       void operator/(int divide)
       {
          count = count / divide;
       }

       void Display() { cout<<"Overloaded Count: "<< count << endl; }
};

class Integer
{
    int nr;
public:
    Integer(){};
    Integer(int nr){this->nr = nr;};
    int getNr() {return nr;};
    operator int()
    {
        return this->nr;
    }
    int operator+=(Integer o)
    {
        this->nr = this->nr + o.getNr();
        return this->nr;
    }
    int operator-=(Integer o)
    {
        this->nr = this->nr - o.getNr();
        return this->nr;
    }
};

class TestOp
{
    int id;
    string name;

public:

    TestOp(): id(0), name(""){}

    TestOp(int id, string name): id(id), name(name)
    {
    }

    void print() const
    {
        cout << id << ": " << name << endl;
    }

    //Assignment operator;
    const TestOp &operator=(const TestOp &other)
    {
        cout << "Assignment running" << endl;
        id = other.id;
        name = other.name;
        return *this;
    }

    //Copy Costructor
    TestOp(const TestOp &other)
    {
        cout << "Copy costructor running" << endl;
        id = other.id;
        name = other.name;
    }
};


#endif // OVERLOADOPERATOR_H
