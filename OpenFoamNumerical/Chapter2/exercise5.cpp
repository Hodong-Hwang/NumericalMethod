#include <iostream>

#define VectorFactory(token) \
	class token##Vector 	\
	{		\
		size_t size_; \
		token* data_; \
		const char* typename_ = #token ; \
	public: \
	 	void print_type() {std::cout << "my type is " <<typename_ << std::endl;}\
	};

VectorFactory(int)
VectorFactory(double)
VectorFactory(char)

int main(int argc, char** argv){
	intVector a;
	doubleVector b;
	charVector c;
	a.print_type();
	b.print_type();
	c.print_type();
	return -1;
}

