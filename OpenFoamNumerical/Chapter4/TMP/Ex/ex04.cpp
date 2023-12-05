#include <cmath>
#include <iostream>
class Circle
{
    private:

    double x_,y_,radius_;
    public:

    Circle()=delete;
    Circle (const double x,const double y,const double radius):x_(x),y_(y),radius_(radius){}
    Circle (const double x1,const double y1,const double x2,const double y2):x_((x1+x2)/2),y_((y1+y2)/2)
    {
        radius_ = std::sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))/2;
    }

    friend std::ostream& operator<< (std::ostream& os, const Circle& c);
};

std::ostream& operator<<(std::ostream& os, const Circle&c)
{
    return os<<"center x :" << c.x_ <<"," << c.y_ <<"," << c.radius_;
}