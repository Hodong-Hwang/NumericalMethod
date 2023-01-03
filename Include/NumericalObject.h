
#ifndef __NUMERICALCOMMON_H__
#define __NUMERICALCOMMON_H__
#include <string>
#ifndef Run_Exception
#define Run_Exception(msg) RunExceptioon(__FILE__,__LINE__,ClassName,__func__,msg)
#endif
#ifndef Run_ExceptionFile
#define Run_ExceptionFile(msg,file) RunExceptioon(__FILE__,__LINE__,ClassName,__func__,msg,file)
#endif

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