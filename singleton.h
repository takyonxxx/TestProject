#ifndef STRINGSINGLETON_H
#define STRINGSINGLETON_H
#include "libraries.h"
/* Place holder for thread synchronization mutex */
class Mutex
{   /* placeholder for code to create, use, and free a mutex */
};

/* Place holder for thread synchronization lock */
class Lock
{   public:
        Lock(Mutex& m) : mutex(m) { /* placeholder code to acquire the mutex */ }
        ~Lock() { /* placeholder code to release the mutex */ }
    private:
        Mutex & mutex;
};

class Singleton
{   public:
        static Singleton* GetInstance();
        int a;
        ~Singleton() { cout << "In Destructor" << endl; }

    private:
        Singleton(int _a) : a(_a) { cout << "In Constructor" << endl; }

        static Mutex mutex;

        // Not defined, to prevent copying
        Singleton(const Singleton& );
        Singleton& operator =(const Singleton& other);
};

Mutex Singleton::mutex;

Singleton* Singleton::GetInstance()
{
    Lock lock(mutex);

    cout << "Get Instance" << endl;

    // Initialized during first access
    static Singleton inst(1);

    return &inst;
}
#endif // STRINGSINGLETON_H
