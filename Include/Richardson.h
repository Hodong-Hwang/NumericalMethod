#ifndef __RICHARDSON_H__
#define __RICHARDSON_H__
#include "NumericalObject.h"
#include <vector>
#include <memory>

template<class T>
class ClosedIntegral;

template<class T>
class Richardson : public NumericalObject
{

    public:
    Richardson(){classname="Richardson";}
    void test();  
    std::unique_ptr<ClosedIntegral<T>> intmethod_ptr;

};




#endif