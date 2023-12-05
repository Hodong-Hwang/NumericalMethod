#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
class Shape
{
    public:
    ~Shape() {}
    virtual double area() const =0;
};

class Circle : public Shape
{
    const double radius_;
    public:
    Circle () : radius_(1){};
    Circle(double radius) : radius_(radius){};
    ~Circle(){};
    double area() const override
    {
        return (M_PI*radius_*radius_);
    }
};

class Rectangle : public Shape
{
    const double height_,width_;
    public:
    Rectangle () : height_(1),width_(1){};
    Rectangle(double height,double width) : height_(height),width_(width){};
    ~Rectangle(){};
    double area() const override
    {
        return (height_*width_);
    }
};

int main(int argc, char** argv)
{
    std::string choice;
    std::cout << "Enter Circle or Rect" <<std::endl;
    std::cin >>choice;
    Shape* sp=nullptr;
    if(choice == "Circle")
    {
        sp = new Circle(3);
    }
    else if (choice == "Rect")
    {
        sp = new Rectangle(1,2);
    }
    std::cout << sp->area() <<std::endl;
    delete sp;
}