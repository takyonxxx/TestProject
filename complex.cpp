#include "complex.h"
namespace turkayProgramming
{
    /////Overloaded Operators/////

    ostream &operator<<(ostream &out, const Complex& c)
    {
        out << "(" << c.getReal() << "," << c.getImaginary() << ")";
        return out;
    }

    Complex operator+(const Complex &c1, const Complex &c2)
    {
        return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
    }

    Complex operator+(const Complex &c1, double d)
    {
         return Complex(c1.getReal() + d, c1.getImaginary());
    }

    Complex operator+(double d, const Complex &c1)
    {
         return Complex(c1.getReal() + d, c1.getImaginary());
    }

    /////Complex//////
    Complex::Complex()
        : real(0), imaginary(0)
    {
    }

    Complex::Complex(double real, double imaginary)
        : real(real), imaginary(imaginary)
    {
    }

    Complex::Complex(const Complex &other)
    {
        //cout << "Copy" << endl;
        real = other.real;
        imaginary = other.imaginary;
        *this = other;
    }

    const Complex &Complex::operator=(const Complex &other)
    {
        //cout << "Assignment" << endl;
        real = other.real;
        imaginary = other.imaginary;
        return *this;
    }

    bool Complex::operator==(const Complex &other)const
    {
        return (real == other.real) && (imaginary == other.imaginary);
    }

    bool Complex::operator!=(const Complex &other)const
    {
        //return (real != other.real) || (imaginary != other.imaginary);
        return !(*this == other);
    }

     //Dereference operator
     Complex Complex::operator*()const
     {
         return Complex(real, -imaginary);
     }

    double Complex::getReal() const
    {
        return real;
    }

    double Complex::getImaginary() const
    {
        return imaginary;
    }
}
