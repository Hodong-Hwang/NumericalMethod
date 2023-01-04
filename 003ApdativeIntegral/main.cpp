#include <AdaptiveIntegral.h>
#include <iostream>

int main()
{
    auto test =AdaptiveMethod<double>();
    double a =0;
    double b= 0.8;
    test.adtQuad(a,b,1e-6);
    //std::cout << "============= Using Stack Result =============" <<"\n";
    //test.adtQuadwithStack(0,0.8);
    return 0;
}