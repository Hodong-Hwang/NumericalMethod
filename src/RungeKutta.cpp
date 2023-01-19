#include <RungeKuttaMethod.h>
#include <iostream>
template class SecondOrder<double>;
template class ThirdOrder<double>;
template class FourthOrder<double>;
template class HighOrder<double>;
template class SecondOrder<float>;
template class ThirdOrder<float>;
template class FourthOrder<float>;
template class HighOrder<float>;
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
    x=a;
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
    x=a;
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

template <class T>
std::pair<std::vector<T>,std::vector<T>> FourthOrder<T>::Solve(T a, T b, T ini)
{
    unsigned step=static_cast<unsigned>(abs(b-a)/h);
    // y_(i+1) = y_i + f(x,y)*h
    std::vector<T> domain;
    std::vector<T> range;
    T x,y,k1,k2,k3,k4,a1,a2,a3,a4;
    a1=1;
    a2=2;
    a3=2;
    a4=1;
    x=a;
    y=ini;
    for (unsigned i=0; i<step+1; i++)
    {
        if(showresult)std::cout << "step i =" << i << ", " << "y = " << y <<std::endl;
        // Predict Step
        domain.push_back(x);
        range.push_back(y);
        k1=fptr2(x,y);
        k2=fptr2(x+0.5*h,y+0.5*k1*h);
        k3=fptr2(x+0.5*h,y+0.5*k2*h);
        k4=fptr2(x+h,y+k3*h);
        x+=h;
        y+=(a1*k1*h+a2*k2*h+a3*k3*h+a4*k4*h)/(a1+a2+a3+a4);
    }
    return std::make_pair(domain,range);    
}

template <class T>
std::pair<std::vector<T>,std::vector<T>> HighOrder<T>::Solve(T a, T b, T ini)
{
    unsigned step=static_cast<unsigned>(abs(b-a)/h);
    // y_(i+1) = y_i + f(x,y)*h
    std::vector<T> domain;
    std::vector<T> range;
    T x,y;
    T k1,k2,k3,k4,k5,k6;
    T a1,a2,a3,a4,a5,a6, suma;
    a1=7; a2=0; a3=32; a4=12; a5=32; a6=7;
    suma=a1+a2+a3+a4+a5+a6;
    y=ini;
    x=a;
    ///
    for (unsigned i=0; i<step+1; i++)
    {
        if(showresult)std::cout << "step i =" << i << ", " << "y = " << y <<std::endl;
        // Predict Step
        domain.push_back(x);
        range.push_back(y);
        k1=fptr2(x,y);
        k2=fptr2(x+0.25*h,y+0.25*k1*h);
        k3=fptr2(x+0.25*h,y+(.125*k1+.125*k2)*h);
        k4=fptr2(x+0.5*h,y+(-.5*k2+k3)*h);
        k5=fptr2(x+0.75*h,y+(3*k1+9*k4)*h/16);
        k6=fptr2(x+h,y+(-3*k1+2*k2+12*k3-12*k4+8*k5)*h/7);
        x+=h;
        y+=(a1*k1+a2*k2+a3*k3+a4*k4+a5*k5+a6*k6)*h/(suma);
    }
    return std::make_pair(domain,range);    

}
