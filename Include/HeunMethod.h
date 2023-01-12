#ifndef __HEUNMETHOD_H__
#define __HEUNMETHOD_H__
#include "DiffMethod.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include<vector>


template <class T>
class HeunMethod : public DiffMethod<T>
{
    protected :
    bool showresult = false;
    using funcptr2 = T(*)(T,T);
    funcptr2 fptr2;
    public:
    HeunMethod(T h_): DiffMethod(h_){}
    HeunMethod(T h_,funcptr fptr_): DiffMethod(h_,fptr_){}
    HeunMethod(T h_,funcptr2 fptr_): DiffMethod(h_){fptr2=fptr_;}

    std::pair<std::vector<T>,std::vector<T>> Solve(T a, T b, T ini);
    std::pair<std::vector<T>,std::vector<T>> IterativeSolve(T a, T b,  T ini, unsigned n);

    void set_showResult(bool shoresult_) noexcept {showresult=shoresult_;}
    void resize_Stepszie(double step) noexcept {h=step;}
   

};
#endif