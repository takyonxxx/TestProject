#ifndef FUNCTORS_H
#define FUNCTORS_H
#include "libraries.h"

/*Please note that the title is Functors (Not Functions)!!
Consider a function that takes only one argument. However,
while calling this function we have a lot more information that we would like to pass to this function,
but we cannot as it accepts only one parameter. What can be done?
One obvious answer might be global variables. However,
good coding practices do not advocate the use of global variables
and say they must be used only when there is no other alternative.

Functors are objects that can be treated as though they are a function or function pointer.
Functors are most commonly used along with STLs in a scenario like following:
Below program uses transform() in STL to add 1 to all elements of arr[].
*/
//int increment(int x) {  return (x+1); }

//Alternative to function pointers;
// A Functor
class increment
{
private:
    int num;
public:
    increment(int n) : num(n) {  }

    // This operator overloading enables calling
    // operator function () on objects of increment
    int operator () (int arr_num) const {
        return num + arr_num;
    }
};

void increament()
{
    int arr[] = {1, 2, 3, 4, 5};
        int n = sizeof(arr)/sizeof(arr[0]);
        int to_add = 5;

        transform(arr, arr+n, arr, increment(to_add));

        for (int i=0; i<n; i++)
            cout << arr[i] << " ";

}

struct BaseTest
{
    virtual bool operator()(string &text)=0;
    virtual ~BaseTest(){}
};

//functor overloads () brackets operator
struct MatchTest: public BaseTest
{
    virtual bool operator()(string &text){
        return text == "lion";
    }

};

void check(string text, BaseTest &test)
{
    if(test(text))
    {
        cout << "Test matches!" << endl;
    }
    else {
        cout << "Not match!" << endl;
    }

}

void testFunctors()
{
    //increament();

    MatchTest pred;
    string value = "lion";
    cout << pred(value) << endl;

    MatchTest m;
    check("lion", m);

}

#endif // FUNCTORS_H
