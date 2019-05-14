#ifndef PRAGMADIRECTIVE_H
#define PRAGMADIRECTIVE_H
#include "libraries.h"

/*#pragma Directive in C/C++
This directive is a special purpose directive and is used to turn on or off some features.
This type of directives are compiler-specific i.e., they vary from compiler to compiler.
Some of the #pragma directives are discussed below:

#pragma startup and #pragma exit:
These directives helps us to specify the functions that are needed to run before program startup( before the control passes to main())
and just before program exit (just before the control returns from main()).
*/

//with padding size 64
struct Person1
{
    char name[50];
    int age;
    double weight;
};


#pragma pack(push, 1) // exact fit - no padding, size 62
struct Person2
{
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop) //back to whatever the previous packing mode was

/*
#pragma warn -rvl: This directive hides those warning which are raised when a function which is supposed to return a value does not return a value.
#pragma warn -par: This directive hides those warning which are raised when a function does not uses the parameters passed to it.
#pragma warn -rch: This directive hides those warning which are raised when a code is unreachable.
For example: any code written after the return statement in a function is unreachable.*/

#pragma warn -rvl /* return value */
#pragma warn -par /* parameter never used */
#pragma warn -rch /*unreachable code */

int show(int x)
{
    // parameter x is never used in
    // the function

    printf("GEEKSFORGEEKS, no return, no parameter never used, no unreachable code\n");

    // function does not have a
    // return statement
    //return 0;
}

void pragmaTest()
{
    //pragma padding
    cout << "with pragma size of Person: " << sizeof (Person1)
         << " without pragma size of Person: " << sizeof (Person2) << endl;

    show(10);
}

#endif // PRAGMADIRECTIVE_H
