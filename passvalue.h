#ifndef PASSVALUE_H
#define PASSVALUE_H
#include "libraries.h"

int global_Var = 42;

//passing the reference of the pointer
void changeReferenceValue(int & pp) {
    pp = global_Var;
}

//passing a copy of the pointer is passed to the function
void changePointerValue(int * pp)
{
    *pp = global_Var;
}

//passing the address of the pointer to the function instead of a copy of the actual functio
void changePointerValue(int** pp)
{
    *pp = &global_Var;
}

void changeReferenceValue(int*& pp)
{
    pp = &global_Var;
}

// function to return a pointer
int* returnPointerValue()
{
    return &global_Var;
}

// function to return reference value
int& ReturnReference()
{
    return global_Var;
}


#endif // PASSVALUE_H
