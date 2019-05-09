/*
Preprocessor Directives:

Macro	Syntax: #define
This macro defines constant value and can be any of the basic data types.
Header file inclusion	Syntax: #include <file_name>
The source code of the file “file_name” is included in the main program at the specified place.
Conditional compilation	Syntax: #ifdef, #endif, #if, #else, #ifndef
Set of commands are included or excluded in source program before compilation with respect to the condition.
Other directives	Syntax: #undef, #pragma
#undef is used to undefine a defined macro variable. #Pragma is used to call a function before and after main function in a C program.
*/

#include "racingexample.h"
#include "singleton.h"
#include "chainofresponsibility.h"
#include "command.h"
#include "interpreter.h"
#include "iterator.h"
#include "overloadfunction.h"
#include "exceptions.h"
#include "passvalue.h"
#include "overloadoperator.h"
#include "overloadfunction.h"
#include "enumaration.h"
#include "template.h"

//MVC Model-View-Controller
#include "view.h"
#include "model.h"
#include "controller.h"
#include "common.h"


void showHelp()
{
    cout << "This is help function." << endl;
}

void DataChange(string data) {
    cout << "Data Changes: " << data <<endl;
}

//change the value of var.
void multiplyBy(int *var, int amount)
{
    *var *= amount;
}

//we should sent size
void multiplyArrayBy(int *array, int amount, int size)
{
    while(size--)
        array[size] *= amount;
}

void printTypes()
{
    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", static_cast<long>(LONG_MAX));
    printf("LONG_MIN    :   %ld\n", static_cast<long>(LONG_MIN));
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", static_cast<unsigned int>(UINT_MAX));
    printf("ULONG_MAX   :   %lu\n", static_cast<unsigned long>(ULONG_MAX));
    printf("USHRT_MAX   :   %d\n", static_cast<unsigned short>( USHRT_MAX));

    cout << endl;
}

