#include "closedintegral.h"
#include <iostream>

template<class T>
T Tropozodial<T>::get_Answer(funcptr fcn, T a, T b, int step)
{
    T stepsize = (b-a)/step;
    T x0,x1;
    T ans =0.0;
    x0=a;
    x1=x0+stepsize;
    for (int i =0 ; i<step; i++)
    {
        ans += stepsize*0.5*(fcn(x0)+fcn(x1));
        x0=x1;
        x1=x1+stepsize;
    }
    return ans;
}

template<class T>
T Simpson<T>::get_Answer(funcptr fcn, T a, T b, int step)
{
   // if (step <3) std::cout << "Error \n";
    T stepsize = (b-a)/step;
    T x0,x1,x2;
    T ans =0.0;
    x0=a;
    x1=x0+stepsize;
    x2=x1+stepsize;
    while (x2<=b)
    {
        ans += stepsize*( fcn(x0)+ 4*fcn(x1)+ fcn(x2) )/3;
        x0=x2;
        x1=x0+stepsize;
        x2=x1+stepsize;
    }
    return ans;
}

template <class T>
T testfunction(T x)
{
    return (0.2+25*x-200*x*x+675*x*x*x-900*x*x*x*x+400*x*x*x*x*x);
}

void TropozodialExample()
{
    std::cout << "TropozodialExample" << std::endl;
    Tropozodial<double> simpletst;
    std::cout << "n \t I \t \t error(%) \n";
    std::cout << "========================================" <<std::endl;
    double exactanswer =1.640533;  
    double approxans,error;  
    for (int i=2 ; i<11; i+=2)
    {
        approxans=simpletst.get_Answer(testfunction,0.0,0.8,i);
        error = abs(approxans-exactanswer)/exactanswer*100;
        std::cout << i << "\t" << approxans << "\t"<<"\t" << error <<"\n";
    }
}

void SimposonExample()
{
    std::cout << "SimposonExample" << std::endl;
    Simpson<double> simpletst;
    std::cout << "n \t I \t \t error(%) \n";
    std::cout << "========================================" <<std::endl;
    double exactanswer =1.640533;  
    double approxans,error;  
    for (int i=2 ; i<11; i+=2)
    {
        approxans=simpletst.get_Answer(testfunction,0.0,0.8,i);
        error = abs(approxans-exactanswer)/exactanswer*100;
        std::cout << i << "\t" << approxans << "\t"<<"\t" << error <<"\n";
    }

}

int main ()
{
    TropozodialExample();
    SimposonExample();
    
    return 0;
}