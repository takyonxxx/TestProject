#ifndef LVALUE_RVALUE_H
#define LVALUE_RVALUE_H
#include "libraries.h"
#include <vector>

/*
L-value: “l-value” refers to memory location which identifies an object.
l-value may appear as either left hand or right hand side of an assignment operator(=).
l-value often represents as identifier.

R-value: r-value” refers to data value that is stored at some address in memory.
A r-value is an expression that can’t have a value assigned to it which means
r-value can appear on right but not on left hand side of an assignment operator(=).

An lvalue reference is formed by placing an & after some type.

A a;
A& a_ref1 = a;  // an lvalue reference

An rvalue reference is formed by placing an && after some type.

A a;
A&& a_ref2 = a;  // an rvalue reference
An rvalue reference behaves just like an lvalue reference except that it can bind to a temporary (an rvalue),
whereas you can not bind a (non const) lvalue reference to an rvalue.

A&  a_ref3 = A();  // Error!
A&& a_ref4 = A();  // Ok
 */

class ValTest
{
    static const int SIZE = 100;
    int *_pBuffer{nullptr};
public:
    ValTest(){
        //cout << "constructor" << endl;
        _pBuffer = new int[SIZE]{};
        //memset(_pBuffer, 0, sizeof (int)*SIZE); we use {} instead of memset
    }

    ValTest(int i){
        //cout << "parameterized constructor" << endl;
        _pBuffer = new int[SIZE]{};

        for (int i=0;i < SIZE; i++) {
            _pBuffer[i] = 7*i;
        }
    }

    ValTest(const ValTest &other){
        //cout << "copy constructor" << endl;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof (int));
    }

    //move constructor
    ValTest(ValTest &&other)
    {
        cout << "move constructor" << endl;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;
    }

    ValTest &operator=(const ValTest &other){
        //cout << "assignment" << endl;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof (int));
        return *this;
    }

    ValTest &operator=(ValTest &&other){
        cout << "move assignment" << endl;
        delete [] _pBuffer;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;
        return *this;
    }

    ~ValTest(){
        //cout << "destructor" << endl;
        delete [] _pBuffer;
    }

    friend ostream &operator<<(ostream &out, const ValTest &test);
};

ostream &operator<<(ostream &out, const ValTest &test)
{
    out << "Hello from ValTest";
    return out;
}

//when you see this kind of method, know that it is not efficient, compiler will optimize it
ValTest getValTest()
{
    return ValTest();
}

void check(const ValTest &value)
{
   cout << "l-value function!" << endl;
}

void check(const ValTest &&value)
{
   cout << "r-value function!" << endl;
}

void testMoveConstructor()
{
    ValTest test = getValTest();
    vector<ValTest> vec;
    vec.push_back(ValTest());
    vec.push_back(getValTest());
}

void testMoveAssignmentOperator()
{
    ValTest test;
    test = getValTest();
}



void testLvalueRvalue()
{
    ValTest test1 = getValTest();

    int value1 = 7;
    int *pValue1 = &value1;
    //int *pValue2 = &7; // 7 is r value not allowed to get reference
    ValTest *pTest1 = &test1;
    //ValTest *pTest2 = &getTest();//return value is an rvalue, returning object. Not allowed to get reference

    int *pValue3 = &++value1;
    cout << *pValue3 << endl;

    //int *pValue4 = &value1++; // has temporary copy file, not allowed to get reference

    //int *s = &(7 + value1);// rvalue, not allowed to get reference

    ValTest &rTest1 = test1;
    //ValTest &rTest2 = getTest();// rvalue, not allowed to get reference
    const ValTest &rTest2 = getValTest();//allowed, the obj will be there

    ValTest test2(ValTest(1));//ValTest(1)is rvalue but we pass it

    vector<ValTest> vec;
    vec.push_back(ValTest());

    ValTest &lTest1 = test1;
    ValTest &&rtest1 = getValTest();

    check(test1);
    check(getValTest());
    check(ValTest());
    check(rtest1);

    //samples
    /*{

    // declare a, b an object of type 'int'
    int a = 1, b;

    //a + 1 = b; // Error, left expression is
               // is not variable(a + 1)

    // declare pointer variable 'p', and 'q'
    int *p, *q; // *p, *q are lvalue

    *p = 1; // valid l-value assignment

    // below is invalid - "p + 2" is not an l-value
    // p + 2 = 18;

    q = p + 5; // valid - "p + 5" is an r-value

    // Below is valid - dereferencing pointer
    // expression gives an l-value
    *(p + 2) = 18;

    p = &b;

    int arr[20]; // arr[12] is an lvalue; equivalent
                  // to *(arr+12)
                  // Note: arr itself is also an lvalue

    struct S { int m; };

    struct S obj; // obj and obj.m are lvalues

    // ptr-> is an lvalue; equivalent to (*ptr).m
    // Note: ptr and *ptr are also lvalues
    struct S* ptr = &obj;
    }

    {

    // declare a as int variable and
    // 'p' as pointer variable
    int a, *p;

    p = &a; // ok, assignment of address
            // at l-value

    //&a = p;    // error: &a is an r-value

    int x, y;

    (  x < y ? y : x) = 0; // It's valid because the ternary
                      // expression preserves the "lvalue-ness"
                     // of both its possible return values
    }*/
}



#endif // LVALUE_RVALUE_H
