#include <GaussQuadrature.h>
#include <iostream>
int main ()
{
    GaussQuadrature<double> test;
    std::cout << test.Integralfixed(0,0.8) <<std::endl;
    std::cout << test.Integral(0,0.8) <<std::endl;
    return 0; 
}