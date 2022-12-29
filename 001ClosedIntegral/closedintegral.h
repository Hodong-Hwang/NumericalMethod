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


#endif