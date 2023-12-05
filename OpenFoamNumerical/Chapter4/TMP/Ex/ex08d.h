#include <iostream>

// Forward Decleartion>
template<typename T, unsigned Dim> class Vector;


template <typename T, unsigned Dim> std::ostream& operator<< (std::ostream& os, const Vector<T,Dim>& v);
template <typename T, unsigned Dim> std::ostream& operator+ ( const Vector<T,Dim>& v1, const Vector<T,Dim>& v2);


template <typename T, unsigned Dim=3>
class Vector
{
    friend std::ostream& operator<< <T,Dim>
    (
        std::ostream& os,const <Vector,Dim&v>
    )
    {
        os << Dim << "(";
        for(unsigned i= 0; i<Dim; i++)
        {
            os<< v[i];
        }
        os << ")";
        return os;
    }
    friend operator+<T,Dim>(const Vector<T,Dim>& v1, const Vector<T,Dim>& v2);
};

