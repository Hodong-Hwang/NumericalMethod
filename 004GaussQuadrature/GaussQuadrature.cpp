#include <GaussQuadrature.h>
#include <cmath>
#include <stack>
#include <iostream>
template class GaussQuadrature<double>;
template class GaussQuadrature<float>;
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
    T xini, xend;
    std::stack<std::pair<T, T>> s;
    // two point method;
    ans= 0 ;
    xini=a;
    xend=b;
    s.push({xini,xend});
    while(!s.empty())
    {
        xini=s.top().first;
        xend=s.top().second;
        s.pop();
        c = (xini+xend)/2;
        I1=Integralfixed(xini,xend);
        I2=Integralfixed(xini,c)+Integralfixed(c,xend);
        err=I2-I1;
        if(abs(err)<tol)
        {
            ans +=I2;
        } 
        else
        {
            s.push({xini,c});
            s.push({c,xend});
            //if(debug)//std::cout << "adjusting step size = " << (c-xini)<<std::endl;
        }
    }

    return ans;
}
