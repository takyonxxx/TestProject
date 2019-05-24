
#include <iostream>
#include "fractal.h"
#include "Fractal/FractalCreator.h"
#include "Fractal/RGB.h"
#include "Fractal/Zoom.h"

using namespace std;
using namespace GP;

Fractal::Fractal()
{

}

void Fractal::drawFractal()
{
    FractalCreator fractalCreator(800, 600);

    fractalCreator.addRange(0.0, RGB(0, 0, 255));
    fractalCreator.addRange(0.05, RGB(255, 99, 71));
    fractalCreator.addRange(0.08, RGB(255, 215, 0));
    fractalCreator.addRange(1.0, RGB(255, 255, 255));

    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));
    fractalCreator.run("fractal.bmp");

    cout << "Finished." << endl;
}
