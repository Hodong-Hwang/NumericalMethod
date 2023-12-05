#include <iostream>
#define FOR_LOOP(N) for(int i=0;i<N;i++)
class vec
{
    double* data_;
    unsigned size_;
public:
    vec(unsigned size =3) : size_(size), data_(new double[size_]){}
    virtual ~vec() {delete[] data_;}

    unsigned size() const {return size_;}
    const double* data() {return data_;}

    double& operator[](const int index) {return data_[index];}
    const double& operator[] (const int index) const {return data_[index];}

    static double dot(const vec& a, const vec& b);
    double dot(const vec&b)
    {
        return dot(*this,b);
    }
    friend std::ostream& operator<<(std::ostream& os, const vec& v);

    friend vec operator+ (const vec& a, const vec& b);
    vec& operator*= (const double& c)
    {
        FOR_LOOP(this->size_) this->data_[i]*=c;
        return *this;
    }

    friend vec operator* (const double& c, const vec& a);
    friend vec operator* (const vec& a, const double& c);
    friend vec operator+ (const vec& a, const vec& b);
};

double vec::dot (const vec& a, const vec& b)
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
vec operator* (const vec& a, const double& c)
{
    vec ans(a.size());
    FOR_LOOP(a.size()) ans[i]=c*a[i];
    return ans;
}
vec operator* (const double& c,const vec& a)
{
    return a*c;
}
vec operator+ (const vec& a, const vec& b)
{
    vec ans(a.size());
    FOR_LOOP(a.size())ans[i]=a[i]+b[i];
    return ans;
}
std::ostream& operator<< (std::ostream& os, const vec& v)
{
    os << v.size() << "( ";
    FOR_LOOP(v.size()) os << v[i]<< " ";
    os<<")";
    return os;
}
int main()
{
    int dim =3;
    vec a(dim);
    vec b(dim);

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