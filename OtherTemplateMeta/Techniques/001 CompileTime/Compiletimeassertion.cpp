
#define STATIC_CHECK(expr) { char unnamed[(expr) ? 1 : 0]; }
// can't create zero memory size
template <class To, class From>
To safe_reinterpret_cast(From from)
{
    assert(sizeof(From) <= sizeof(To));
    //
    // 
    STATIC_CHECK(sizeof(From) <= sizeof(To));
    return reinterpret_cast<To>(from);
}

// char* p = safe_reinterpret_cast<char*>(i);

template<bool> struct CompileTimeError;
template<> struct CompileTimeError<true> {};

#define STATIC_CHECKWithMsg(expr) \
(CompileTimeError<(expr) != 0>())

// CompileTimeError is a template taking a nontype parameter (a Boolean constant).
// If you try to instantiate CompileTimeError<false>, the compiler utters a message such as "Undefined specialization CompileTimeError<false>."


template<bool> struct CompileTimeChecker
{
    CompileTimeChecker(...);
};

template<> struct CompileTimeChecker<false> { };

#define STATIC_CHECK(expr, msg) \
{\
class ERROR_##msg {}; \
(void)sizeof(CompileTimeChecker<(expr) != 0>((ERROR_##msg())));\
}


template <class To, class From>
To safe_reinterpret_cast(From from)
{
    STATIC_CHECK(sizeof(From) <= sizeof(To),
    Destination_Type_Too_Narrow);
    return reinterpret_cast<To>(from);
    // class ERROR_Destination_Type_Too_Narrow {};
// (void)sizeof(
// CompileTimeChecker<(sizeof(From) <= sizeof(To))>(
// ERROR_Destination_Type_Too_Narrow()));
}