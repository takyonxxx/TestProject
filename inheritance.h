#ifndef INHERITANCE_H
#define INHERITANCE_H
#include "libraries.h"
//we are taking after some kind of properties from other classes
/*The capability of a class to derive properties and characteristics from another class is called Inheritance.
Inheritance is one of the most important feature of Object Oriented Programming.
Sub Class: The class that inherits properties from another class is called Sub class or Derived Class.
Super Class:The class whose properties are inherited by sub class is called Base Class or Super class.*/

class Point //base, parent, super class
{
    
protected: //it will be available for this and inherited class
    int x;
public:   
    Point(int x = 0)
    {
        this->x = x;
        //cout << "The constructor from Point invoked." << endl;
    }
    ~Point()
    {
        //cout << "The destructor from Point invoked." << endl;
    }
    int getX()
    {
        return x;
    }
    void setX(int x)
    {
        this->x = x;
        //cout << "setX : I am from Point" << endl;
    }
};

class Point2D : public Point // derived, child, subclass

        //class Point2D : public Point
        //everything what is inside Point (excluding constructor and desctructor) will be in Point2D
        //private : can not access
        //protected - protected
        //public - public

        //class Point2D : protected Point
        //everything what is inside Point (excluding constructor and desctructor) will be in Point2D
        //private : can not access
        //protected - protected
        //public - protected

        //class Point2D : private Point
        //everything what is inside Point (excluding constructor and desctructor) will be in Point2D
        //private : can not access
        //protected - private
        //public - private
{

protected: //it will be available for this and inherited class
    int y;
public:
    Point2D(int x = 0, int y = 0): Point (x)
    {
        this->y = y;
        //cout << "The constructor from Point2D invoked." << endl;
    }
    ~Point2D()
    {
        //cout << "The destructor from Point2D invoked." << endl;
    }

    Point2D operator+(Point2D o)
    {
        Point2D tmp;
        tmp.setX(this->getX() + o.getX());
        tmp.setY(this->getY() + o.getY());
        return tmp;
    }

    int getY()
    {
        return y;
    }
    void setX(int x)
    {
        this->x = x;
        //cout << "setX : I am from Point2D" << endl;
    }
    void setY(int y)
    {
        this->y = y;
    }
    void setXY(int x, int y)
    {
        setX(x);
        setY(y);
    }
};


#endif // INHERITANCE_H
