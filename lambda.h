#ifndef LAMBDA_H
#define LAMBDA_H
#include "libraries.h"

void lambdaTest()
{
    auto lambda = []( int b ){ int r=1; while (b>0) r*=b--; return r; }(5); // 5!

    auto algorithm = [&]( double x, double m, double b ) -> double
    {
        return (m+x)/b;
    };

    auto a1 = algorithm(11,32,3.2), b1 = algorithm(41,55,6.1);
    cout << a1 << " " << b1 << " " << lambda << endl;

    auto lambda1 = [&](auto x, auto y)->double{return x / y;};
    cout << lambda1(50.0,6.0) << endl;
}

#endif // LAMBDA_H
