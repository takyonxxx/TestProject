#ifndef POLYMORPHISM_H
#define POLYMORPHISM_H
#include "libraries.h"
//polymorphism, virtual functions, abstract class

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
