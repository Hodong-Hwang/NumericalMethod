#ifndef __DIFFMETHOD_H__
#define __DIFFMETHOD_H__
#include "NumericalObject.h"
#include <memory>
#include <map>
#include <string>
#include <functional>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
template <class T>
T testfunction(T x)
{
    return (-2*x*x*x+12*x*x-20*x+8.5);
}
template <class T>
T exactSolution(T x)
{
    return (-0.5*x*x*x*x+4*x*x*x-10*x*x+8.5*x+1);
}

template <class T>
class DiffMethod : public NumericalObject
{
    protected :
    using funcptr = T(*)(T);     
    funcptr fptr;
    T h;
    public:
    DiffMethod(T h_,funcptr fptr_=testfunction<T>):h(h_){fptr=fptr_; classname="DiffMethod";};
};
#endif