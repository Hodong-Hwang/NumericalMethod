#pragma
#include <array>
#include <iostream>
#define N 3

template <template <typename> typename C, typename n>
void print_array (C A, int n)
{
    for (int i=0; i<n ; i++)
    {
        for (int j=0; j<n; j++)
        {
            std::cout <<A[i][j] <<"\t";
        }
        std::cout <<"\n";
    }

}

int main ()
{
    std::array<std::array<double,N>,N> A{
        3,-0.1,-0.2,0.1,7,-0.3,0.3,-0.2,10
    };
    print_array(A,N);

  //  std::cout << A <<std::endl;
}
