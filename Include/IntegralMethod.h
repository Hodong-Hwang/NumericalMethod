#ifndef __INTEGRALMETHOD_H__
#define __INTEGRALMETHOD_H__
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
    return (0.2+25*x-200*x*x+675*x*x*x-900*x*x*x*x+400*x*x*x*x*x);
}

template <class T>
inline T NormalDistribution(T x)
{
    return (1/(sqrt(2*M_PI))*exp(-x*x/2));
}
template <class T>
inline T NormalDistribution_t(T x)
{
    return (1/(sqrt(2*M_PI))*exp(-1/(2*x*x))/(x*x));
}
template <class T>
class IntegralMethod : public NumericalObject
{
    protected :
    using funcptr = T(*)(T);     
    funcptr fptr;
    public:
    IntegralMethod(funcptr fptr_=testfunction<T>){fptr=fptr_;};
};


#endif 