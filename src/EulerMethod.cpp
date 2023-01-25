#include <EulerMethod.h>
#include <DiffMethod.h>
#include <iostream>
template class EulerMethod<double>;
template class EulerMethod<float>;

template <class T>
std::pair<std::vector<T>,std::vector<T>> EulerMethod<T>::Forward(T a, T b, T ini)
{
    unsigned step=static_cast<unsigned>(abs(b-a)/h);
    // y_(i+1) = y_i + f(x,y)*h
    std::vector<T> domain;
    std::vector<T> range;
    T x,y;
    x=a;
    y=ini;
    domain.reserve(step);
    range.reserve(step);
    for (unsigned i=0; i<step; i++)
    {
        if(showresult)std::cout << "step i =" << i << ", " << "y = " << y <<std::endl;
        domain.push_back(x);
        range.push_back(y);
        y+=fptr(x)*h;
        x+=h;
    }
    return std::make_pair(domain,range);    
}


// Test Code (Need To be generalized)
template <class T>
std::pair<std::vector<T>,std::pair<std::vector<T>,std::vector<T>>> EulerMethod<T>::Forward(T a, T b, std::pair<T,T> yini)
{
    unsigned step=static_cast<unsigned>(abs(b-a)/h);
    // y_(i+1) = y_i + f(x,y)*h
    std::vector<T> domain;
    std::pair<std::vector<T>,std::vector<T>> range;
    auto& ran0=range.first;
    auto& ran1=range.second;
    T x,y0,y1,dxdy1,dxdy0;
    x=a;

    y0=yini.first;
    y1=yini.second;
    domain.reserve(step);
    ran0.reserve(step);
    ran1.reserve(step);
    for (unsigned i=0; i<step; i++)
    {
        if(showresult)std::cout << "step i =" << i << ", " << "y0 = " << y0 <<", y1=" <<y1  <<std::endl;
        domain.push_back(x);
        ran0.push_back(y0);
        ran1.push_back(y1);
        dxdy0=-0.5*y1;
        dxdy1=4-0.3*y1-0.1*y0;
        y0+=dxdy0*h;
        y1+=dxdy1*h;
        x+=h;
    }
    return std::make_pair(domain,range);    
}
