#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H
#include <cstdint>
using namespace std;

#pragma pack(2) // move padding, the struct being packed should not have its members aligned

namespace BMP
{
    struct BitmapFileHeader
    {
        char header[2]{'B', 'M'};
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffset; //how long
    };
}

#endif // BITMAPFILEHEADER_H
