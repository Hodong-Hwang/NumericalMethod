template <class T>
class NiftyContainer
{
    ...
};

template <typename T, bool isPolymorphic>
class NiftyContainer
{
    ...

        void
        DoSomething()
    {
        T *pSomeObj = ...;
        if (isPolymorphic)
        {
            T *pNewObj = pSomeObj->Clone();
            ... polymorphic algorithm...
        }
        else
        {
            T *pNewObj = new T(*pSomeObj);
            ... nonpolymorphic algorithm...
        }
    }
};

template <typename T, bool isPolymorphic>
class NiftyContainer
{
private:
    void DoSomething(T *pObj, Int2Type<true>)
    {
        T *pNewObj = pObj->Clone();
        ... polymorphic algorithm...
    }
    void DoSomething(T *pObj, Int2Type<false>)
    {
        T *pNewObj = new T(*pObj);
        ... nonpolymorphic algorithm...
    }

public:
    void DoSomething(T *pObj)
    {
        DoSomething(pObj, Int2Type<isPolymorphic>());
    }
};

template <class T, class U>
T *Create(const U &arg)
{
    return new T(arg);
}

template <typename T, bool isPolymorphic>
struct NiftyContainerValueTraits
{
    typedef T *ValueType;
};
template <typename T>

struct NiftyContainerValueTraits<T, false>
{
    typedef T ValueType;
};

template <typename T, bool isPolymorphic>
class NiftyContainer
{
    ... typedef NiftyContainerValueTraits<T, isPolymorphic> Traits;
    typedef typename Traits::ValueType ValueType;
};

template <bool flag, typename T, typename U>
struct Select
{
    typedef T Result; 
};
template <typename T, typename U>
struct Select<false, T, U>
{
    typedef U Result;
};