#include <iostream>

class Point
{
    double x_,y_;
public:
    Point():x_(0),y_(0){}
    Point(const double x, const double y):x_(x),y_(y){};
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    static Point add(const Point& p1, const Point& p2);
    static Point sub(const Point& p1, const Point& p2);
    static Point mul(const Point& p1, const Point& p2);
    Point& operator+=(const Point& p){
        x_+=p.x_;
        y_+=p.y_;
        return *this; 
    } 
    Point& operator-=(const Point& p){
        x_-=p.x_;
        y_-=p.y_;
        return *this; 
    } 
    Point& operator*=(const Point& p){
        x_*=p.x_;
        y_*=p.y_;
        return *this; 
    } 
    friend Point operator+(const Point& p1, const Point& p2);
    friend Point operator*(const Point& p1, const Point& p2);
    friend Point operator-(const Point& p1, const Point& p2);

};
Point operator+(const Point&p1, const Point&p2)
{
    return Point(p1.x_+p2.x_,p1.y_+p2.y_);
}
Point operator-(const Point&p1, const Point&p2)
{
    return Point(p1.x_-p2.x_,p1.y_-p2.y_);
}
Point operator*(const Point&p1, const Point&p2)
{
    return Point(p1.x_*p2.x_,p1.y_*p2.y_);
}


std::ostream& operator<<(std::ostream& os, const Point& p)
{
    return os << p.x_ <<"," << p.y_;;
}

Point Point::add(const Point&p1, const Point&p2)
{
    return Point(p1.x_+p2.x_,p2.x_+p2.y_);
} 
Point Point::sub(const Point&p1, const Point&p2)
{
    return Point(p1.x_-p2.x_,p2.x_-p2.y_);
} 
Point Point::mul(const Point&p1, const Point&p2)
{
    return Point(p1.x_*p2.x_,p2.x_*p2.y_);
} 

int main()
{
    Point p1 (1,2);
    Point p2 (3,4);
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << Point::add(p1,p2) << std::endl;
    std::cout << Point::sub(p1,p2) << std::endl;
    std::cout << Point::mul(p1,p2) << std::endl;
    std::cout << p1+p2 <<std::endl;
    p1+=p2;
    std::cout << p1 <<std::endl;
    return 0;
}
