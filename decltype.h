#ifndef DECLTYPE_H
#define DECLTYPE_H
#include "libraries.h"
#include <typeinfo>
/*Type Inference in C++ (auto and decltype)
Type Inference refers to automatic deduction of the data type of an expression in a programming language.
Before C++ 11, each data type needs to be explicitly declared at compile time,
limiting the values of an expression at runtime but after the new version of C++,
many keywords are included which allows a programmer to leave the type deduction to the compiler itself.
With type inference capabilities, we can spend less time having to write out things compiler already knows.
As all the types are deduced in compiler phase only,
the time for compilation increases slightly but it does not affect the run time of the program.
*/
template<class T>
auto test(T value) -> decltype(value)
{
    return value;
}

int get()
{
    return 999;
}

auto test2() -> decltype(get())
{
    return get();
}

// A generic function which finds minimum of two values
// return type is type of variable which is minimum
template <class A, class B>
auto findMin(A a, B b) -> decltype(a < b ? a : b)
{
    return (a < b) ? a : b;
}

void testType()
{
    int value1;
    string value2;
    cout << typeid(value1).name() << typeid(value2).name() << endl;//string is coplicated class and passing too many info

    //define your type
    decltype(value2) name = "My Type";
    cout << name << endl;

    cout << test("hello") << endl;
    cout << test(1.2) << endl;

    cout << test2() << endl;

    //auto
    auto value = "text";
    cout << value << endl;

    auto x = 4;
    auto y = 3.37;
    auto ptr = &x;

    cout << typeid(x).name() << endl
         << typeid(y).name() << endl
         << typeid(ptr).name() << endl;

    // This call returns 3.44 of doubale type
    cout << findMin(4, 3.44) << endl;

    // This call returns 3 of double type
    cout << findMin(5.4, 3) << endl;

}
#endif // DECLTYPE_H
