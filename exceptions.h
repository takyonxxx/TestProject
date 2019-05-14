#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include "libraries.h"

//An exception is a problem that arises during the execution of a program.
//A C++ exception is a response to an exceptional circumstance that arises
//while a program is running, such as an attempt to divide by zero. ...
//C++ exception handling is built upon three keywords: try, catch, and throw.

class CanGoWrong{
public:
    CanGoWrong(){
        char *pMemory = new char [1024];
        delete []pMemory;
    }
};

double division(int a, int b) {
   if( b == 0 )
   {
      throw "Division by zero condition!";
   }
   return (a/b);
}

void goesWrong()
{
    bool error1 = true;
    bool error2 = false;

    if(error1)
    {
     throw bad_alloc();
    }

    if(error2)
    {
     throw exception();
    }
}

struct MyException : public exception
{

public:
  virtual const char * what () const throw(){
      return "Something went wrong";
   }
};

#endif // EXCEPTIONS_H
