#include <fstream>
#include "bitmap.h"
#include "bitmapinfoheader.h"
#include "bitmapfileheader.h"

using namespace std;

namespace  GP
{

Bitmap::Bitmap(int width, int height)
    : m_width(width),
      m_height(height),
      m_pPixels(new uint8_t[width * height * 3]{})// {} initialize with zero
{

}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
    uint8_t *pPixel = m_pPixels.get(); // i got pointer to unique pointer on memory

    //move forward
    pPixel += (y*3) * m_width + (x*3);

    //little endian file format bmp
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
}

bool Bitmap::write(string filename)
{
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.fileSize = sizeof (BitmapFileHeader) + sizeof (BitmapInfoHeader) + m_width*m_height*3;
    fileHeader.dataOffset = sizeof (BitmapFileHeader) + sizeof (BitmapInfoHeader);//image begin address

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    ofstream file;
    file.open(filename, ios::out|ios::binary);
    if(!file)
    {
        return false;
    }

    file.write((char*)&fileHeader, sizeof (fileHeader));
    file.write((char*)&infoHeader, sizeof (infoHeader));
    file.write((char*)m_pPixels.get(), m_width*m_height*3);//for casting get()

    file.close();
    if(!file)
    {
        return false;
    }

    return true;
}

Bitmap::~Bitmap()
{

}

}
