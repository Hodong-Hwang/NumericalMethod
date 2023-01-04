#ifndef __CLOSEDINTEGRAL_H__
#define __CLOSEDINTEGRAL_H__
#include "NumericalObject.h"
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
class SimpsonThird : public ClosedIntegral<T>{
    public:
    SimpsonThird(){classname="SimpsonThird";}
    T get_Answer(funcptr fcn, T a, T b, int step);

};

template<class T>
class SimpsonFourth : public ClosedIntegral<T>{
    public:
    SimpsonFourth(){classname="SimpsonFourth";}
    T get_Answer(funcptr fcn, T a, T b, int step);


};

template <class T>
inline T testfunction(T x)
{
    return (0.2+25*x-200*x*x+675*x*x*x-900*x*x*x*x+400*x*x*x*x*x);
}

template <class T>
inline T NormalDistribution(T x)
{
    return 
}
vo
#endif