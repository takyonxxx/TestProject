#ifndef CHAINOFRESPONSIBILITY_H
#define CHAINOFRESPONSIBILITY_H
#include "libraries.h"
//Chain of Responsibility Design Pattern
/*
Chain of responsibility pattern is used to achieve loose coupling in software design
where a request from the client is passed to a chain of objects to process them. Later,
the object in the chain will decide themselves who will be processing the request and whether
the request is required to be sent to the next object in the chain or not.

Where and When Chain of Responsibility pattern is applicable :

When you want to decouple a request’s sender and receiver
Multiple objects, determined at runtime, are candidates to handle a request
When you don’t want to specify handlers explicitly in your code
When you want to issue a request to one of several objects without specifying the receiver explicitly.
This pattern is recommended when multiple objects can handle a request and the handler doesn’t have to be a specific object.
Also, the handler is determined at runtime. Please note that a request not handled at all by any handler is a valid use case.

Handler : This can be an interface which will primarily recieve the request and dispatches the request to chain of handlers.
It has reference of only first handler in the chain and does not know anything about rest of the handlers.

Concrete handlers : These are actual handlers of the request chained in some sequential order.

Client : Originator of request and this will access the handler to handle it.
*/

class Photo
{
public:
    Photo(string s) : mTitle(s)
    {
    cout << "Processing " << mTitle << " ...\n";
    }

private:
    string mTitle;
};

class PhotoProcessor
{
public:
    PhotoProcessor() : mNextProcessor(nullptr){ }

public:
    void process(Photo &p) {
        processImplementation(p);
        if (mNextProcessor != nullptr)
            mNextProcessor->process(p);
    }

    virtual ~PhotoProcessor() { }

    void setNextProcessor(PhotoProcessor *p) {
        mNextProcessor = p;
    }

protected:
    virtual void processImplementation(Photo &a) = 0;

private:
    PhotoProcessor *mNextProcessor;
};

class Scale : public PhotoProcessor
{
public:
    enum SCALE { S50, S100, S200, S300, S500 };
    Scale(SCALE s) : mSCALE(s) { }

private:
    void processImplementation(Photo &a) {
        cout << "Scaling photo\n";
    }

    SCALE mSCALE;
};

class RedEye : public PhotoProcessor
{
private:
    void processImplementation(Photo &a) {
        cout << "Removing red eye\n";
    }
};

class Filter : public PhotoProcessor
{
private:
    void processImplementation(Photo &a) {
        cout << "Applying filters\n";
    }
};

class ColorMatch : public PhotoProcessor
{
private:
    void processImplementation(Photo &a)
    {
        cout << "Matching colors\n";
    }
};

void processPhoto(Photo &photo)
{
    ColorMatch match;
    RedEye eye;
    Filter filter;
    Scale scale(Scale::S200);
    scale.setNextProcessor(&eye);
    eye.setNextProcessor(&match);
    match.setNextProcessor(&filter);
    scale.process(photo);
}

#endif // CHAINOFRESPONSIBILITY_H
