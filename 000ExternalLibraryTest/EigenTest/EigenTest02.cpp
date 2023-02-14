#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

int print_eigen(Eigen::MatrixXd m)
{
    // Eigen Matrices do have rule to print them with std::cout
    std::cout << m << std::endl;
    return 0;
}

int main()
{
    Eigen::MatrixXd test; //3 by 3 double precision matrix initialization
    Eigen::VectorXf T(15);
    test.resize(15,15);
    // Let's make it a symmetric matrix
    test(0,0)=1;
    test(14,14)=1;
    for(int i=1; i<14; i++)
    {
        for(int j=i-1; j<14; j++)
        {
            int xidx1  = i%5;
            int yidx1  = i/5;

            int xidx2  = j%5;
            int yidx2  = j/5;
            if (xidx1==yidx1) test(i,j)=-4;
            else if ( (abs(xidx1-xidx2)==1) & (abs(xidx2-yidx2)==1)) test(i,j)=1;
            else test(i,j)=0;
        }
    }

    // Print
    print_eigen(test);

    return 0;
}