#include <GaussQuadrature.h>
#include <iostream>


void DistributionEx()
{
    GaussQuadrature<double> test(NormalDistribution);
    GaussQuadrature<double> test2(NormalDistribution_t);
    double ans =0;
    ans=test2.Integral(-0.5,0)+test.Integral(-2,1);
    std::cout << "Improper Integral Result : " << ans << std::endl;

}
int main ()
{
    GaussQuadrature<double> test;
    std::cout << test.Integralfixed(0,0.8) <<std::endl;
    std::cout << test.Integral(0,0.8) <<std::endl;
    DistributionEx();
    return 0; 
}