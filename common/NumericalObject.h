
#ifndef __NUMERICALCOMMON_H__
#define __NUMERICALCOMMON_H__
#include <string>
class NumericalObject
{
public:
    NumericalObject(){}
    std::string get_classname() const {return classname;}
protected:
    std::string classname="NumericalObject";

    // add logger 
};

#endif