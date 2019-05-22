#ifndef POINTERS_H
#define POINTERS_H
#include "libraries.h"
#include <algorithm>
#include <vector>
#include <memory>//unique_ptr
/*
auto_ptr, unique_ptr, shared_ptr and weak_ptr
Prerequisite – Smart Pointers
C++ libraries provide implementations of smart pointers in following types:

auto_ptr : depricated
unique_ptr
shared_ptr
weak_ptr
They all are declared in memory header file.

auto_ptr

This class template is deprecated as of C++11. unique_ptr is a
new facility with a similar functionality, but with improved security.
auto_ptr is a smart pointer that manages an object obtained via
new expression and deletes that object when auto_ptr itself is destroyed.
An object when described using auto_ptr class it stores a pointer to a
single allocated object which ensures that when it goes out of scope,
the object it points to must get automatically destroyed.
It is based on exclusive ownership model i.e.
two pointers of same type can’t point to the same resource at the same time.

Using smart pointers, we can make pointers to work in way that we don’t need to explicitly call delete.
Smart pointer is a wrapper class over a pointer with operator like * and -> overloaded.
The objects of smart pointer class look like pointer, but can do many things
that a normal pointer can’t like automatic destruction (yes, we don’t have to explicitly use delete), reference counting and more.
The idea is to make a class with a pointer, destructor and overloaded operators like * and ->.
Since destructor is automatically called when an object goes out of scope,
the dynamically allocated memory would automatically deleted (or reference count can be decremented).

When to use unique_ptr?
Use unique_ptr when you want to have single ownership(Exclusive) of resource.
Only one unique_ptr can point to one resource. Since there can be one unique_ptr
for single resource its not possible to copy one unique_ptr to another.

shared_ptr

A shared_ptr is a container for raw pointers.
It is a reference counting ownership model i.e. it maintains the reference count of its contained pointer
in cooperation with all copies of the shared_ptr. So, the counter is incremented each time a new pointer
points to the resource and decremented when destructor of object is called.

When to use shared_ptr?
Use shared_ptr if you want to share ownership of resource .
Many shared_ptr can point to single resource. shared_ptr maintains reference count for this propose.
when all shared_ptr’s pointing to resource goes out of scope the resource is destroyed.

weak_ptr

A weak_ptr is created as a copy of shared_ptr.
It provides access to an object that is owned by one or more shared_ptr instances,
but does not participate in reference counting. The existence or destruction of weak_ptr
has no effect on the shared_ptr or its other copies. It is required in some cases
to break circular references between shared_ptr instances.
*/
class PoTest
{
public:
    PoTest()
    {
        cout << "created" << endl;
    }

    void greet()
    {
        cout << "Hello" << endl;
    }

    ~PoTest()
    {
        cout << "destroyed" << endl;
    }
};

class Temp
{
    unique_ptr<PoTest[]> pTest;

public:
    Temp():pTest(new PoTest[2]){}
};

class A1
{
public:
    void show()
    {
        cout<<"A::show()"<<endl;
    }
};

//function pointers
void pointerFunction(int value)
{
    cout << "This function pointer: " << value << endl;
}

bool match(string test)
{
    return test.size() == 3;
}

int countStrings(vector<string> &texts, bool (*match)(string test))
{
    int tally = 0;
    for(int i=0; i<texts.size(); i++)
    {
        if(match(texts[i])){
            tally++;
        }
    }

    return tally;
}

void testPointers()
{
    void (*pTest)(int) = pointerFunction;
    //(*pTest)();
    pTest(5);

    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("four");
    texts.push_back("two");
    texts.push_back("three");

    cout << count_if(texts.begin(), texts.end(), match) << endl;
    cout << countStrings(texts, match) << endl;
}

void testUniquePointer()
{
    /*unique_ptr<int> pTest(new int);
    *pTest = 7;
    cout << *pTest << endl;*/

    unique_ptr<PoTest> pTest(new PoTest); // clean memory when variable goes out scope
    pTest->greet();

    {
        unique_ptr<PoTest[]> pTest2(new PoTest[2]); // clean memory when variable goes out scope
        pTest2[1].greet();
    }

    Temp temp;

    //////////////////

    unique_ptr<A1> p1 (new A1);
    p1 -> show();

    // returns the memory address of p1
    cout << p1.get() << endl;

    // transfers ownership to p2
    unique_ptr<A1> p2 = move(p1);
    p2 -> show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;

    // transfers ownership to p3
    unique_ptr<A1> p3 = move (p2);
    p3->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p3.get() << endl;

    /////////////////


    cout << "finished" << endl;
}

class SmartPtr1
{
    int *ptr;  // Actual pointer
public:
    // Constructor: Refer https://www.geeksforgeeks.org/g-fact-93/
    // for use of explicit keyword
    explicit SmartPtr1(int *p = nullptr) { ptr = p; cout << "created" << endl;}

    // Destructor
    ~SmartPtr1() { delete(ptr); cout << "destroyed" << endl;}

    // Overloading dereferencing operator
    int &operator *() {  return *ptr; }
};

// A generic smart pointer class
template <class T>
class SmartPtr
{
    T *ptr;  // Actual pointer
public:
    // Constructor
    explicit SmartPtr(T *p = nullptr) { ptr = p; cout << "created" << endl;}

    // Destructor
    ~SmartPtr() { delete(ptr); cout << "destroyed" << endl;}

    // Overloading dereferncing operator
    T & operator * () {  return *ptr; }

    // Overloding arrow operator so that members of T can be accessed
    // like a pointer (useful if T represents a class or struct or
    // union type)
    T * operator -> () { return ptr; }
};

void testSmartPointer()
{
    PoTest *ptrt = new PoTest();
    ptrt->greet();
    //  We must do delete(ptr) to avoid memory leak
    delete ptrt;

    SmartPtr1 ptr1(new int());
    *ptr1 = 20;
    cout << *ptr1 << endl;

    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr << endl;

    // We don't need to call delete ptr: when the object
    // ptr goes out of scope, destructor for it is automatically
    // called and destructor does delete ptr.

}

void testSharedPointer()
{
    shared_ptr<PoTest> pTest2(nullptr);
    {
        shared_ptr<PoTest> pTest1 = make_shared<PoTest>();
        pTest2 = pTest1;

        auto pTest3 = pTest1;
    }

    shared_ptr<A1> p1 = make_shared<A1>();
    cout << p1.get() << endl;
    p1->show();
    shared_ptr<A1> p2 (p1);
    p2->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;

    // Returns the number of shared_ptr objects
    //referring to the same managed object.
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;

    // Relinquishes ownership of p1 on the object
    //and pointer becomes NULL
    p1.reset();
    cout << p1.get() << endl;
    cout << p2.use_count() << endl;
    cout << p2.get() << endl;

    cout << "finished" << endl;
}

#endif // POINTERS_H
