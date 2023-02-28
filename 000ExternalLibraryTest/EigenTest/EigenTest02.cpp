#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <fstream>
int print_eigen(Eigen::MatrixXd m)
{
    // Eigen Matrices do have rule to print them with std::cout
    std::cout << m << std::endl;
    return 0;
}

void Test_RectAngular_Solver(int numnode,double Tl, double Tb, double Tr, double Tt)
{
    int size = numnode*numnode;
    int offset = numnode;
    Eigen::MatrixXd test; //3 by 3 double precision matrix initialization
    Eigen::VectorXd T(size);
    test.resize(size,size);
    for(int i=0; i<size; i++)
    {
        T[i]= 0;
        test(i,i)=4; 
        int pxidx=i%offset;
        int pyidx=i/offset;
        int widx=i-1;
        int eidx=i+1;
        int sidx=i-offset;
        int nidx=i+offset;

        if (pxidx==0)
        {
            T[i]+=Tl;
        }        
        else
        {
            test(i,widx)=-1;
        }

        if ((pxidx+1)==offset)
        {
            T[i]+=Tr;
        }
        else
        {
            if (eidx<size)
            {
                test(i,eidx)=-1;
            }
        }

        if (pyidx==0)
        {
            T[i]+=Tb;
        }
        else
        {
            if (sidx>=0) test(i,sidx)=-1;
        }

        if ((pyidx+1)==offset)
        {
            T[i]+=Tt;
        }
        else
        {
            if (nidx<size)
            {
                test(i,nidx)=-1;
            }
        }

       
    }   

    auto T1= test.inverse()*T;
    Eigen::MatrixXd result;
    result.resize(offset,offset);

    for (int j= 0 ; j<offset; j++)
    {
        for (int i= 0 ; i<offset; i++)
        {
            result(j,i)=T1[i+j*offset];
        }
    }
    std::ofstream fs("data.dat");
    if(fs.is_open())
    {
        fs << result <<"\n";
    }
    fs.close();
}

int main()
{
    int Dim = 15;
    // Let's make it a symmetric matrix
    double Tl=75, Tb=0, Tr=50, Tt=100;   
    Test_RectAngular_Solver(5,Tl,Tb,Tr,Tt);
    


    // std::cout << " ================ "<<std::endl;
    // print_eigen(test.inverse()*T1);


    return 0;
}