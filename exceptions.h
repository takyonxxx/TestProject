#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include "libraries.h"

//An exception is a problem that arises during the execution of a program.
//A C++ exception is a response to an exceptional circumstance that arises
//while a program is running, such as an attempt to divide by zero. ...
//C++ exception handling is built upon three keywords: try, catch, and throw.

double division(int a, int b) {
   if( b == 0 )
   {
      throw "Division by zero condition!";
   }
   return (a/b);
}

struct MyException : public exception {
   const char * what () const throw () {
      return "C++ test exception";
   }
};

#endif // EXCEPTIONS_H
