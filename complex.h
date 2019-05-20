#ifndef COMPLEX_H
#define COMPLEX_H
#include "libraries.h"

namespace  turkayProgramming
{
    class Complex
    {
        double real;
        double imaginary;
    public:
        Complex();
        Complex(double real, double imaginary);

        //Copy Costructor:
        Complex(const Complex &other);

        //Assignment operator:
        const Complex &operator=(const Complex &other);

        double getReal() const;
        double getImaginary() const;

        bool operator==(const Complex &other)const;
        bool operator!=(const Complex &other)const;
        Complex operator*()const;
    };

ostream &operator<<(ostream &out, const Complex& c);
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, double d);
Complex operator+(double d, const Complex &c1);
}

#endif // COMPLEX_H
