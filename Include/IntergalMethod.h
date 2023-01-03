#ifndef __INTEGRALMETHOD_H__
#define __INTEGRALMETHOD_H__
#include "NumericalObject.h"
#include <memory>
#include <map>
#include <string>
#include <functional>

using namespace std;
template <class T>
T testfunction(T x)
{
    return (0.2+25*x-200*x*x+675*x*x*x-900*x*x*x*x+400*x*x*x*x*x);
}
template <class T>
class IntergralMethod : public NumericalObject
{
    using funcptr = T(*)(T);    
    protected : 
    funcptr fptr;
    public:
    IntergralMethod(funcptr fptr_=testfunction<T>){fptr=fptr_;};
};


#endif 