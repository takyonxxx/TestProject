#ifndef TESTCLASS_H
#define TESTCLASS_H

class TestClass
{
    int classId;
    int x, y;   
    static int counter;
public:
    TestClass(int, int, int);
    TestClass(const TestClass &);
    ~TestClass();
    static int getCounter();
    void getPosition() const;
    void setPosition(int, int);
    friend void setX(TestClass &, int);

    int *p;
};

#endif // TESTCLASS_H
