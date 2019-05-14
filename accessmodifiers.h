#ifndef ACCESSMODIFIERS_H
#define ACCESSMODIFIERS_H
#include "libraries.h"

/*Access modifiers are used to implement an important feature of Object Oriented Programming known as Data Hiding.
Consider a real-life example: Consider Indian secret informatic system having 10 senior members,
have some top secret regarding national security. So we can think that 10 people as class data members
or member functions who can directly access secret information from each other but anyone can’t access this information
other than these 10 members i.e. outside people can’t access information directly without having any privileges.
This is what data hiding is.
Access modifiers or Access Specifiers in a class are used to set the accessibility of the class members.
That is, it sets some restrictions on the class members not to get directly accessed by the outside functions.

There are 3 types of access modifiers available in C++:

Public    : All the class members declared under public will be available to everyone.
Private   : The class members declared as private can be accessed only by the functions inside the class.
Protected : Protected access modifier is similar to that of private access modifiers,
the difference is that the class member declared as Protected are
inaccessible outside the class but they can be accessed by any subclass(derived class) of that class.
*/

// C++ program to demonstrate public
// access modifier

// class definition
class Circle_Public
{
public:
    double radius;

    double  compute_area()
    {
        cout << "Circle_Public:" << endl;
        return 3.14*radius*radius;
    }

};


// C++ program to demonstrate private
// access modifier

class Circle_Private
{
    // private data member
private:
    double radius;

    // public member function
public:
    void compute_area(double r)
    {   // member function can access private
        // data member radius
        radius = r;

        double area = 3.14*radius*radius;

        cout << "Circle_Private:" << endl;
        cout << "Radius is:" << radius << endl;
        cout << "Area is: " << area << endl;
    }

};


// C++ program to demonstrate
// protected access modifier


// base class
class Parent
{
    // protected data members
protected:
    int id_protected;

};

// sub class or derived class
class Child : public Parent
{


public:
    void setId(int id)
    {

        // Child class is able to access the inherited
        // protected data members of base class

        id_protected = id;
    }

    void displayId()
    {
        cout << "id_protected is:" << id_protected << endl;
    }
};


#endif // ACCESSMODIFIERS_H
