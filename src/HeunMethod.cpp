#include <HeunMethod.h>
#include <DiffMethod.h>
#include <iostream>

template class HeunMethod<double>;
template class HeunMethod<float>;

template <class T>
std::pair<std::vector<T>,std::vector<T>> HeunMethod<T>::Solve(T a, T b, T ini)
{
    unsigned step=static_cast<unsigned>(abs(b-a)/h);
    // y_(i+1) = y_i + f(x,y)*h
    std::vector<T> domain;
    std::vector<T> range;
    T x,y,slope,slopepre,ypre,slopecorr;
    x=a;
    y=ini;
    ///
    for (unsigned i=0; i<step+1; i++)
    {
        if(showresult)std::cout << "step i =" << i << ", " << "y = " << y <<std::endl;
        // Predict Step
        domain.push_back(x);
        range.push_back(y);
        slopepre=fptr2(x,y); 
        ypre=y+slopepre*h;
        slopecorr=(slopepre+fptr2(x+h,ypre))*0.5;      
        x+=h;
        y+=slopecorr*h;
    }
    return std::make_pair(domain,range);    

}
