#include "../Include/GaussQuadrature.h"
#include <cmath>
template<class T>
inline T GaussQuadrature<T>::Integralfixed(T a, T b)
{
    T ans,x1,x2,root1,root2;
    // two point method;
    root1=-1/sqrt(3);
    root2=1/sqrt(3);
    x1=(b-a)/2*root1+(b+a)/2;
    x2=(b-a)/2*root2+(b+a)/2;
    ans = (fptr(x1)+fptr(x2))*(b-a)/2;
    return ans;
}

template<class T>
T GaussQuadrature<T>::Integral(T a, T b)
{
    double tol = 1e-6;
    T I1,I2,err,c,ans;
    // two point method;
    c=(a+b)/2;
    I1=Integralfixed(a,b);
    I2=Integralfixed(a,c)+Integralfixed(c,b);
    err=I2-I1;
    if(abs(err)<tol)
    {
        ans=Ia+Ib; 
    }

    return ans;
}
