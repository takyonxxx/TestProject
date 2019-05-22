#ifndef COSTRUCTORS_H
#define COSTRUCTORS_H
#include "libraries.h"

class TestConstructorClass
{
    int id;
    string name;

public:

    /*if you want to imlement default
    TestConstructorClass() = default;
    TestConstructorClass(const TestConstructorClass &other) = default; // Test2 test2 = test1;
    TestConstructorClass &operator=(const TestConstructorClass &other) = default; // test2 = test1;

    if you want to disable constructor delete
    TestConstructorClass() = delete;
    TestConstructorClass(const TestConstructorClass &other) = delete;
    TestConstructorClass &operator=(const TestConstructorClass &other) = delete;
    */

    TestConstructorClass(): id(0), name(""){}

    TestConstructorClass(int id, string name): id(id), name(name)
    {
    }

    void print() const
    {
        cout << id << ": " << name << endl;
    }

    //Assignment operator;
    const TestConstructorClass &operator=(const TestConstructorClass &other)// test2 = test1;
    {
        cout << "Assignment running" << endl;
        id = other.id;
        name = other.name;
        return *this;
    }

    //Copy Costructor
    TestConstructorClass(const TestConstructorClass &other) // Test2 test2 = test1;
    {
        cout << "Copy costructor running" << endl;
        id = other.id;
        name = other.name;
        *this = other;
    }

    //allow access private methods
    friend ostream &operator<<(ostream &out, const TestConstructorClass &test)
    {
        out << test.id << ": " << test.name;
        return  out;
    }

};

//example constructors

class ExampleClass
{
    static const int SIZE = 100;
    int *_pBuffer{nullptr};
public:
    ExampleClass(){
        cout << "constructor" << endl;
        _pBuffer = new int[SIZE]{};
        //memset(_pBuffer, 0, sizeof (int)*SIZE); we use {} instead of memset
    }

    ExampleClass(int i){
        cout << "parameterized constructor" << endl;
        _pBuffer = new int[SIZE]{};

        for (int i=0;i < SIZE; i++) {
            _pBuffer[i] = 7*i;
        }
    }

    ExampleClass(const ExampleClass &other){
        cout << "copy constructor" << endl;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof (int));
    }

    //move constructor
    ExampleClass(ExampleClass &&other)
    {
        cout << "move constructor" << endl;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;
    }

    ExampleClass &operator=(const ExampleClass &other){
        cout << "assignment" << endl;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof (int));
        return *this;
    }

    ExampleClass &operator=(ExampleClass &&other){
        cout << "move assignment" << endl;
        delete [] _pBuffer;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;
        return *this;
    }

    ~ExampleClass(){
        cout << "destructor" << endl;
        delete [] _pBuffer;
    }

    friend ostream &operator<<(ostream &out, const ExampleClass &test);
};

ostream &operator<<(ostream &out, const ExampleClass &test)
{
    out << "Hello from ExampleClass";
    return out;
}


#endif // COSTRUCTORS_H
