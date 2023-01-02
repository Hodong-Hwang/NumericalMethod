#ifndef __GAUSSQUADRATURE_H__
#define __GAUSSQUADRATURE_H__
#include "NumericalObject.h"
template <class T>
class GaussQuadrature: public NumericalObject
{
    private:

    public:
    GaussQuadrature(){classname="GaussQuadrature";}
    T Integral(T a, T b);
};
#endif