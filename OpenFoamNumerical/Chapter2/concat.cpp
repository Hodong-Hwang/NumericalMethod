#include <iostream>
#define CONCAT(x,y) x##y
int main(){
	int y = 10 ;
	int xy = 10;
	std::cout << CONCAT(x,y) <<std::endl;
	
}
