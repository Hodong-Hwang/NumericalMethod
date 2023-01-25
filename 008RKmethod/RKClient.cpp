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
void testSmaple ()
{
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
    for (size_t i=0; i<size_N; i++)
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
void ErrorEstimate ()
{
    double xini=0;
    double xend=4;
    double yini=2;
    double stepsize1=0.25;
    int size_N=(xend-xini)/stepsize1+1;
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
    ThirdOrder<double> test2(stepsize1,expFunction);
    FourthOrder<double> test3(stepsize1,expFunction);
    HighOrder<double> test4(stepsize1,expFunction);
    auto result=test.Solve(xini,xend,yini);
    auto result2=test2.Solve(xini,xend,yini);
    auto result3=test3.Solve(xini,xend,yini);
    auto result4=test4.Solve(xini,xend,yini);
    std::vector<double> err1,err2,err3,err4;
    err1.reserve(size_N);
    err2.reserve(size_N);
    err3.reserve(size_N);
    err4.reserve(size_N);
    auto dom=result.first;
    auto y1=result.second;
    auto y2=result2.second;
    auto y3=result3.second;
    auto y4=result4.second;
    for (size_t i=0; i<size_N; i++)
    {
        err1.push_back(abs(yrange.at(i)-y1.at(i))/yrange.at(i)*100);
        //err2.push_back(abs(yrange.at(i)-y2.at(i))/yrange.at(i)*100);
        err3.push_back(abs(yrange.at(i)-y3.at(i))/yrange.at(i)*100);
        err4.push_back(abs(yrange.at(i)-y4.at(i))/yrange.at(i)*100);
    }
  //  plt::plot(dom,err1,{{"label", "Second Order(Heun)"}});
   // plt::plot(dom,err2,{{"label", "Third Order"}});
    //plt::semilogy(dom,err3);
    //plt::semilogy(dom,err4);
    plt::plot(dom,err3,{{"label", "Fourth Order"}});
    plt::plot(dom,err4,{{"label", "Butchers Order"}});
    plt::legend();
    plt::title("RK Order Error Estimation");
    plt::save("RK Error.png");

}
int main()
{

    //testSmaple();
    ErrorEstimate();

    return 0;

}