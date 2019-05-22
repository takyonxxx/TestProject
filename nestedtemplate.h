#ifndef NESTEDTEMPLATE_H
#define NESTEDTEMPLATE_H
#include "libraries.h"
//ring

template<class T>
class ring
{
    int m_size;
    int m_pos;
    T *m_values;
public:
    class iterator;// nested class, its friend class

public:
    ring(int size):m_size(size), m_pos(0), m_values(nullptr)
    {
        m_values = new T[size];
    }

    ~ring(){delete [] m_values;}

    int size() const
    {
        return m_size;
    }

    iterator begin()
    {
        return iterator(0, *this);
    }

    iterator end()
    {
        return iterator(m_size, *this);
    }

    void add(T value)
    {
        m_values[m_pos] = value;
        m_pos++;
        if(m_pos == m_size)
            m_pos = 0;
    }

    T &get(int pos)
    {
        return m_values[pos];
    }

};


template<class T>
class ring<T>::iterator
{
    int m_pos;
    ring &m_ring;
public:
    iterator(int pos, ring &obj): m_pos(pos), m_ring(obj)
    {

    }

    /*iterator &operator++(int){
        m_pos++;
        return *this;
    }*/

    iterator &operator++(){
        m_pos++;
        return *this;
    }

    T &operator*()
    {
        return m_ring.get(m_pos);
    }

    bool operator!=(const iterator &other) const
    {
        return m_pos != other.m_pos;
    }

};

void testNestedTemplates()
{
    //iterator nested in ring
    //ring<int>::iterator it;
    //it.print();

    ring<string> textring(3);

    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");
    textring.add("five");

    for(auto value : textring)
    {
        cout << value << endl;
    }

}

#endif // NESTEDTEMPLATE_H

