#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__
#include <string>

class Exception : public std::exception
{
protected:
    std::string ExName; 
    std::string SrcFile;  
    int SrcLine;           
    std::string ClassName; 
    std::string Method;   
    std::string Text;  
    std::string File;  
public:
    Exception(const std::string& srcfile, int srcline, const std::string& classname, const std::string& method, const std::string& text, const std::string& file){
        ExName = "Exception";
        SrcFile = "";
        SrcLine = srcline;
        ClassName = classname;
        Method = method;
        Text = text;
        File = file;
        Print();
    }
    ~Exception() throw() {}  ///<Destructor of objects.
    std::string ToStr()const{

    };
    void Print()const{

    };
    virtual const char* what() const throw() 
    {
        static char tx[2048];
        std::string tex = ToStr();
        for (unsigned c = 0; c <= tex.size() && c < 2047; c++)tx[c] = tex[c]; tx[2047] = '\0';
        return(tx);
    }
};
#endif