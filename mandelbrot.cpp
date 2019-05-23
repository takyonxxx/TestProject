#include <complex>
#include "mandelbrot.h"
namespace  GP
{

Mandelbrot::Mandelbrot()
{

}

Mandelbrot::~Mandelbrot()
{

}

int Mandelbrot::getIterations(double x, double y)
{
    complex<double> z = 0;
    complex<double> c(x, y);
    int iterations = 0;

    while(iterations < MAX_ITERATIONS)
    {
        z = z*z + c;

        if(abs(z) > 2)//get magnitude of complex number
        {
            break;
        }

        iterations++;
    }

    return iterations;
}

}
