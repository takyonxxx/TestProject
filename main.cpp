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

A translation unit is any preprocessed source file.
A translation unit is the basic unit of compilation in C++.
This unit is made up of the contents of a single source file after it passes through preprocessing.
It contains included any header files without blocks that are ignored using conditional preprocessing statements like ifdef, ifndef, etc.
A single translation unit can be compiled into an object file, library, or executable program.

The Difference between Class and Structure.
Class can create a subclass that will inherit parent's properties and methods,
whereas Structure does not support the inheritance.
A class has all members private by default. A struct is a class where members are public by default.
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
#include "testclass.h"
#include "inheritance.h"
#include "polymorphism.h"
#include "namespace.h"
#include "stream.h"
#include "database.h"
#include "algorithm.h"

//MVC Model-View-Controller
#include "view.h"
#include "model.h"
#include "controller.h"
#include "common.h"

extern int ex_a;  // external outside, here we do not reserve memory for variable ex_a;

void showHelp();
void DataChange(string data) ;
void multiplyBy(int *var, int amount);
void multiplyArrayBy(int *array, int amount, int size);
void printTypes();
//friend function defined in TestClass
void setX(TestClass &, int);
//polymorphism
void voiceOfAnimal(Animal *);
void voiceOfAnimal(Animal &);

template<>
Point2D Add(Point2D var1, Point2D var2)
{
    Point2D tmp;
    tmp.setX(var1.getX() + var2.getX());
    tmp.setY(var1.getY() + var2.getY());

    return tmp;
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
        TestClass dog(10, 50, 100);
        TestClass copyOfDog = dog; // copy constructure;
        const TestClass house(5, 25, 100); // House can not move setposition is not available;
        *(copyOfDog.p) = 700;

        cout << "Dog position:" << endl;
        dog.getPosition();
        cout << "p: " << *(dog.p) << endl;

        cout << "Copy Dog position:" << endl;
        copyOfDog.getPosition();
        cout << "p: " << *(copyOfDog.p) << endl;

        dog.setPosition(50, 100);
        setX(dog, 444);
        cout << "New Dog position:" << endl;
        dog.getPosition();
        cout << "p: " << *(dog.p) << endl;

        cout << "House position:" << endl;
        house.getPosition();
        cout << "p: " << *(house.p) << endl;
    }

    {
        //overloading operators
        Integer a(50);
        int b = static_cast<int>(a);
        a = 100;
        cout << a.getNr() << endl;
        cout << b << endl;
        a += b;
        cout << a.getNr() << endl;
        a -= b;
        cout << a.getNr() << endl;
    }

    //inheritance
    {
        Point2D p2(10, 67);
        //p2.setXY(5, 50);
        p2.setX(47);
        p2.Point::setX(47);
        cout << p2.getX() << endl;
        cout << p2.getY() << endl;
    }

    //polymorphism, virtual functions, abstract class
    //polymorphism means : our complier knows which of morphs could invoke,
    //Another word the condition of occurring in several different forms.
    {
        Dog dog;
        Cat cat;
        Cow cow;

        cout <<  animal.getVoice() << endl;
        cout <<  dog.getVoice() << endl;
        cout <<  cat.getVoice() << endl;
        cout <<  cow.getVoice() << endl;

        Animal *d = &dog;
        voiceOfAnimal(d);
        voiceOfAnimal(&cat);
        voiceOfAnimal(cow);

        //Animal *dog = new Dog;
        //delete dog;// virtual ~Animal() invoked here
    }

    //function templates generalization
    {
        cout << Add<double, double>(2, 5.2) << endl;

        Point2D p1(10, 67);
        Point2D p2(50, 3);

        Point2D sum = Add(p1, p2); // templates way
        cout << sum.getX() << " " << sum.getY() << endl;

        Point2D sum2 = p1 + p2; // overloading operation way
        cout << sum2.getX() << " " << sum2.getY() << endl;
    }

    //class templates generalization
    {
        //typedefination
        templateClassChild_Int t(5);
        cout << t.getValue() << endl;

        templateClassChild_Double td(5.5);
        cout << td.getValue() << endl;

        //specialize the functions
        TemplateClass<char> b(49);
        TemplateClass<double> c(49.5);
        auto value = c.getValue();
        //specialized class
        TemplateClass<int*> i(49);
    }

    //Exceptions
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

        int a = 5;
        try {
            a *=10;

            if(a == 50)
                throw a;

            cout << "Here are other instructions" << endl;

        } catch (int e) {
            cout << "A cannot be equal to " << a << endl;
        }catch(double e){
            cout << "A cannot be equal to " << a << endl;
        }
        catch(...){
            cout << "other catches" << endl;
        }
    }

    //namespaces
    {
        cout << "this is text: " << mySpace::endl ;

    }

    //stream
    {
        writeFile();
        openFile();
    }

    //peek, putback
    {
        char c = cin.peek();
        //char c = cin.get();
        //cin.putback(c);

        if(c > '0' && c < '9')
        {
            int number;
            cin >> number;
            cout << "Number is: " << number << endl;
        }
        else {
            string text;
            cin >> text;
            cout << "Text is: " << text << endl;
        }
    }

    //database
    {
        databaseMenu();
    }
    */

    //algorithm
    {
        algorithmTest();
    }

    return 0;
}

void voiceOfAnimal(Animal *p) //faster
{
    cout << p->getVoice() << endl;
}

void voiceOfAnimal(Animal &p)
{
    cout << p.getVoice() << endl;
}

//friend function defined in TestClass
//A non-member function can access the private and protected members of a class if it is declared a friend of that class.
//That is done by including a declaration of this external function within the class,
//and preceding it with the keyword friend:
void setX(TestClass &obj, int value)
{
    obj.x = value;
    cout << "setting x value by friend class to : " << value << endl;
}

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
