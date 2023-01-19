#include <RungeKuttaMethod.h>
#include <iostream>
template class SecondOrder<double>;
template class ThirdOrder<double>;
template class SecondOrder<float>;
template class ThirdOrder<float>;

template <class T>
std::pair<std::vector<T>,std::vector<T>> SecondOrder<T>::Solve(T a, T b, T ini)
{
    unsigned step=static_cast<unsigned>(abs(b-a)/h);
    // y_(i+1) = y_i + f(x,y)*h
    std::vector<T> domain;
    std::vector<T> range;
    T x,y,k1,k2,a1,a2,p1,q11;
    a2=0.5;
    a1=1-a2;
    p1=1/(2*a2);
    q11=1/(2*a2);
    y=ini;
    ///
    for (unsigned i=0; i<step+1; i++)
    {
        if(showresult)std::cout << "step i =" << i << ", " << "y = " << y <<std::endl;
        // Predict Step
        domain.push_back(x);
        range.push_back(y);
        k1=fptr2(x,y);
        k2=fptr2(x+p1*h,y+q11*k1*h);
        x+=h;
        y+=a1*k1*h+a2*k2*h;
    }
    return std::make_pair(domain,range);    

}

template <class T>
std::pair<std::vector<T>,std::vector<T>> ThirdOrder<T>::Solve(T a, T b, T ini)
{
    unsigned step=static_cast<unsigned>(abs(b-a)/h);
    // y_(i+1) = y_i + f(x,y)*h
    std::vector<T> domain;
    std::vector<T> range;
    T x,y,k1,k2,k3,a1,a2,a3,p1,q11,p2,q21,q22;
    a1=1;
    a2=4;
    a3=1;
    p1=1/2;
    q11=1/2; // Matrix Solver For get Coefficeint 
    p2=1; 
    q21=-1;
    q22=2;

    y=ini;
    ///
    for (unsigned i=0; i<step+1; i++)
    {
        if(showresult)std::cout << "step i =" << i << ", " << "y = " << y <<std::endl;
        // Predict Step
        domain.push_back(x);
        range.push_back(y);
        k1=fptr2(x,y);
        k2=fptr2(x+p1*h,y+q11*k1*h);
        k3=fptr2(x+p2*h,y+q21*k1*h+q22*k2*h);
        x+=h;
        y+=(a1*k1*h+a2*k2*h+a3*k3*h)/(a1+a2+a3);
    }
    return std::make_pair(domain,range);    

}
