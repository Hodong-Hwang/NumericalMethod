#include "../Include/AdpativeIntegral.h"
#include "../Include/closedintegral.h"
#include <iostream> 
#include <cmath>
#include <stack>
template <class T>
T AdpativeMethod<T>::adtQuad(T a, T b, double tol){
    
    T c;
    T d;
    T e, I1,I2,fd,fe,fa,fb,fc,h1,h2,ans;
    T Ia,Ib;
    c = (a+b)/2;
    d=(a+c)/2;
    e=(c+b)/2;
    h1=(b-a);
    h2=h1/2;
    fa=fptr(a);
    fb=fptr(b);
    fc=fptr(c);
    fd=fptr(d);
    fe=fptr(e);
    std::stack<std::pair<T, T>> s{a,b};
    // Simposon'Third method
    I1= h1*(fa+4*fc+fb)/6;
    I2= h2*(fa+4*fd+2*fc+4*fe+fb)/6;
    if(abs(I2-I1)<= tol){
        ans=(I2+(I2-I1)/15); //boole's rule;
    }
    else {
        std::cout <<"Adjusting Step size : error = "<< abs(I2-I1) <<std::endl;;

        Ia=adtQuad(a,c);
        Ib=adtQuad(c,b);
        ans=Ia+Ib;        
    }

    return ans;
  
}
int main()
{
    auto test = AdpativeMethod<double> (testfunction<double>);
    std::cout<<test.adtQuad(0,0.8,1e-7) <<std::endl;

    return 0;
}