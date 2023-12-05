#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

class dispersionRelation
{
    const double pi_;
    const double grav_;
    double omega_;
    double h_;
public:
    dispersionRelation(double omega, double h):
    pi_(M_PI),grav_(9.812),omega_(omega),h_(h)
    {

    }
    
    double operator()(double k)
    {
        return omega_*omega_-grav_*k*tanh(k*h_);
    }
    double derivative(double k)
    {
        return (this->operator()(k+this->h_)-this->operator()(k))/(this->h_);
    }
};

double find_root(double x0, dispersionRelation& f)
{
    double x;
    x = x0;
    for (int i =0; i< 10; ++i)
    {
        std::cout << " iter : " << i << std::endl;
        x= x0 -f(x0)/f.derivative(x0);
        std::cout << "inter x: "<< x <<std::endl;
        x0= x;
    }
    return x;
}

int main()
{
    dispersionRelation disperf(M_PI/2 ,10.0);
    find_root(M_PI/2*M_PI/2/9.812,disperf);
}