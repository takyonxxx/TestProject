#include "testclass.h"
#include <iostream>
using namespace std;
int TestClass::counter = 0;

int TestClass::getCounter()
{
    return counter;
}

TestClass::TestClass(int x, int y, int value)
{
    this->x = x;
    this->y = y;
    this->p = new int(value);
    counter++;
    classId = counter;
    cout << "TestClass Constructure has been invoked. Class ID is " << classId << endl;
}

TestClass::TestClass(const TestClass & obj)
{    
    this->x = obj.x;
    this->y = obj.y;
    this->p = new int(*(obj.p));
    counter++;
    classId = counter;
    cout << "TestClass Implicit Constructure has been invoked. Class ID is " << classId << endl;
}

TestClass::~TestClass()
{
    delete p;
}

void TestClass::getPosition() const
{
    cout << "x: " << this->x << endl << "y: " << this->y << endl;
}

 void TestClass::setPosition(int x, int y)
 {
     this->x = x;
     this->y = y;
 }
