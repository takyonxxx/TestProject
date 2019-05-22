#ifndef CASTING_H
#define CASTING_H
#include "libraries.h"
//Type Casting operators
/*
static_cast is the first cast you should attempt to use.
It does things like implicit conversions between types (such as int to float, or pointer to void*),
and it can also call explicit conversion functions (or implicit ones).
In many cases, explicitly stating static_cast isn't necessary,
but it's important to note that the T(something) syntax is equivalent to (T)something and should be avoided (more on that later).
A T(something, something_else) is safe, however, and guaranteed to call the constructor.
static_cast can also cast through inheritance hierarchies.
It is unnecessary when casting upwards (towards a base class),
but when casting downwards it can be used as long as it doesn't cast through virtual inheritance.
It does not do checking, however, and it is undefined behavior to static_cast down
a hierarchy to a type that isn't actually the type of the object.

const_cast can be used to remove or add const to a variable;
no other C++ cast is capable of removing it (not even reinterpret_cast).
It is important to note that modifying a formerly const value is only undefined if the original variable is const;
if you use it to take the const off a reference to something that wasn't declared with const, it is safe.
This can be useful when overloading member functions based on const, for instance.
It can also be used to add const to an object, such as to call a member function overload.
const_cast also works similarly on volatile, though that's less common.

dynamic_cast is exclusively used for handling polymorphism.
You can cast a pointer or reference to any polymorphic type to any other class type
(a polymorphic type has at least one virtual function, declared or inherited).
You can use it for more than just casting downwards – you can cast sideways or even up another chain.
The dynamic_cast will seek out the desired object and return it if possible.
If it can't, it will return nullptr in the case of a pointer, or throw std::bad_cast in the case of a reference.
dynamic_cast has some limitations, though.
It doesn't work if there are multiple objects of the same type
in the inheritance hierarchy (the so-called 'dreaded diamond') and you aren't using virtual inheritance.
It also can only go through public inheritance - it will always fail to travel through protected or private inheritance.
This is rarely an issue, however, as such forms of inheritance are rare.

reinterpret_cast is the most dangerous cast,
and should be used very sparingly.
It turns one type directly into another — such as casting the value from one pointer to another,
or storing a pointer in an int, or all sorts of other nasty things.
Largely, the only guarantee you get with reinterpret_cast is that normally if you cast the result back to the original type,
you will get the exact same value (but not if the intermediate type is smaller than the original type).
There are a number of conversions that reinterpret_cast cannot do, too.
It's used primarily for particularly weird conversions and bit manipulations,
like turning a raw data stream into actual data, or storing data in the low bits of an aligned pointer.

C-style cast and function-style cast are casts using (type)object or type(object),
respectively, and are functionally equivalent. They are defined as the first of the following which succeeds:
C-style casts also ignore access control when performing a static_cast,
which means that they have the ability to perform an operation that no other cast can.
This is mostly a kludge, though, and in my mind is just another reason to avoid C-style casts.

//////
reinterpret_cast:
It is used to convert one pointer of another pointer of any type, no matter either the class is related to each other or not.
It does not check if the pointer type and data pointed by the pointer is same or not.
It doesn’t have any return type. It simply converts the pointer type.*/
void reinterpret_cast_test()
{
    int* p = new int(65);
    char* ch = reinterpret_cast<char*>(p);
    cout << "reinterpret_cast : " << ch << endl; // A
}

/*
static_cast:
A Cast operator is an unary operator which forces one data type to be converted into another data type.
This is the simplest type of cast which can be used.
It is a compile time cast.It does things like implicit conversions between types
(such as int to float, or pointer to void*), and it can also call explicit conversion functions (or implicit ones).
*/

class Base {
public:
    virtual void speak()
    {
        cout << "I am parent class." << endl;
    }
};
class Derived : public Base { // Inherited private/protected not public
};

class Brother : public Base { // Inherited private/protected not public
};

class Sister : public Base { // Inherited private/protected not public
};

//compile time
void static_cast_test()
{
    float f = 3.5;
    int a = f; // this is how you do in C
    int b = static_cast<int>(f);
    cout << "static_cast : " << b << endl;

    Derived d1;
    Base* b1 = (Base*)(&d1); // allowed
    Base* b2 = static_cast<Base*>(&d1);
    if(b2)
        cout << "static_cast success" << endl;
    else
        cout << "static_cast failed" << endl;

}

/*
dynamic_cast:
If the cast is successful, dynamic_cast returns a value of type new_type.
If the cast fails and new_type is a pointer type, it returns a null pointer of that type.
If the cast fails and new_type is a reference type, it throws an exception that matches a handler of type std::bad_cast.

dynamic_cast has runtime type checking and only works with references and pointers,
whereas static_cast does not offer runtime type checking. ...
dynamic_cast only supports pointer and reference types.
It returns NULL if the cast is impossible if the type is a pointer or throws an exception if the type is a reference type.
*/

//runtime
void dynamic_cast_test()
{
    Derived *child = new Derived();
    Base  *base = dynamic_cast<Base*>(child); // ok

    if(base)
        cout << "dynamic_cast success" << endl;
    else
        cout << "dynamic_cast failed" << endl;
}

void testCasting()
{
    Base parent;
    Brother brother;
    Sister sister;

    //static_cast
    {
        //this is dangereous, static_cast is just a compile time thing, code work but danger
        Base *ppb = &brother;
        //Brother *ppb1 = ppb;//error
        Brother *pbb = static_cast<Brother*>(ppb);

        Base &&p = Base();
        //Base &&p1 = parent;//error

        Base &&p1 = static_cast<Base&&>(parent);//safe
        p1.speak();

        Sister *pss = static_cast<Sister *>(ppb);// return adress
        if(pss)
            cout << pss << endl;
        else
            cout << "static_cast failed" << endl;
    }

    //dynamic_cast
    {
        Base *ppb = &parent;
        Brother *pbb = dynamic_cast<Brother *>(ppb);// return nullptr
        if(pbb)
            cout << pbb << endl;
        else
            cout << "dynamic_cast failed" << endl;

        Base *ppb1 = &brother;
        Brother *pbb1 = dynamic_cast<Brother *>(ppb1);// return pointer, cast success
        if(pbb1)
            cout << pbb1 << endl;
        else
            cout << "dynamic_cast failed" << endl;

    }

    //reinterpret_cast
    {
        Base *ppb = &brother;
        Sister *pss = static_cast<Sister *>(ppb);// return adress
        if(pss)
            cout << pss << endl;
        else
            cout << "reinterpret_cast failed" << endl;
    }

    cout << endl << "For same comparison" << endl;

    Base *ppb = &brother;

    Sister *pss1 = static_cast<Sister *>(ppb);// return adress
    if(pss1)
        cout << "static_cast : " << pss1 << endl;
    else
        cout << "static_cast failed" << endl;

    Sister *pss2 = reinterpret_cast<Sister *>(ppb);// return adress
    if(pss2)
        cout << "reinterpret_cast : " << pss2 << endl;
    else
        cout << "reinterpret_cast failed" << endl;

    //this gives true result.
    Sister *pss3 = dynamic_cast<Sister *>(ppb);// return adress
    if(pss3)
        cout << "dynamic_cast : " << pss3 << endl;
    else
        cout << "dynamic_cast failed" << endl;

}


#endif // CASTING_H
