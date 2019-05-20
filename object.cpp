#include "object.h"
#include <iostream>
using namespace std;
int Object::counter = 0;

int Object::getCounter()
{
    return counter;
}

Object::Object(int x, int y, int value)
{
    this->x = x;
    this->y = y;
    this->p = new int(value);
    counter++;
    classId = counter;
    cout << "TestClass Constructure has been invoked. Class ID is " << classId << endl;
}

Object::Object(const Object & obj)
{    
    this->x = obj.x;
    this->y = obj.y;
    this->p = new int(*(obj.p));
    counter++;
    classId = counter;
    cout << "TestClass Implicit Constructure has been invoked. Class ID is " << classId << endl;
}

Object::~Object()
{
    delete p;
}

void Object::getPosition() const
{
    cout << "x: " << this->x << endl << "y: " << this->y << endl;
}

 void Object::setPosition(int x, int y)
 {
     this->x = x;
     this->y = y;
 }
