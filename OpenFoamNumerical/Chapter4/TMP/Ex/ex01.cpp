#include <iostream>


template <class T>
class Sub
{
    public:
    [[nodiscard]] constexpr
    inline decltype (auto) operator () (const T& arg1, const T& arg2) const
    {
        return arg1-arg2;
    }
};

template <class T>
class Add
{
    public:
    [[nodiscard]] constexpr
    decltype (auto) operator () (const T& arg1, const T& arg2) const
    {
        return arg1+arg2;
    }
};

template <class T>
class Mul
{
    public:
    [[nodiscard]] constexpr
    inline decltype (auto)  operator () (const T& arg1, const T& arg2) const
    {
        return arg1*arg2;
    }
};


template <class T>
class Div
{
    public:
    [[nodiscard]] constexpr
    inline T operator () (const T& arg1, const T& arg2) const
    {
        return arg1*arg2;
    }
};

int main()
{
    int x=1, y=2;
    Sub<int> sub;
    Mul<int> mul;
    Add<int> add;
    Div<int> div;
    auto ans1 =sub(x,y); 
    auto ans2 = mul(x,y);
    auto ans3 = add(x,y);
    auto ans4 = div(x,y);

    std::cout << "ans1 :" << ans1 <<std::endl;
    std::cout << "ans2 :" << ans2 <<std::endl;
    std::cout << "ans3 :" << ans3 <<std::endl;
    std::cout << "ans4 :" << ans4 <<std::endl;

}
