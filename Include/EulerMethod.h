#ifndef __EULERMETHOD_H__
#define __EULERMETHOD_H__
#include "DiffMethod.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include<vector>


template <class T>
class EulerMethod : public DiffMethod<T>
{
    protected :
    bool showresult = false;

    public:
    EulerMethod(T h_): DiffMethod(h_){}
    EulerMethod(T h_,funcptr fptr_): DiffMethod(h_,fptr_){}
    std::pair<std::vector<T>,std::vector<T>> Solve(T a, T b, T ini);
    void set_showResult(bool shoresult_) noexcept {showresult=shoresult_;}
    void resize_Stepszie(double step) noexcept {h=step;}

    

};
#endif