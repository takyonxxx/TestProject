#ifndef TEMPLATE_H
#define TEMPLATE_H
#include "libraries.h"

template <typename T>
T Average(T *atArray, int nNumValues)
{
    T tSum = 0;
    for (int nCount=0; nCount < nNumValues; nCount++)
        tSum += atArray[nCount];

    tSum /= nNumValues;
    return tSum;
}

template  <typename T>
T GetMaxValue(T* atArray, int size)
{
    T tMax = atArray[0];
    for (int nCount=0; nCount < size; nCount++)
    {
        if(atArray[nCount] > tMax)
            tMax = atArray[nCount];
    }

    return tMax;
}

template<typename T>
T Average( std::vector<T> const& vec , int nNumValues)
{
    T tSum = 0;
    for (int nCount=0; nCount < nNumValues; nCount++)
        tSum += vec[nCount];

    tSum /= nNumValues;
    return tSum;
}
#endif // TEMPLATE_H
