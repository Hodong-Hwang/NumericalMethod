#include <IntegralMethod.h>
#include <random>
#include <iostream>

double MCIntegral(double a, double b, unsigned N)
{
    unsigned count = 0;
    double x,y,ymax,area,rand1,rand2;
    ymax = 4.0; //assumption it should be larger than given Domain
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    auto func=testfunction<double>;
    for (unsigned i=0; i<N; i++)
    {        
        rand1=dist(gen);
        rand2=dist(gen);
        x=a*rand1+b*(1-rand1);
        y=ymax*rand2;
        if (y<func(x))count++;
        // ymax<func(x)-> update ymax
    }
    return (ymax*(b-a)*count/N);
    // matplotlib add it <plot result and gif generation>
}

int main ()
{
    //for loop matplotlib
    std::cout << MCIntegral(0,0.8,20000) << std::endl;
    return 0;
}