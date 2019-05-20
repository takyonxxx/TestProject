#ifndef OVERLOAD_H
#define OVERLOAD_H
#include "libraries.h"

int power(int input, int e)
{
    int tmp = input;

    while(e-- > 1)
    {
        input *= tmp;
    }

    return input;
}

double power(double input, int e)
{
    double tmp = input;

    while(e-- >1)
    {
        input *= tmp;
    }

    return input;
}

class PointF
{
private:
    int x, y;
public:
    PointF(int i = 0, int j = 0) {
        x = i;   y = j;
    }
    void print() {
        cout << endl << " x = " << x << ", y = " << y << endl;
    }
};

class Fraction
{
    int num, den;
public:
    Fraction(int n,  int d) { num = n; den = d; }

    // conversion operator: return float value of fraction
    operator float() const {
        return float(num) / float(den);
    }
};

class Complex1 {
private:
    int real, imag;
public:
    Complex1(int r = 0, int i =0)  {real = r;   imag = i;}

    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex1 operator + (Complex1 const &obj) {
         Complex1 res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    void print() { cout << real << " + i" << imag << endl; }
};

#endif // OVERLOAD_H
