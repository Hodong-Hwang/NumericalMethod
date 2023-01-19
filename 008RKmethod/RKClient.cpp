#include <RungeKuttaMethod.h>
#include <matplotlibcpp.h>
#include <iostream>
namespace plt = matplotlibcpp;
template <class T>
T expFunction (T x,T y)
{
    return (4*exp(0.8*x)-0.5*y);;
}

template <class T>
T exactSolution1 (T x)
{
    return (4*(exp(0.8*x)-exp(-0.5*x))/1.3+2*exp(-0.5*x));
}
void testSmaple (){
    double xini=0;
    double xend=4;
    double yini=2;
    double stepsize1=1;
    double stepsize2=0.25;
    int size_N=100;
    double x;
    /// make _Exact Solution

    std::vector <double> xdomain;
    std::vector <double> yrange;

    double step= (xend-xini)/(size_N-1);
    xdomain.reserve(size_N);
    yrange.reserve(size_N);
    for (unsigned i=0; i<size_N; i++)
    {
        x=xini+i*step;
        xdomain.push_back(x);
        yrange.push_back(exactSolution1<double>(x));
    }

    SecondOrder<double> test(stepsize1,expFunction);
    auto result=test.Solve(xini,xend,yini);
    auto dom=result.first;
    auto ran=result.second;
    ThirdOrder<double> test2(stepsize1,expFunction);
    auto result2=test2.Solve(xini,xend,yini);

    auto dom2=result2.first;
    auto ran2=result2.second;

    plt::plot(dom,ran,{{"label", "Second Order(Heun)"}});
    plt::plot(dom2,ran2,{{"label", "Third Order"}});
    plt::plot(xdomain,yrange,{{"label", "Exact Solution"}});
    plt::legend();
    plt::title("RK Method");

    plt::save("RK Method.png");

}
int main()
{

    testSmaple();

    return 0;

}