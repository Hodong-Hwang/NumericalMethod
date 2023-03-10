#include "../Include/Closedintegral.h"
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
T SimpsonThird<T>::get_Answer(funcptr fcn, T a, T b, int step)
{
   // if (step <3) std::cout << "Error \n";
    T stepsize = (b-a)/step/3;
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

template<class T>
T SimpsonFourth<T>::get_Answer(funcptr fcn, T a, T b, int step)
{
    T stepsize = (b-a)/step/4;
    T x0,x1,x2,x3;
    T ans =0.0;
    x0=a;
    x1=x0+stepsize;
    x2=x1+stepsize;
    x3=x2+stepsize;
    while (x2<=b)
    {
        ans += stepsize*(fcn(x0)+ 3*fcn(x1)+ 3*fcn(x2) +fcn(x3))/8;
        x0=x3;
        x1=x0+stepsize;
        x2=x1+stepsize;
        x3=x2+stepsize;
    }
    return ans;
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
    std::cout << "SimposonExample 1/3 " << std::endl;
    SimpsonThird<double> simpletst;
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

void SimposonForthExample()
{
    std::cout << "SimposonExample 3/8" << std::endl;
    SimpsonFourth<double> simpletst;
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
// int main ()
// {
//     TropozodialExample();
//     SimposonExample();
//     SimposonForthExample();

//     return 0;
// }