//int argc is how many paremeters sended
//char *argv[] is arguments values
int main(int argc, char *argv[])
{
    for(int i = 0;  i < argc; i++)
    {
        cout << "parameter " << i << " is: " <<  argv[i] << endl;
        if(strcmp(argv[i], "-h") == 0 && i == 1) showHelp();
    }

    {
        std::cout << "Current C++ version is: ";
        if (__cplusplus == 201703L) std::cout << "C++17\n";
        else if (__cplusplus == 201402L) std::cout << "C++14\n";
        else if (__cplusplus == 201103L) std::cout << "C++11\n";
        else if (__cplusplus == 199711L) std::cout << "C++98\n";
        else std::cout << "pre-standard C++\n";
    }

    /*{
        char cont = {};
        do
        {
            //system("cls");
            printTypes();

            cout << "Do you want to print again? (Y/N)" << endl;
            cin >> cont;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }while(cont != 'n' && cont != 'N');
    }


    {
        char a;   //character 1 byte -128 to 127
        int b;    //integer 4 bytes -2147483648 to 2147483647
        short c;  //short integer 2 bytes -32768 to 32768
        float d;  //floating point 4 bytes +/- 3.4e +/- 38 (~7 digits)
        double f; //double floating point 8 bytes +/- 1.7e +/- 308 (~15 digits)
        unsigned g; // integer 2 bytes 0 to 65535

        for(int i = 1; i <= 10; i++)
        {
            if(i == 5)continue;

            for(int j = 1; j <= 10; j++)
            {
                cout.width(4);
                cout << i * j;
            }
            cout << endl;
        }

        int biArray[3][4] = {};
        cout << biArray[0][0] << endl;
    }

    {
        RacingExample EO;
        bool(RacingExample::*func_pointer1)();
        func_pointer1 = &RacingExample::Add;
        auto thread_one = std::thread (func_pointer1, &EO);

        bool(RacingExample::*func_pointer2)();
        func_pointer2 = &RacingExample::Sub;
        auto thread_two = std::thread (func_pointer2, &EO);

        thread_one.join();
        thread_two.join();
    }

    {
        Singleton* singleton = Singleton::GetInstance();
        cout << "The value of the singleton: " << singleton->a << endl;

        Light lamp;
        FlipUpCommand switchUp(lamp);
        FlipDownCommand switchDown(lamp);

        Switch s(switchUp, switchDown);
        s.flipUp();
        s.flipDown();
    }

    {
        using namespace wikibooks_design_patterns;
        Evaluator sentence("w x z - +");

        static
                const int sequences[][3] = {
            {5, 10, 42}, {1, 3, 2}, {7, 9, -5},
        };

        for (size_t i = 0; sizeof(sequences)/sizeof(sequences[0]) > i; ++i) {
            Map variables;
            variables["w"] = new Number(sequences[i][0]);
            variables["x"] = new Number(sequences[i][1]);
            variables["z"] = new Number(sequences[i][2]);
            int result = sentence.interpret(variables);
            for (Map::iterator it = variables.begin(); variables.end() != it; ++it) delete it->second;

            std::cout<<"Interpreter result: "<<result<<std::endl;
        }

        ParaWeatherData * wdata = new ParaWeatherData;
        CurrentConditionBoard* currentB = new CurrentConditionBoard(*wdata);
        StatisticBoard* statisticB = new StatisticBoard(*wdata);

        wdata->SensorDataChange(10.2, 28.2, 1001);
        wdata->SensorDataChange(12, 30.12, 1003);
        wdata->SensorDataChange(10.2, 26, 806);
        wdata->SensorDataChange(10.3, 35.9, 900);

        wdata->removeOb(currentB);

        wdata->SensorDataChange(100, 40, 1900);

        delete statisticB;
        delete currentB;
        delete wdata;
    }

    {
        Model model("Model");
        View view(model);
        // register the data-change event
        model.RegisterDataChangeHandler(&DataChange);
        // binds model and view.
        Controller controller(model, view);
        // when application starts or button is clicked or form is shown...
        controller.OnLoad();
        model.SetData("Changes"); // this should trigger View to render
    }

    {
        try {
            throw MyException();
        } catch(MyException& e) {
            std::cout << "MyException caught" << std::endl;
            std::cout << e.what() << std::endl;
        } catch(std::exception& e) {
            //Other errors
        }

        int x = 50;
        int y = 0;
        double z = 0;

        try {
            z = division(x, y);
            cout << z << endl;
        } catch (const char* msg) {
            cerr << msg << endl;
        }
    }

    {
        cout << 132 % 3 << endl; // Modulus, remaining

        OverloadOperator t;
        *t;
        t.Display();

        cout << (10 << 3) << endl; // multiply by 3 power of 2 --> 10 * 2 ^ 3 = 80
        cout << (10 >> 1) << endl; // divide by 1 power of 2 --> 10 / 2 ^ 1 = 5

        std::cout << "power: "  << endl << power(2,3) << endl  << power(2.1, 3) << endl;

        dayOfWeek d  = SN;
        cout << d << endl;
        cout << dayOfWeek(SN) << endl;

        cout << getDay(dayOfWeek(4)) << endl;

    }

    {
        auto lambda = []( int b ){ int r=1; while (b>0) r*=b--; return r; }(5); // 5!

        auto algorithm = [&]( double x, double m, double b ) -> double
        {
            return (m+x)/b;
        };

        auto a1 = algorithm(11,32,3.2), b1 = algorithm(41,55,6.1);
        cout << a1 << " " << b1 << " " << lambda << endl;

        auto lambda1 = [&](auto x, auto y)->double{return x / y;};
        cout << lambda1(50.0,6.0) << endl;

    }

    {
        //chainofresponsibility
        Handler *h1 = new SpecialHandler(10, 1);
        Handler *h2 = new SpecialHandler(20, 2);
        Handler *h3 = new SpecialHandler(30, 3);

        h1->setNextHandler(h2);
        h2->setNextHandler(h3);

        h1->request(18);

        h1->request(40);

        delete h1;
        delete h2;
        delete h3;
    }

    {
        int nr1 = 5, nr2 = 7;
        int &nickname = nr1;
        nickname = nr2;
        cout << nickname << endl;
        //you can not change the reference of reference variable
        //&nickname = nr2;

        int var1 = 5;
        int var2 = 5;
        int * const p1 = &var1;
        const int * p2 = &var1; // this pointer can not change the value that is under adress its pointing to.
        const int * const p3 = &var1; // this pointer can not change the value that is under adress its pointing to,
        //also it can not change the adress
        p2 = &var2;
        //p3 = &var2; //error
    }

    {
        double array[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
        vector<double> vect = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
        cout << Average(array, 6) << endl;
        cout << GetMaxValue(array, 6) << endl;
        cout << Average(vect, 6) << endl;
        cout << *(array + 1) << endl; // array is pointer. result 2
    }

    {
        //Dynamic allocation of memory allows you to reserve(allocate) memory after compilation of your program.
        //It also allows you to delete allocated memory which will free resources.

        cout << new int << endl; // after compile it reserve memory, and after every run the adress changes.

        int *p = new int;
        *p = 50;
        cout << *p << endl << p << endl;
        delete p; //releasing the adress in memory, not deleting
        p = nullptr;

        if(p)
            cout << *p << endl << p << endl;
    }

    {
        double *p = new (nothrow) double[6];
        if(p)
        {
            cout << p << endl;
            for(int i = 0; i < 6; i++)
                p[i] = static_cast<double>(i + 1);

            cout << *p << endl; // 1
            cout << *++p << endl; // 2
            cout << *++p << endl; // 3
            cout << *p++ << endl; // 3
            cout << *p << endl; // 4
            cout << *++p << endl; // 5
            cout << *--p << endl; // 4
        }

        delete []p;
    }

    {

        int var = 23;
        int* ptr_to_var = &var;

        cout << "Passing a copy of the pointer to function" << endl;
        cout << "Before :" << *ptr_to_var << endl; // display 23
        changePointerValue(ptr_to_var);
        cout << "After :" << *ptr_to_var << endl; // display 23

        var = 23;
        ptr_to_var = &var;
        cout << "Passing the address of the pointer to function" << endl;
        cout << "Before :" << *ptr_to_var << endl; // display 23
        changePointerValue(&ptr_to_var);
        cout << "After :" << *ptr_to_var << endl; // display 42

        var = 23;
        ptr_to_var = &var;
        cout << "Passing a Reference to a pointer to function" << endl;
        cout << "Before :" << *ptr_to_var << endl; // display 23
        changeReferenceValue(ptr_to_var);
        cout << "After :" << *ptr_to_var << endl; // display 42

        var = 23;
        cout << "Passing a Reference to a pointer to function" << endl;
        cout << "Before :" <<  var << endl; // display 23
        changeReferenceValue(var);
        cout << "After :" << var << endl; // display 42
    }

    {
        int a = 10;
        multiplyBy(&a, 5);
        cout << a << endl;
    }

    {
        int array[10];
        int lenght_of_array = sizeof (array) / sizeof (int);

        for (int i=0; i < lenght_of_array; i++)
        {
            array[i] = i;
            cout << array[i] << endl;
        }

        multiplyArrayBy(array, 5, lenght_of_array);
        //same
        //multiplyArrayBy(&array[0], 5, lenght_of_array);

        for (int i=0; i < lenght_of_array; i++)
        {
            cout << array[i] << endl;
        }
    }

    {
        cout << time(nullptr) << endl; // how many seconds gone from..
        srand(time(nullptr)); // seeds everytime will create different numbers

        //pseudo random is always following some rules
        int nr = rand() % 10; // generate numbers between 0-9 can get same number.
        cout << nr << endl;
    }

    {
        int a = 5;
        int b = 7;
        cout << (double)a / b << endl; // implicit way of casting
        cout << static_cast<int>(a /b) << endl; //explicit way of casting

        char ch = 'k';
        cout << static_cast<int>(ch) << endl; //explicit way of casting value = 107

    }

    {
        int a[3];
        if(a == &a[0])
        cout << a << endl << &a[0] << endl;
    }

    {
        //There is always invisible character called ending character and it looks like that: '/0'.
        //When that character is met it is a signal to stop printing characters.
        //That character '/0' is added automatically at the end when you use quotes between a word like that "hamburgers".
        //You can add it manually too. Check it out by for example doing something like that:
        char my_array[ ] =  "ham\0burgers";
        char  *p = my_array;
        cout << p << endl; // output is 'ham'

        char a[] = {'a', 'b', 'c', '\0'};
        cout << a << endl;

        char x[] = "a"; //name of array is a pointer
        char y[] = "a";

        cout << (x==y) << endl;
        cout << (&x[0] == &y[0]) << endl;

        cout << (strcmp(x, y)) << endl;
        //0 -variable are the same
        //1 -first string is greater
        //-1 -first string is lower

    }*/


    return 0;
}
