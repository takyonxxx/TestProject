#ifndef OVERLOADOPERATOR_H
#define OVERLOADOPERATOR_H
#include "libraries.h"

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

#endif // OVERLOADOPERATOR_H
