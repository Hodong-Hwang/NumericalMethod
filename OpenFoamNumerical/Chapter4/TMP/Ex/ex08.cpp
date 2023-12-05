#include <iostream>
#define FOR_LOOP(N) for(int i=0;i<N;i++)


template<typename T, unsigned Dim>
class Vec
{
    T* data_;public:
    Vec() : data_(new double[Dim]){}
    virtual ~Vec() {delete[] data_;}

    unsigned size() const {return Dim;}
    const double* data() {return data_;}

    double& operator[](const int index) {return data_[index];}
    const double& operator[] (const int index) const {return data_[index];}

    static double dot(const Vec<T,Dim>& a, const Vec<T,Dim>& b);
    double dot(const Vec<T,Dim>&b)
    {
        return dot(*this,b);
    }
    template<typename T1, unsigned Dim1>
    friend std::ostream& operator<<(std::ostream& os, const Vec& v);

    template<typename T1, unsigned Dim1>
    friend Vec operator+ (const Vec& a, const Vec& b);
    
    Vec& operator*= (const double& c)
    {
        FOR_LOOP(this->Dim) this->data_[i]*=c;
        return *this;
    }

    template<typename T1, unsigned Dim1>
    friend Vec operator* (const double& c, const Vec& a);

    template<typename T1, unsigned Dim1>
    friend Vec operator* (const Vec& a, const double& c);

    template<typename T1, unsigned Dim1>
    friend Vec operator+ (const Vec& a, const Vec& b);
};
template<typename T, unsigned Dim>
double Vec<T,Dim>::dot (const Vec<T,Dim>& a, const Vec<T,Dim>& b)
{
    if (a.size()!=b.size())
    {
        std::cout << "Vector Length should be same \n";
        return 0.0;
    }
    double ans=0.0;
    for (int i= 0; i<a.size();i++) ans+=a.data_[i]*b.data_[i];
    return ans;
}
template<typename T, unsigned Dim>
Vec<T,Dim> operator* (const Vec<T,Dim>& a, const double& c)
{
    Vec<T,Dim> ans;
    FOR_LOOP(a.size()) ans[i]=c*a[i];
    return ans;
}
template<typename T, unsigned Dim>
Vec<T,Dim> operator* (const double& c,const Vec<T,Dim>& a)
{
    return a*c;
}

template<typename T, unsigned Dim>
Vec<T,Dim> operator+ (const Vec<T,Dim>& a, const Vec<T,Dim>& b)
{
    Vec<T,Dim> ans;
    FOR_LOOP(a.size())ans[i]=a[i]+b[i];
    return ans;
}

template<typename T, unsigned Dim>
std::ostream& operator<< (std::ostream& os, const Vec<T,Dim>& v)
{
    os << v.size() << "( ";
    FOR_LOOP(v.size()) os << v[i]<< " ";
    os<<")";
    return os;
}
int main()
{
    const unsigned dim =3;
    Vec<double,dim> a;
    Vec<double,dim> b;

    FOR_LOOP(dim)
    {
        a[i]=i+1;
        b[i]=i+2;
    }
    std::cout << a <<std::endl;
    std::cout << b<< std::endl;
    std::cout << a.dot(b) <<std::endl;
    std::cout << a+b <<std::endl;

}