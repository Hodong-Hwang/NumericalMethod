#include <iostream>
#define PARMINFO(parm,desc) { std::cout \
	<<#parm ":" << desc <<std::endl;\
}\

int main(){
	PARMINFO(debug, "TestVersion 001 " );
}
