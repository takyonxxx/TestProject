#include "racingexample.h"
#include "singleton.h"
#include "chainofresponsibility.h"
#include "command.h"
#include "interpreter.h"
#include "iterator.h"
#include "overload.h"
#include "exceptions.h"
#include "passvalue.h"

//MVC Model-View-Controller
#include "view.h"
#include "model.h"
#include "controller.h"
#include "common.h"


void DataChange(string data) {
    cout << "Data Changes: " << data <<endl;
}

int main()
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

    Singleton* singleton = Singleton::GetInstance();
        cout << "The value of the singleton: " << singleton->a << endl;

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

    /*Light lamp;
    FlipUpCommand switchUp(lamp);
    FlipDownCommand switchDown(lamp);

    Switch s(switchUp, switchDown);
    s.flipUp();
    s.flipDown();

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

    Model model("Model");
    View view(model);
    // register the data-change event
    model.RegisterDataChangeHandler(&DataChange);
    // binds model and view.
    Controller controller(model, view);
    // when application starts or button is clicked or form is shown...
    controller.OnLoad();
    model.SetData("Changes"); // this should trigger View to render

    // Declare and Initialize the constructor
    Overload d1(8, 9);
    // Use (-) unary operator by single operand
    -d1;
    +d1;

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
    cout << "Passing Pointer to function:" << endl;
    cout << "Before : " << var << endl;  // display 23
    changePointerValue(&var);
    cout << "After : " << var << endl; // display 42

    var = 23;
    ptr_to_var = &var;
    cout << "Passing a Reference to a pointer to function" << endl;
    cout << "Before :" << *ptr_to_var << endl; // display 23
    changeReferenceValue(ptr_to_var);
    cout << "After :" << *ptr_to_var << endl; // display 42

    var = 23;
    ptr_to_var = &var;
    cout << "Passing a Reference to a pointer to function" << endl;
    cout << "Before :" <<  var << endl; // display 23
    changeReferenceValue(var);
    cout << "After :" << var << endl; // display 42

    var = 23;
    ptr_to_var = &var;
    cout << "Return a pointer from a function " << endl;
    cout << "Before :" << *ptr_to_var << endl; // display 23
    ptr_to_var = returnPointerValue();
    cout << "After :" << *ptr_to_var << endl; // display 42

    var = 23;
    ptr_to_var = &var;
    cout << "Returing a Reference " << endl;
    cout << "Before :" << *ptr_to_var << endl; // display 23
    ptr_to_var = &ReturnReference();
    cout << "After :" << *ptr_to_var << endl; // display 42*/


    return 0;
}
