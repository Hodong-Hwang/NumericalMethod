
// 런타임에 백터 내적을 ㅜㄱ하도록 구현
template <typename T, unsigned Dim, unsigned index>
struct ComputeDot
{
    static T Op(const Vector<T,Dim>& v1, const Vector <T,Dim>& v2)
    {
        return a[index]*a[index] + ComputeDot<T,Dim,index-1>::Op(v1,v2);
    }
};

//재기 조건 마지막은 특수화로 정의해서
template <typename T, unsigned Dim>
struct ComputeDot<T,Dim,0>
{
    static T Op(const Vector<T,Dim>& v1, const Vector <T,Dim>& v2)
    {
        return a[0]*a[0];
    }
};


template <typename T, unsigned Dim>
T Vector <T,Dim>::dot (const Vector<T,Dim>& v1, const Vector<T,Dim>& v2)
{
    return ComputeDot<T,Dim,Dim-1>::Op(a,b);
}

