#ifndef TESTCLASS_H
#define TESTCLASS_H

class Object
{
    int classId;
    int x, y;   
    static int counter;
public:
    Object(int, int, int);
    Object(const Object &);
    ~Object();
    static int getCounter();
    void getPosition() const;
    void setPosition(int, int);
    friend void setX(Object &, int);

    int *p;
};

#endif // TESTCLASS_H
