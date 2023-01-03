#ifndef __GAUSSQUADRATURE_H__
#define __GAUSSQUADRATURE_H__
#include "IntergalMethod.h"
template <class T>
class GaussQuadrature: public IntergralMethod<T>
{
    public:
    GaussQuadrature(){classname="GaussQuadrature";}
    T Integral(T a, T b);
};


#endif