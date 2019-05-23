#include "fractal.h"
#include "bitmap.h"
#include "mandelbrot.h"
#include "zoom.h"
#include "zoomlist.h"

using namespace GP;

Fractal::Fractal()
{

}

void Fractal::drawFractal()
{

    int WIDTH = 800;
    int HEIGHT = 600;

    double min = 999999;
    double max = -999999;

    ZoomList zoomlist(WIDTH, HEIGHT);
    zoomlist.add(Zoom(WIDTH/2, HEIGHT/2, 1));

    Bitmap bitmap(WIDTH, HEIGHT);

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
    unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{0});

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            double xFractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            fractal[y * WIDTH + x] = iterations;

            if(iterations != Mandelbrot::MAX_ITERATIONS)
            {
                histogram[iterations]++;
            }
        }
    }

    cout << endl;

    int total = 0;
    for (int i=0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        total += histogram[i];
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = fractal[y * WIDTH + x];
            if(iterations != Mandelbrot::MAX_ITERATIONS)
            {
                double hue = 0;
                for (int i=0; i <= iterations; i++) {
                    hue += ((double)histogram[i]) / total;
                }

                green = pow(255, hue);
                bitmap.setPixel(x, y, red, green, blue);
            }
        }
    }

    bitmap.write("fractal.bmp");

    cout << "Finished." << endl;
}
