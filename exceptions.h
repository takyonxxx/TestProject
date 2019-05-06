#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include "libraries.h"

double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}

struct MyException : public exception {
   const char * what () const throw () {
      return "C++ Exception";
   }
};

#endif // EXCEPTIONS_H
