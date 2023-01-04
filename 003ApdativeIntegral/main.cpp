#include <AdaptiveIntegral.h>
#include <iostream>

int main()
{
    auto test =AdaptiveMethod<double>();
    double a =0;
    double b= 0.8;    
    std::cout << test.adtQuad(a,b,1e-6) <<std::endl;
    std::cout << "============= Using Stack Result =============" <<"\n";
    std::cout <<test.adtQuadwithStack(0,0.8)<<std::endl;
    return 0;
}