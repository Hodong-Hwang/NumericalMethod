#include <EulerMethod.h>
#include <matplotlibcpp.h>
#include <iostream>
namespace plt = matplotlibcpp;

void testSmaple (){
    double xini=0;
    double xend=3;
    double yini=1;
    double stepsize1=0.5;
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
        yrange.push_back(exactSolution<double>(x));
    }

    EulerMethod<double> test(stepsize1);
    auto result=test.Forward(xini,xend,yini);
    test.resize_Stepszie(stepsize2);
    auto result2=test.Forward(xini,xend,yini);
    auto dom=result.first;
    auto ran=result.second;
    auto dom2=result2.first;
    auto ran2=result2.second;

    plt::plot(dom,ran,{{"label", "stepSize=0.5"}});
    plt::plot(dom2,ran2,{{"label", "stepSize=0.25"}});
    plt::plot(xdomain,yrange,{{"label", "Exact Solution"}});
    plt::legend();
    plt::title("StepSzieEffect");

    plt::save("StepSizeEffect.png");

}
int main()
{

    testSmaple();

    return 0;

}