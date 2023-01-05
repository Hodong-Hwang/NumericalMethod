#include <random>
#include <fstream>
#include <iomanip>
#define SIZE_N 1024
int main()
{
    std::mt19937 gen(std::random_device{}());
    std::normal_distribution<double> dist(0.0, 1.0);
    std::ofstream fs;
    fs.open("temp.dat");
    fs<<std::setprecision(9)<<std::setw(7); 

    for (unsigned i=0; i<SIZE_N; i++)
    {
        fs<<i<<"\t"<<dist(gen)<<"\n";
    }
    fs.close();

    return 0;


}