#ifndef TEMPLATE_H
#define TEMPLATE_H
#include "libraries.h"

//function templates generalization

template <typename T, typename T2>
T Add(T var1, T2 var2)
{
    return var1 + var2;
}

template <typename T>
T Average(T *atArray, int nNumValues)
{
    T tSum = 0;
    for (int nCount=0; nCount < nNumValues; nCount++)
        tSum += atArray[nCount];

    tSum /= nNumValues;
    return tSum;
}

template  <typename T>
T GetMaxValue(T* atArray, int size)
{
    T tMax = atArray[0];
    for (int nCount=0; nCount < size; nCount++)
    {
        if(atArray[nCount] > tMax)
            tMax = atArray[nCount];
    }

    return tMax;
}

//class templates generalization

template <typename T>
class TemplateClass
{
protected:
    T value;
public:
    TemplateClass(T = 0);
    virtual  ~TemplateClass();
    virtual T getValue();
};

template <typename T>
TemplateClass<T>::TemplateClass(T value)
{
    this->value = value;
}

template <typename T>
TemplateClass<T>::~TemplateClass()
{
}

template <typename T>
T TemplateClass<T>::getValue()
{
    return this->value;
}

 //specialize the function
template <>
double TemplateClass<double>::getValue()
{
    cout << "this will be executed only when TemplateClass<double>" << endl;
    return this->value;
}

//type defination
typedef TemplateClass<int> templateClass_Int;
typedef TemplateClass<double> templateClass_Double;

template<typename T>
class TemplateClassChild : public TemplateClass<T>
{
protected:
    T childValue;
public:
    TemplateClassChild(T = 0);
    ~TemplateClassChild();
    virtual T getValue()
    {
        cout << "drived class invoked" << endl;
        return childValue;
    }
};

template <typename T>
TemplateClassChild<T>::TemplateClassChild(T value): TemplateClass<T> (value)
{
    this->childValue = value;
}

template <typename T>
TemplateClassChild<T>::~TemplateClassChild()
{
}

//type defination
typedef TemplateClassChild<int> templateClassChild_Int;
typedef TemplateClassChild<double> templateClassChild_Double;


//specialize the class
template<typename K>
class TemplateClass<K*>
{
public:
    TemplateClass(K a=0)
    {
        cout << "you can't use pointers here" << endl;
    }
};

template <>
class TemplateClass<char>
{
public:
    TemplateClass(char a = 0){cout << "this is from TemplateClass<char>" << endl;};
};

#endif // TEMPLATE_H
