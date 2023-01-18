#include "../Include/closedintegral.h"
#include "../Include/Richardson.h"
#include <iostream>

template <class T>
T testfunction(T x)
{
    return (0.2+25*x-200*x*x+675*x*x*x-900*x*x*x*x+400*x*x*x*x*x);
}

template <class T>
void Richardson<T>::test()
{
    double ans1, ans2,corrected_ans;
    intmethod_ptr=std::make_unique<Tropozodial<double>>();
    ans1 = intmethod_ptr->get_Answer(testfunction,0,0.8,1);
    ans2 = intmethod_ptr->get_Answer(testfunction,0,0.8,2);
    corrected_ans=4*ans2/3-ans1/3;
    std::cout <<ans1 <<std::endl;
    std::cout <<ans2 <<std::endl;
    std::cout <<corrected_ans <<std::endl;
    std::cout<< intmethod_ptr->get_Answer(testfunction,0,0.8,8)<<std::endl;

}
int main ()
{
    Richardson<double> richardson;
    richardson.test();
    return 0;

}