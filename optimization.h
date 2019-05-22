#ifndef OPTIMIZATION_H
#define OPTIMIZATION_H
#include "libraries.h"
#include <vector>
#include <memory>
/*In C++ computer programming, copy elision refers to a compiler optimization
technique that eliminates unnecessary copying of objects.

Return value optimization (RVO) is a compiler optimization that involves
eliminating the temporary object created to hold a function’s return value.
*/

class TestOP
{
    static const int SIZE = 100;
    int *_pBuffer;
public:
    TestOP(){
        cout << "constructor" << endl;
        _pBuffer = new int[SIZE]{};
        //memset(_pBuffer, 0, sizeof (int)*SIZE); we use {} instead of memset
    }

    TestOP(int i){
        cout << "parameterized constructor" << endl;
        _pBuffer = new int[SIZE]{};

        for (int i=0;i < SIZE; i++) {
            _pBuffer[i] = 7*i;
        }
    }

    TestOP(const TestOP &other){
        cout << "copy constructor" << endl;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof (int));
    }

    TestOP &operator=(const TestOP &other){
        cout << "assignment" << endl;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof (int));
        return *this;
    }

    ~TestOP(){
        cout << "destructor" << endl;
        delete [] _pBuffer;
    }

    friend ostream &operator<<(ostream &out, const TestOP &test);
};

ostream &operator<<(ostream &out, const TestOP &test)
{
    out << "Hello from TestOP";
    return out;
}

//when you see this kind of method, know that it is not efficient, compiler will optimize it
TestOP getTestOP()
{
    return TestOP();
}

void testOptimization()
{
    TestOP test1 = getTestOP();
    cout << test1 << endl;

    //vector<TestOP> vec;
    //vec.push_back(TestOP()); // it is not efficient

}

#endif // OPTIMIZATION_H
