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
