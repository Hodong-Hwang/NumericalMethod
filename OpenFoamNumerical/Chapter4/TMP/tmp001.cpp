#include <iostream>

template <unsigned int n>
class factorial
{
    public :
    static const unsigned int value = n*factorial<n-1>::value;
};

// specialization
// Termination Conditions
template <>
class factorial<0>
{
    public:
    static const unsigned int value = 1;
};


int main ()
{
    std::cout <<factorial<30>::value <<std::endl;
}

