#ifndef BITMAP_H
#define BITMAP_H
#include "iostream"
#include "string"
#include <cstdint>
#include <memory>
using namespace std;

namespace GP
{

class Bitmap
{
    int m_width{0};
    int m_height{0};
    unique_ptr<uint8_t[]> m_pPixels{nullptr};

public:
    Bitmap(int width, int height);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    bool write(string filename);
    void createFractal();
    virtual ~Bitmap();
};
}



#endif // FRACTAL_H
