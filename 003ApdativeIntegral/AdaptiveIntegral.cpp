#include <iostream> 
#include <cmath>
#include <stack>
#include <AdaptiveIntegral.h>
#include <IntegralMethod.h>
// Explicit template instantiation
template class AdaptiveMethod<double>;
template class AdaptiveMethod<float>;

template <class T>
T AdaptiveMethod<T>::adtQuad(T a, T b, double tol){
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
    // Simposon'Third method
    I1= h1*(fa+4*fc+fb)/6;
    I2= h2*(fa+4*fd+2*fc+4*fe+fb)/6;
    // will be updated with stack algorithm 
    if(abs(I2-I1)<= tol){
        ans=(I2+(I2-I1)/15); //boole's rule;
    }
    else {
       // std::cout <<"Adjusting Step size : error = "<< abs(I2-I1) <<std::endl;;
        Ia=adtQuad(a,c);
        Ib=adtQuad(c,b);
        ans=Ia+Ib;        
    }
    return ans;  
}

template <class T>
T AdaptiveMethod<T>::adtQuadwithStack(T a, T b, double tol){
    
    T xini,xend;
    T c,d,e, I1,I2,fd,fe,fa,fb,fc,h1,h2,ans;
    T Ia,Ib;
    std::stack<std::pair<T, T>> s;
    xini=a;
    xend=b;
    ans=0;
    s.push({xini,xend});
    while(!s.empty())
    {
        xini=s.top().first;
        xend=s.top().second;
        s.pop();
        c = (xini+xend)/2;
        d=(xini+c)/2;
        e=(c+xend)/2;
        h1=(xend-xini);
        h2=h1/2;
        fa=fptr(xini);
        fb=fptr(xend);
        fc=fptr(c);
        fd=fptr(d);
        fe=fptr(e);
        // Simposon'Third method
        I1= h1*(fa+4*fc+fb)/6;
        I2= h2*(fa+4*fd+2*fc+4*fe+fb)/6;        
        // will be updated with stack algorithm 
        if(abs(I2-I1)>tol) {
        //std::cout <<"Adjusting Step size : error = "<< abs(I2-I1) <<std::endl;;
        s.push({xini,c});
        s.push({c,xend});
        }
        else {
            ans+=(I2+(I2-I1)/15);    
        }
    }
    return ans;
}

