#pragma once
#include "Point2D.h"

class Point3D:public Point2D
{
private:
    double z;
    void set_z(const double other_z);
public:
    Point3D();
    Point3D(const double other_x,const double other_y,const double other_z);

    virtual Point3D* clone() const;//recognize location

    virtual double getDistanceTo(const Point2D& destination) const;
    virtual double get_z() const;

    virtual void print() const;
};
