#ifndef CHAINOFRESPONSIBILITY_H
#define CHAINOFRESPONSIBILITY_H
#include "libraries.h"

class Handler {
protected:
    Handler *next;

public:
    Handler() {
        next = nullptr;
    }

    virtual ~Handler() { }

    virtual void request(int value) = 0;

    void setNextHandler(Handler *nextInLine) {
        next = nextInLine;
    }
};

class SpecialHandler : public Handler {
private:
    int myLimit;
    int myId;

public:
    SpecialHandler(int limit, int id) {
        myLimit = limit;
        myId = id;
    }

    ~SpecialHandler() { }

    void request(int value)
    {
        cout << "Handler value: " << value << " limit: " << myLimit << endl;

        if(value < myLimit)
        {
            cout << "Handler " << myId << " handled the request with a limit of " << myLimit << endl;
        }
        else if(next != nullptr)
        {
            next->request(value);
        }
        else
        {
            cout << "Sorry, I am the last handler (" << myId << ") and I can't handle the request." << endl;
        }
    }
};

#endif // CHAINOFRESPONSIBILITY_H
