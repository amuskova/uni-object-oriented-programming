#include <iostream>
#include <cmath>
#include "Point2D.h"

Point2D::Point2D()
{
    set_x(0);
    set_y(0);
}
Point2D::Point2D(const double other_x,const double other_y)
{
    set_x(other_x);
    set_y(other_y);
}
Point2D* Point2D::clone() const
{
    return new Point2D(*this);
}
double Point2D::get_z() const
{
    return 0.0;
}
double Point2D::getDistanceTo(const Point2D& destination) const
{
    return sqrt(pow(get_x()-destination.get_x(),2) + pow(get_y()-destination.get_y(),2));
}
void Point2D::set_x(const double other_x)
{
    x=other_x;
}
double Point2D::get_x() const
{
    return x;
}
void Point2D::set_y(const double other_y)
{
    y=other_y;
}
double Point2D::get_y() const
{
    return y;
}
void Point2D::print() const
{
    std::cout << "Coordinate X: "<<get_x()<<std::endl;
    std::cout << "Coordinate Y: "<<get_y()<<std::endl;
}
Point2D::~Point2D(){}
