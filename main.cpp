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

#include "accessmodifiers.h"
#include "racingexample.h"
#include "singleton.h"
#include "chainofresponsibility.h"
#include "interface.h"
#include "overloadfunction.h"
#include "exceptions.h"
#include "passvalue.h"
#include "overloadoperator.h"
#include "overloadfunction.h"
#include "enumaration.h"
#include "template.h"
#include "object.h"
#include "inheritance.h"
#include "polymorphism.h"
#include "encapsulation.h"
#include "namespace.h"
#include "lambda.h"
#include "stream.h"
#include "database.h"
#include "algorithm.h"
#include "pragmadirective.h"
#include "casting.h"
#include "vectors_maps.h"
#include "stack_queue.h"
#include "constructors.h"
#include "complex.h"

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
void setX(Object &, int);
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

    /*

    //cout << 132 % 3 << endl; // Modulus, remaining

    //Access Modifiers
    {
        //public
        Circle_Public obj;
        // accessing public datamember outside class
        obj.radius = 5.5;

        cout << "Radius is:" << obj.radius << "\n";
        cout << "Area is:" << obj.compute_area() << endl;

        //private
        // creating object of the class
        Circle_Private obj2;
        // trying to access private data member
        // directly outside the class
        obj2.compute_area(1.5);

        //protected
        Child obj3;

        // member function of the derived class can
        // access the protected data members of the base class

        obj3.setId(81);
        obj3.displayId();
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
    {
        Dog dog;
        Cat cat;
        Cow cow;

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

    //encapsulation
    {
        Encapsulation obj;
        obj.set(5);
        cout << "Encapsulation: get() " << obj.get() << endl;
    }

    //io
    {
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

    //RacingExample
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

    //Singleton, interface
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

    //Model View Controller
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

    //Overloading
    {
        OverloadOperator t;
        *t;
        t.Display();

        cout << (10 << 3) << endl; // multiply by 3 power of 2 --> 10 * 2 ^ 3 = 80
        cout << (10 >> 1) << endl; // divide by 1 power of 2 --> 10 / 2 ^ 1 = 5

        std::cout << "power: "  << endl << power(2,3) << endl  << power(2.1, 3) << endl;

        Fraction f(2, 5);
        float val = f;
        cout << val;

        PointF p(20, 20);
        p.print();
        p = 30;   // Member x of t becomes 30
        p.print();
    }

    //Enumaration
    {
        dayOfWeek d  = SN;
        cout << d << endl;
        cout << dayOfWeek(SN) << endl;
        cout << getDay(dayOfWeek(4)) << endl;
    }

    //lambda function
    {
        lambdaTest();
    }

    //referance, pointer
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

        int a[3];
        if(a == &a[0])
        cout << a << endl << &a[0] << endl;

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

    //Dynamic allocation of memory
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

    //Passing value
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

        int a = 10;
        multiplyBy(&a, 5);
        cout << a << endl;

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

    //Random numbers
    {
        cout << time(nullptr) << endl; // how many seconds gone from..
        srand(time(nullptr)); // seeds everytime will create different numbers

        //pseudo random is always following some rules
        int nr = rand() % 10; // generate numbers between 0-9 can get same number.
        cout << nr << endl;
    }

    //Casting
    {
        int a = 5;
        int b = 7;
        cout << (double)a / b << endl; // implicit way of casting
        cout << static_cast<int>(a /b) << endl; //explicit way of casting

        char ch = 'k';
        cout << static_cast<int>(ch) << endl; //explicit way of casting value = 107

    }

    //Characters, array
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

    //Chain of Responsibility
    {
        Photo *p = new Photo("Y2013 Photo");
        processPhoto(*p);
    }

    //Constructure, friend function
    {
        Object dog(10, 50, 100);
        Object copyOfDog = dog; // copy constructure;
        const Object house(5, 25, 100); // House can not move setposition is not available;
        *(copyOfDog.p) = 700;

        cout << "Dog position:" << endl;
        dog.getPosition();
        cout << "p: " << *(dog.p) << endl;

        cout << "Copy Dog position:" << endl;
        copyOfDog.getPosition();
        cout << "p: " << *(copyOfDog.p) << endl;

        dog.setPosition(50, 100);
        //friend function
        setX(dog, 444);
        cout << "New Dog position:" << endl;
        dog.getPosition();
        cout << "p: " << *(dog.p) << endl;

        cout << "House position:" << endl;
        house.getPosition();
        cout << "p: " << *(house.p) << endl;
    }

    //Overloading operators
    {
        Integer a(50);
        int b = static_cast<int>(a);
        a = 100;
        cout << a.getNr() << endl;
        cout << b << endl;
        a += b;
        cout << a.getNr() << endl;
        a -= b;
        cout << a.getNr() << endl;

        Complex1 c1(10, 5), c2(2, 4);
        Complex1 c3 = c1 + c2; // An example call to "operator+"
        c3.print();
    }    

    //templates generalization
    {
        double array[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
        vector<double> vect = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
        cout << Average(array, 6) << endl;
        cout << GetMaxValue(array, 6) << endl;
        cout << Average(vect, 6) << endl;
        cout << *(array + 1) << endl; // array is pointer. result 2
        cout << Add<double, double>(2, 5.2) << endl;

        Point2D p1(10, 67);
        Point2D p2(50, 3);

        Point2D sum = Add(p1, p2); // template way
        cout << sum.getX() << " " << sum.getY() << endl;

        Point2D sum2 = p1 + p2; // overloading operation way
        cout << sum2.getX() << " " << sum2.getY() << endl;

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

    //algorithm
    {
        algorithmTest();
    }

    //Exceptions
    {
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

        try
        {
            CanGoWrong wrong;
        }
        catch (bad_alloc &e)
        {
             cout << "Caught Exception: " << e.what() << endl;
        }

        try
        {
            throw MyException();
        }
        catch(MyException& e)
        {
            std::cout << "MyException caught: ";
            std::cout << e.what() << std::endl;
        }
        catch(std::exception& e)
        {
            //Other errors
        }

        //cath order parent child classes, bad_alloc is child of exception
        try
        {
            goesWrong();
        }
        catch(bad_alloc &e)
        {
            std::cout << "Catching bad_alloc: " << e.what() << std::endl;
        }
        catch(exception &e)
        {
            std::cout << "Catching exception: " << e.what() << std::endl;
        }

        cout << "Still running" << endl;
    }

    //pragma Directive
    {
        pragmaTest();
    }

    //Binary file
    {
        writeBinary();
        readBinary();
    }    

    //Casting
    {
        reinterpret_cast_test();
        cout << endl;
        static_cast_test();
        cout << endl;
        dynamic_cast_test();
        cout << endl;
        const int myConst = 5;
        int *nonConst = const_cast<int*>(&myConst); // removes const
    }
    //Stack, Queue
    {
        testStack();
        testQueue();
    }

    //Vectors
    {
        testVectors();
        testMaps();
        testSet();
        testSort();
    }

    //Constructors, operator overloading
    {
        TestConstructorClass test1(10, "Turkay");
        test1.print();
        cout << "print test1: " << flush;
        //using std::flush causes the stream buffer to flush its output buffer.
        test1.print();

        TestConstructorClass test2(20, "Alya");

        test2 = test1;
        cout << "print test2: " << flush;
        test2.print();

        //Copy Initialization
        TestConstructorClass test3 = test1;
        cout << "print test3: " << flush;
        test3.print();

        TestConstructorClass testPrint1(1, "Turkay");
        TestConstructorClass testPrint2(2, "Alya");
        int value = 1 + 2 + 5;
        // + operator has right to left associativity of operators, first 2 + 5 than 1 + 7 => 1 + (2 +5)

        cout << testPrint1 << " " << testPrint2 << endl;
        // << (bit shift) operator has left to right associativity of operators, (cout << testPrint) << endl;
    }

    //Complex Constructors, operator overloading
    {
        using namespace turkayProgramming;

        Complex c1(3, 4);
        Complex c2(3, 4);
        Complex c2 = c1; // copy
        c1 = c2; // assignment
        Complex c3(c1); // copy

        Complex c3 = c1 + c2;

        Complex c4(4, 2);
        Complex c5 = c4 + 7;

        Complex c6(1, 7);
        cout << 3.2 + c6 << endl;

        cout << c1 << c2 << c3 << c4 << c5 << c6 << endl;
    }*/

    //Complex comparison, operator
    {
        using namespace turkayProgramming;

        Complex c1(2, 4);
        Complex c2(3, 1);

        if(c1 == c2)
        {
            cout << "Equal" << endl;
        }
        else if(c1 != c2)
        {
            cout << "Not Equal" << endl;
        }

        //Dereference operator
         cout << *c1 + *Complex(4, 3) << endl;
    }

    requireEnter();
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
void setX(Object &obj, int value)
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
