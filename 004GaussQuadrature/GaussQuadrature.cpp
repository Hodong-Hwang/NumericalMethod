#include "../Include/GaussQuadrature.h"
#include <cmath>
#include <iostream>
template<class T>
T GaussQuadrature<T>::Integral(T a, T b)
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
int main ()
{
    GaussQuadrature<double> test;

    std::cout << test.Integral(0,0.8) <<std::endl;
    return 0; 
}