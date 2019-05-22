#ifndef LAMBDA_H
#define LAMBDA_H
#include "libraries.h"
//Lambda Expressions

void testLambda(void(*pFunc)())
{
    pFunc();
}

void runDivide(double(*divide)(double a, double b))
{
   auto rval = divide(9, 3);
   cout << rval << endl;
}

class lambdaClass
{
    int one{1};
    int two{2};

public:
    void run()
    {
        int three{3};
        int four{4};
        auto pLambda = [&, this]() // we put this for getting one and two by reference
        {
            one = 7;
            cout << one << ", "  << two << ", "  << three << ", " << four << endl;

        };
        pLambda();
    }
};

void lambdaTest()
{
    /*auto lambda = []( int b ){ int r=1; while (b>0) r*=b--; return r; }(5); // 5!

    auto algorithm = [&]( double x, double m, double b ) -> double
    {
        return (m+x)/b;
    };

    auto a1 = algorithm(11,32,3.2), b1 = algorithm(41,55,6.1);
    cout << a1 << " " << b1 << " " << lambda << endl;

    auto lambda1 = [&](auto x, auto y) -> double // if we not put -> double, return 0 will not compile
    {
        if(y == 0.0)
        {
            return 0;
        }
        return x / y;
    };
    cout << lambda1(50.0,6.0) << endl;

    [](){cout << "Hello direct"  << endl;}(); //calling directly

    auto func = [](){cout << "Hello auto"  << endl;}; // kind of functor
    func();

    testLambda(func);

    testLambda([](){cout << "Hello again"  << endl;});

    auto pGreet = [](string name){cout << "Hello " << name << endl;};
    pGreet("Turkay");

    auto pDivide = [](double a, double b) -> double //if we not put -> double, return 0 will not compile
    {
        if(b == 0.0)
        {
            return 0;
        }
        return a/b;
    };

    cout << pDivide(10.0, 5.0) << endl;

    runDivide(pDivide);

    //capture
    int one = 1;
    int two = 2;
    int three = 3;

    //Capture one, two, three by value
    [one, two, three](){cout << "Hello " << one <<  ", " << two << ", " << three << endl;}();

    //Capture all local variables by value
    [=](){cout << "Hello " << one <<  ", " << two << ", " << three << endl;}();

    //Capture all local variables by value, three by reference
    [=, &three]()
    {
        three = 7;
        cout << "Hello " << one <<  ", " << two << ", " << three << endl;
    }();

    //Capture all local variables by reference
    [&]()
    {
        one = 7;
        cout << "Hello " << one <<  ", " << two << ", " << three << endl;
    }();

    //Capture all local variables by reference, one and three by value
    [&, two, three]()
    {
        one = 7;
        //two = 7; error
        cout << "Hello " << one <<  ", " << two << ", " << three << endl;
    }();*/

    lambdaClass lClass;
    lClass.run();

}

#endif // LAMBDA_H
