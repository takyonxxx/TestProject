#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "libraries.h"

mutex m;
static unsigned int counter = 0;
static bool alive = true;
static bool shouldAdd = true;

//Racing Example
//A race condition occurs when two or more threads can access shared data and they try to change it at the same time.
//Because the thread scheduling algorithm can swap between threads at any time,
//you don't know the order in which the threads will attempt to access the shared data.
//Therefore, the result of the change in data is dependent on the thread scheduling algorithm,
//i.e. both threads are "racing" to access/change the data.


struct RacingExample // all menbers public
{
    auto Add() -> bool
    {
        while(alive)
        {
            if( shouldAdd )
            {
                //you can use std::lock_guard if you want to be exception safe
                lock_guard<std::mutex> lock(m);
                counter += 10;
                std::cout << "Counter Add = " << counter << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                shouldAdd = false;
            }
        }
        return alive;
    }

    auto Sub() -> bool
    {
        while(alive)
        {
            if( !shouldAdd )
            {
                //you can use std::lock_guard if you want to be exception safe
                lock_guard<std::mutex> lock(m);
                counter -= 10;
                std::cout << "Counter Sub = " << counter<< std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                shouldAdd = true;
            }
        }
        return alive;
    }
};
#endif // FUNCTIONS_H
