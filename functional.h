#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H
#include "libraries.h"
#include <functional>
#include <vector>
#include <algorithm>

/*template< class R, class... Args >
class function<R(Args...)>;*/

/*Why use Functional Programming?
In a world of multi core CPU(s) where the program runs in parallel,
a functional program can safely execute of multiple CPU(s)
with worrying about excessive locking because it doesn’t use or modify any global resources.
*/

template<int iValue, int jValue>
struct AbcTest {
  int i = iValue;
  int j = jValue;
  int sumFn() {
      return [this](){
          return this->i + this->j;
      }();
  }
};

bool check1(string &test)
{
    return test.size() == 3;
}

class Check
{
public:
    bool operator()(string &test)
    {
        return test.size() == 5;
    }
}check2;

void run(function<bool(string&)> check)
{
    string test = "stars";
    cout << test << ", " << check(test) << endl;
}

void testFunctional()
{
    vector<string> vec{"one", "two", "three"};

    int size = 3;

    auto count = count_if(vec.begin(), vec.end(),[size](string test){return test.size() == size;});
    cout << count << endl;

    count = count_if(vec.begin(), vec.end(), check1);
    cout << count << endl;

    count = count_if(vec.begin(), vec.end(), check2);
    cout << count << endl;

    auto lambda = [size](string test){return test.size() == size;};

    run(lambda);
    run(check1);
    run(check2);

    //Functional

    // Getting the function reference using function<>
    function<int(int)> lambdaFn1 = [](int value)->int
    {
        cout<<"Hello World1"<<endl;
        return value + 1;
    };
    // Calling the lambda function here
    int retLambda1 = lambdaFn1(100);
    cout << retLambda1 << endl;

    // We can also use auto instead as while taking the function reference
    auto lambdaFn2 = [](int value)->int{
        cout<<"Hello World2"<<endl;
        return value + 1;
    };

    // Calling the lambda function here
    int retLambda2 = lambdaFn2(100);
    cout << retLambda2 << endl;

    function<int(int, int)> add = [](int one, int two){return one + two;};
    cout << add(5,5) << endl;


    // f(x) = x * x
    function<int(int)> fxsquare1 = [](int x) ->int {
        return x * x;
    };
    int retValue1 = fxsquare1(10);
    cout << retValue1 << endl;

    //f(x,y)2 = x2 + y2 + 2xy
    function<int(int, int)> fxsquare2 = [](int x, int y) ->int {
        int xsquare = [](int x) { return x * x; }(x);
        int ysquare = [](int y) { return y * y; }(y);
        int twoxy = [](int x, int y) { return 2 * x * y;}(x,y);
        return xsquare + ysquare + twoxy;
    };
    int retValue2 = fxsquare2(5,3);
    cout << retValue2 << endl;

    // Using class
    AbcTest<100,200> aTest;
    int sum = aTest.sumFn();
    cout << sum << endl;

    //mutable
    int cats = 5;
    [cats]() mutable
    {
        cats = 8; //error if not put mutable
        cout << " cats: " <<  cats << endl;
    }();

}

#endif // FUNCTIONAL_H
