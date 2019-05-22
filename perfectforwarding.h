#ifndef PERFECTFORWARDING_H
#define PERFECTFORWARDING_H
#include "libraries.h"

/*
Perfect forwarding allows us to preserve an argument’s value category (lvalue/rvalue)
and const/volatile modifiers. Perfect forwarding is performed in two steps:
receive a forwarding reference (also known as universal reference),
then forward it using std::forward.
*/

class PTest
{

};

template <typename T>
void call(T &&arg)
{
    check(forward<T>(arg));
}

//doing same job
template <typename T>
void call2(T &&arg)
{
    check(static_cast<T>(arg));
}

void check(const PTest &value)
{
   cout << "l-value function!" << endl;
}

void check(const PTest &&value)
{
   cout << "r-value function!" << endl;
}

void testPerfectForwarding()
{
    PTest test;
    auto &&t1 = PTest(); //rvalue ref type

    call(PTest()); // passing r-value
    call(test); // passing l-value

    call2(PTest()); // passing r-value
    call2(test); // passing l-value

}

#endif // PERFECTFORWARDING_H
