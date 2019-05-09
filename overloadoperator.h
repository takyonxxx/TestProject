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

#endif // OVERLOADOPERATOR_H
