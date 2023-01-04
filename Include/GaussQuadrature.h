#ifndef __GAUSSQUADRATURE_H__
#define __GAUSSQUADRATURE_H__
#include "IntegralMethod.h"

template <class T>
class GaussQuadrature: public IntegralMethod<T>
{
    public:
    GaussQuadrature(){classname="GaussQuadrature";}
    GaussQuadrature(funcptr fptr_) : IntegralMethod(fptr_) {classname="GaussQuadrature";}
    T Integral(T a, T b);
    T Integralfixed(T a, T b);
};


#endif