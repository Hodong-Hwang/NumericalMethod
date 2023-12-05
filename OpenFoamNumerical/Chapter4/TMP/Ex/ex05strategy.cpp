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

struct ISelecter
{
    virtual void get_Area()=0;
};


class ShapeSelecter : public ISelecter
{
    void get_Area()
    {
        std::string choice;
        std::cout << "Enter Circle or Rect" <<std::endl;
        std::cin >>choice;
        Shape* sp=nullptr;
        if(choice == "Circle")
        {
            double radius_ =0.0;
            std::cout << " Enter Radius (r) = ";
            std::cin >>radius_;
            sp = new Circle(radius_);
        }
        else if (choice=="Rect"){
            double width = 0;
            std::cout << "Enter Width :";
            std::cin >> width;
            double height =0;
            std::cout << "Enter Height :";
            std::cin >> height;
            sp = new Rectangle(width,height);
        }
        else{

            std::cout << choice << " is not included in " << "{Rect, Circle}" <<std::endl;
            return;
        }
        std::cout << choice << " area is " << sp->area() <<std::endl;
        delete sp;
        return;
    }
};

class ShapeClient{
    ISelecter* sel =nullptr;
public:
    ~ShapeClient()
    {
        if(sel!=nullptr) delete sel;
    }
    void get_Area()
    {
        sel->get_Area();
    }
    void set_Selecter(ISelecter* selecter)
    {
        sel=selecter;
    }
};


int main(int argc, char** argv)
{
    ShapeClient* sc =new ShapeClient;
    sc->set_Selecter(new ShapeSelecter);
    sc->get_Area();
}