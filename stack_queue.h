#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H
#include "libraries.h"
#include <stack>
#include <queue>
//Stack:
//Insertion and deletion happen on same end, Last in, First out
//The simplest application of a stack is to reverse a word. You push a given word to stack - letter by letter - and then pop letters from the stack.
//Another application is an "undo" mechanism in text editors; this operation is accomplished by keeping all text changes in a stack.

//Queue:
//Insertion and deletion happen on different ends, First in, First out
//A queue is a container of objects (a linear collection) that are inserted and removed according to the first-in first-out (FIFO) principle.
//An excellent example of a queue is a line of students in the food court of the UC. New additions to a line made to the back of the queue,
//while removal (or serving) happens in the front. In the queue only two operations are allowed enqueue and dequeue.
//Enqueue means to insert an item into the back of the queue, dequeue means removing the front item. The picture demonstrates the FIFO access.
//The difference between stacks and queues is in removing.

//In a stack we remove the item the most recently added; in a queue, we remove the item the least recently added.
//Bir yığında en son eklenen öğeyi kaldırırız; kuyrukta, en yakın zamanda eklenen öğeyi kaldırdık.

#define MAX 1000

class Stack
{
    int top;
public:
    int a[MAX];    //Maximum size of Stack

    Stack()  { top = -1; }
    bool push(int x);
    int pop();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX-1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout<<x <<" pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

struct Queue {
    stack<int> s;

    // Enqueue an item to the queue
    void enQueue(int x)
    {
        s.push(x);
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        if (s.empty()) {
            cout << "Q is empty";
            exit(0);
        }

        // pop an item from the stack
        int x = s.top();
        s.pop();

        // if stack becomes empty, return
        // the popped item
        if (s.empty())
            return x;

        // recursive call
        int item = deQueue();

        // push popped item back to the stack
        s.push(x);

        // return the result of deQueue() call
        return item;
    }
};


class TestQS
{
    string name;
public:
    TestQS(string name): name(name)
    {
    }

    ~TestQS()
    {
        //cout << "TestQS destroyed" << endl;
    }

    void print() const
    {
        cout << name << endl;
    }
};

void testStack()
{
    //LIFO
    stack<TestQS> testStack;
    testStack.push(TestQS("Turkay"));
    testStack.push(TestQS("Gokhan"));
    testStack.push(TestQS("Alya"));

    /*invalid code, object is destroyed.
    TestQS &test1 = testStack.top();
    testStack.pop();
    test1.print();//Reference refers to destroyed objects
    */
    cout << endl;
    cout << "Stack -> LIFO:" << endl;

    while(testStack.size() > 0)
    {
        TestQS &test = testStack.top();
        test.print();
        testStack.pop(); // before come to top
    }

    cout << endl;
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop() << " Popped from stack\n";
}

void testQueue()
{
    //FIFO
    queue<TestQS> testQueue;
    testQueue.push(TestQS("Turkay"));
    testQueue.push(TestQS("Gokhan"));
    testQueue.push(TestQS("Alya"));

    //testQueue.back().print();

    cout << endl;
    cout << "Queue -> FIFO:" << endl;

    while(testQueue.size() > 0)
    {
        TestQS &test = testQueue.front();
        test.print();
        testQueue.pop(); // before come to top
    }

    cout << endl;

    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

}

#endif // STACK_QUEUE_H
