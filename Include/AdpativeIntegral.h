# ifndef __ADPATIVEINTEGRAL_H__
# define __ADPATIVEINTEGRAL_H__
#include "NumericalObject.h"
template <class T>
class SimpsonThird;

template <class T>
class AdpativeMethod : public NumericalObject{
    public: 
    using funcptr = T(*)(T);
    AdpativeMethod(funcptr fptr_) {classname="AdpativeMethod"; fptr=fptr_;}
    T adtQuad(T a, T b, double tol = 1e-6);
    funcptr fptr;
    SimpsonThird<T> approxans;
};

# endif 