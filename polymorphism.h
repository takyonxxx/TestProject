#ifndef POLYMORPHISM_H
#define POLYMORPHISM_H
#include "libraries.h"
//polymorphism, virtual functions, abstract class

/*
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


class Animal
{
protected:
    string voice;
public:

    Animal()
    {
        voice = "Default Voice";
    }

    virtual ~Animal() // we should create as virtual for free memory when use delete.
    {
        cout << "I am from the base class" << endl;
    }

    virtual string getVoice() = 0; // we make class abstract class
    //= 0 tells complier this is abstract class.
};

class Dog : public Animal
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
        cout << "I am from the Dog class" << endl;
    }

    string getVoice()
    {
        return voice + " " + sign;
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
        cout << "I am from the Cat class" << endl;
    }

    string getVoice()
    {
        return voice + " " + sign;
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
        cout << "I am from the Cow class" << endl;
    }

    string getVoice()
    {
       return voice + " " + sign;
    }

};

#endif // POLYMORPHISM_H
