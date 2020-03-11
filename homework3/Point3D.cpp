#include <iostream>
#include <cmath>
#include "Point3D.h"

Point3D::Point3D():Point2D()
{
    set_z(0);
}
Point3D::Point3D(const double other_x,const double other_y,const double other_z):Point2D(other_x,other_y)
{
    set_z(other_z);
}
Point3D* Point3D::clone() const
{
    return new Point3D(*this);
}
double Point3D::getDistanceTo(const Point2D& destination) const
{
    try //check if destination is 3D
    {
        auto point3D = dynamic_cast<const Point3D&>(destination);
        return sqrt(pow(get_x()-destination.get_x(),2) + pow(get_y()-destination.get_y(),2) + pow(get_z()-destination.get_z(),2));
    }
    catch(...) //if it is not
    {
        return Point2D::getDistanceTo(destination);
    }
}
void Point3D::set_z(const double other_z)
{
    z=other_z;
}
double Point3D::get_z() const
{
    return z;
}
void Point3D::print() const
{
    Point2D::print();
    std::cout<<"Coordinate Z: "<<get_z()<<std::endl;
}
