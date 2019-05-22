#ifndef BIND_H
#define BIND_H
#include "libraries.h"
#include <functional>

/*Bind function and placeholders in C++
Sometimes we need to manipulate the operation of a function according to the need,
i.e changing some arguments to default etc. Predefining a function to have default
arguments restricts the versatility of a function and forces us to use the default
arguments and that too with similar value each time. From C++11 onwards,
the introduction of bind function has made this task easier.

How does bind() work?
Bind function with the help of placeholders,
helps to manipulate the position and number of values to be used
by the function and modifies the function according to the desired output.

What are placeholders?
Placeholders are namespace which direct the position of a value in a function.
They are represented by _1, _2, _3…
*/

using namespace  placeholders;

class BTest
{
public:
    int add(int a, int b, int c)
    {
        cout << a << ", " << b  << ", " << c << endl;
        return a + b + c;
    }
};

int add(int a, int b, int c)
{
    cout << a << ", " << b  << ", " << c << endl;
    return a + b + c;
}

int run(function<int(int, int)> func)
{
   return func(7, 3);
}

void testBind()
{
    // Use of bind() to bind the function
       // _1 is for first parameter and assigned
       // to 'a' in above declaration.
       // 2 is assigned to b
       // 3 is assigned to c
       auto fn1 =  bind(add, _1, 2, 3);

       // 2 is assigned to a.
       // _1 is for first parameter and assigned
       // to 'b' in above declaration.
       // 3 is assigned to c.
       auto fn2 =  bind(add, 2, _1, 3);

       // calling of modified functions
       cout << fn1(10) << endl;//10,2,3
       cout << fn2(20) << endl;//2,20,3

       auto calculate = bind(add, _2, 100, _1);
       cout << run(calculate) << endl;

       //in class
       BTest test;
       auto calculateC = bind(&BTest::add, test, _2, 100, _1);
       cout << run(calculateC) << endl;
}

#endif // BIND_H
