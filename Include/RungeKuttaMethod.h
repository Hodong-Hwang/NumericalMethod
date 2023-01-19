#ifndef __RUNGEKUTTAMETHOD_H__
#define __RUNGEKUTTAMETHOD_H__
#include "DiffMethod.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include<vector>

template <class T>
class RungeKutta : public DiffMethod<T>
{
    protected :
    bool showresult = false;
    using funcptr2 = T(*)(T,T);
    funcptr2 fptr2;
    public:
    RungeKutta(T h_): DiffMethod(h_){}
    RungeKutta(T h_,funcptr2 fptr_): DiffMethod(h_){fptr2=fptr_;}
    virtual std::pair<std::vector<T>,std::vector<T>> Solve(T a, T b, T ini)=0;
    void set_showResult(bool shoresult_) noexcept {showresult=shoresult_;}
    void resize_Stepszie(double step) noexcept {h=step;}   

};
template <class T>
class SecondOrder : public RungeKutta<T>
{
    public:
    SecondOrder(T h_,funcptr2 fptr_):RungeKutta(h_,fptr_){}
    std::pair<std::vector<T>,std::vector<T>> Solve(T a, T b, T ini) override;
};

template <class T>
class ThirdOrder : public RungeKutta<T>
{
    public:
    ThirdOrder(T h_,funcptr2 fptr_):RungeKutta(h_,fptr_){}
    std::pair<std::vector<T>,std::vector<T>> Solve(T a, T b, T ini) override;
};

template <class T>
class FourthOrder : public RungeKutta<T>
{
    public:
    FourthOrder(T h_,funcptr2 fptr_):RungeKutta(h_,fptr_){}
    std::pair<std::vector<T>,std::vector<T>> Solve(T a, T b, T ini) override;
};


template <class T>
class HighOrder : public RungeKutta<T>
{
    public:
    HighOrder(T h_,funcptr2 fptr_):RungeKutta(h_,fptr_){}
    std::pair<std::vector<T>,std::vector<T>> Solve(T a, T b, T ini) override;

};

#endif