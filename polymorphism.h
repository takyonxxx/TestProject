#ifndef POLYMORPHISM_H
#define POLYMORPHISM_H
#include "libraries.h"
//polymorphism, virtual functions, abstract class

/*
Polymorphism means : our complier knows which of morphs could invoke,
Another word the condition of occurring in several different forms.
The word polymorphism means having many forms.
In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form.
Real life example of polymorphism, a person at a same time can have different characteristic.
Like a man at a same time is a father, a husband, a employee.
So a same person posses have different behavior in different situations. This is called polymorphism.
Polymorphism is considered as one of the important features of Object Oriented Programming.

In C++ polymorphism is mainly divided into two types:
Compile time Polymorphism
Runtime Polymorphism
Compile time polymorphism: This type of polymorphism is achieved by function overloading or operator overloading.
Runtime polymorphism: This type of polymorphism is achieved by Function Overriding.
*/

//object slicing, up casting
class Parent
{
    int one;
public:

    Parent():one(0){}

    Parent(const Parent& other):one(0)//copy constructor, when we define this
    //we lose implicit no parmeter constructor so should define default constructor..
    {
        one = other.one;
        cout << "Parent copy constructor" << endl;
    }

    virtual ~Parent(){}

    virtual void print()
    {
        cout << "parent" << endl;
    }

};


class Child : public Parent
{
    int two;
public:

    Child():two(0)//we cant initialize one
    {
    }

    ~Child(){}

    void print()
    {
        cout << "child" << endl;
    }
};


class Animal
{
protected:
    string voice;
public:

    //Animal(){}we cant run constructor, its abstract class

    virtual ~Animal() // we should create as virtual for free memory when use delete.
    {
        cout << "Deconstructor I am from the base class Animal" << endl;
    }
    virtual void run() = 0;
    virtual string getVoice() = 0; // a pure virtual function, we make class abstract class
    //= 0 tells complier this is abstract class.
};

class Dog : public Animal //Abstrac class, run() not implemented
{
    string sign;
public:
    Dog()
    {
        sign = "D";
        voice = "hau hau hau";
    }
    ~Dog()
    {
        cout << "Deconstructor I am from the Dog class" << endl;
    }

    virtual string getVoice()
    {
        return voice + " " + sign;
    }

};

class Labrador : public Dog
{
public:
    virtual void run()
    {
        cout << "Labrador is running" << endl;
    }
};

class Cat : public Animal
{
    string sign;
public:
    Cat()
    {
        sign = "C";
        voice = "meow";
    }    
    ~Cat()
    {
        cout << "Deconstructor I am from the Cat class" << endl;
    }

    virtual string getVoice()
    {
        return voice + " " + sign;
    }

    virtual void run()
    {
        cout << "Cat is running" << endl;
    }

};

class Cow : public Animal
{
    string sign;
public:
    Cow()
    {
        sign = "CO";
        voice = "mooo";
    }
    ~Cow()
    {
        cout << "Deconstructor I am from the Cow class" << endl;
    }

    virtual string getVoice()
    {
       return voice + " " + sign;
    }

    virtual void run()
    {
        cout << "Cow is running" << endl;
    }

};

void testAnimal(Animal &a)
{
    a.run();
}



#endif // POLYMORPHISM_H
