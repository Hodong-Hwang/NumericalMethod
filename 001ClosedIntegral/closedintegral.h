#ifndef __CLOSEDINTEGRAL_H__
#define __CLOSEDINTEGRAL_H__
#include "../common/NumericalObject.h"
#include <matplotlibcpp.h>
#include <vector>
namespace plt = matplotlibcpp;

template<class T>
class ClosedIntegral : public NumericalObject
{
    public:
        ClosedIntegral(){classname="ClosedIntegral";}
        using funcptr = T(*)(T);
        virtual T get_Answer(funcptr fcn, T a, T b, int step)=0;
};

template<class T>
class Tropozodial : public ClosedIntegral<T>{
    public:
    Tropozodial(){classname="Tropozodial";}
    T get_Answer(funcptr fcn, T a, T b, int step);

};

template<class T>
class Simpson : public ClosedIntegral<T>{
    public:
    Simpson(){classname="Simpson";}
    T get_Answer(funcptr fcn, T a, T b, int step);
    // T ThreePointMethod(funcptr fcn, T x0);
    // T FourPointMethod(funcptr fcn, T x0);

};



#endif