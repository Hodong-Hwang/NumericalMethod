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
    int size = 9;
    Eigen::VectorXd T(size);
    test.resize(size,size);
    // Let's make it a symmetric matrix

    int offset =3;
    test(0,0)=4; 
    test(0,1)=-1;
    test(0,offset)=-1;
    for(int i=1; i<offset; i++)
    {
        test(i,i-1)=-1; 
        test(i,i)=4; 
        test(i,i+1)=-1;
        test(i,i+offset)=-1;  
    }
    for(int i=offset; i<size-offset; i++)
    {
        test(i,i-offset)=-1; 
        test(i,i-1)=-1; 
        test(i,i)=4; 
        test(i,i+1)=-1;
        test(i,i+offset)=-1;  
    }
    for(int i=size-offset; i<size-1; i++)
    {
        test(i,i-offset)=-1; 
        test(i,i-1)=-1; 
        test(i,i)=4; 
        test(i,i+1)=-1;
    }
    test(size-1,size-1)=4; 
    test(size-1,size-2)=-1;
    test(size-1,size-1-offset)=-1;
    // Print
    print_eigen(test);
    T[0]=75; // lb + bb
    T[1]=0;  // bb
    T[2]=50; // rb
    T[3]=75; // lb
    T[4]=0; // center // no
    T[5]=50; // 
    T[6]=175;
    T[7]=100;
    T[8]=150;

    auto T1= test.inverse()*T;
    print_eigen(T1);
    std::cout << " ================ "<<std::endl;
    print_eigen(test.inverse()*T1);


    return 0;
}