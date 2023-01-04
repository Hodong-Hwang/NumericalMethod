# ifndef __ADAPTIVEINTEGRAL_H__
# define __ADAPTIVEINTEGRAL_H__
#include "IntegralMethod.h"

template <class T>
class AdaptiveMethod : public IntegralMethod<T>
{
    public: 
    //AdaptiveMethod(funcptr fptr_) {classname="AdaptiveMethod"; fptr=fptr_;}
    AdaptiveMethod() {classname="AdaptiveMethod";}
    T adtQuad(T a, T b, double tol = 1e-6);
    //T adtQuadwithStack(T a, T b, double tol = 1e-6);
};
AdaptiveMethod<double>;
AdaptiveMethod<float>;

# endif 