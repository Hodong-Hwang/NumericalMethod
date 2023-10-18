#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <float.h>

template <typename T>
class NewtonRapson{
    using  value_type = T;
    using FP = T(*)(T); 
    FP funcptr;
    double eps = 1e-6;
    double stepsize = 1e-6;
    int interator = 0;
    public : 
    T get_Root(T x0_){
        double err=DBL_MAX;
        T oldvalue,curvalue;
        int numiteration=0;
        T xprev,xnext;
        xprev=x0_; 
        while ( err>eps)
        {
            T gradValue = (funcptr(xprev+stepsize)-funcptr(xprev))/stepsize;
            xnext = xprev - funcptr(xprev)/gradValue;
            err=std::abs((xnext-xprev)/xprev);
            std::cout << "iter : "  << numiteration << "\t inter K : " << xprev << "\t Error :" << err<<"\n" ;
            numiteration++;
            if(numiteration>maxIteration)
            {
                std::cout << "Number of Iteration is exceeded, current value will be returned\n" 
                << "err : " <<err << "current value : " << xnext  <<std::endl;
                break;
            }
            xprev=xnext;
        }        
        return xnext;
    };    
    int maxIteration=3000;
    void set_function(FP fp){funcptr=fp;}
};

double waveNumber( double k )
{
    const double pi = M_PI;
    const double omega = pi/2;
    const double gravity = 9.81;
    const double h = 10;
    return (omega*omega - gravity*k*h);
}

int main (int argc, char** argv)
{
    const double pi = M_PI;
    const double omega = pi/2;
    double k0=omega*omega/9.81;

    NewtonRapson<double> doubleNR;
    doubleNR.set_function(waveNumber);
    doubleNR.get_Root(k0);
    return 0;
}