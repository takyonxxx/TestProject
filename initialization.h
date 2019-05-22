#ifndef INITIALIZATION_H
#define INITIALIZATION_H
#include "libraries.h"
#include <vector>
#include <initializer_list>

struct{
    string text;
    int id;
}r1 = {"shello", 7}, r2 = {"shello", 8};

class{
public:
    string text;
    int id;
}c1 = {"chello", 7}, c2 = {"chello", 8};

//initializer_list
class iTest
{
public:
    iTest(initializer_list<string> texts)
    {
        for(auto value: texts)
            cout << value << endl;
    }

    void print(initializer_list<string> texts)
    {
        for(auto value: texts)
            cout << value << endl;
    }

};

class Test2
{
    int id{3};
    string name {"Turkay"};
public:
    Test2() = default;
    Test2(const Test2 &other) = default;//copy constructor if i make it delete,  Test2 test4 = test3; will not compile
    Test2 &operator=(const Test2 &other) = default;//if make delete test3 = test2; will not compile

    Test2(int id): id(id)//lose implicit constructor, we need to define default
    {

    }

    void print()
    {
        cout << id << ": " << name << endl;
    }

};

void testInitialization()
{
    //c98
    cout << r1.text << endl;
    cout << r2.text << endl;
    cout << c1.text << endl;
    cout << c2.text << endl;

    //c11 features
    int value{5};
    cout << value << endl;

    int value1{};//defaul value 0
    cout << value1 << endl;

    string text{"Hello"};
    cout << text << endl;

    int numbers[]{1, 2, 3};
    cout << numbers[1] << endl;

    int *pInts = new int[3]{1, 2,3};
    cout << pInts[1] << endl;
    delete [] pInts;

    int *pSomething{};// equivalent to int *pSomething1 = nullptr
    cout << pSomething << endl;

    int numbers1[5]{};
    cout << numbers1[1] << endl;

    vector<string> strings {"one", "two", "three"};
    for(auto item: strings)
        cout << item << endl;

    iTest test{"turkay", "alya", "gokhan", "muteber"};
    test.print({"one", "two", "three", "four"});

    Test2 test2;
    test2.print();

    Test2 test3(77);
    test3.print();

    Test2 test4 = test3;
    test3 = test2;
    test4.print();
}


#endif // INITIALIZATION_H
