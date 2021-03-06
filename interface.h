#ifndef COMMAND_H
#define COMMAND_H
#include "libraries.h"
/*the Command interface*/
class Interface
{
public:
    virtual void execute() = 0;
};

/*Receiver class*/
class Light {

public:
    Light() {  }

    void turnOn()
    {
        cout << "The light is on" << endl;
    }

    void turnOff()
    {
        cout << "The light is off" << endl;
    }
};

/*the Command for turning on the light*/
class FlipUpCommand: public Interface
{
public:

    FlipUpCommand(Light& light):theLight(light)
    {

    }

    virtual void execute()
    {
        theLight.turnOn();
    }

private:
    Light& theLight;
};

/*the Command for turning off the light*/
class FlipDownCommand: public Interface
{
public:
    FlipDownCommand(Light& light) :theLight(light)
    {

    }
    virtual void execute()
    {
        theLight.turnOff();
    }
private:
    Light& theLight;
};

class Switch {
public:
    Switch(Interface& flipUpCmd, Interface& flipDownCmd)
    :flipUpCommand(flipUpCmd),flipDownCommand(flipDownCmd)
    {

    }

    void flipUp()
    {
        flipUpCommand.execute();
    }

    void flipDown()
    {
        flipDownCommand.execute();
    }

private:
    Interface& flipUpCommand;
    Interface& flipDownCommand;
};

#endif // COMMAND_H
