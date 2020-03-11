#pragma once

class Point2D
{
private:
    double x;
    double y;
    void set_x(const double other_x);
    void set_y(const double other_y);
public:
    Point2D();
    Point2D(const double other_x,const double other_y);
    virtual ~Point2D();
    virtual Point2D* clone() const;//recognize location
    virtual double getDistanceTo(const Point2D& destination) const;
    double get_x() const;
    double get_y() const;
    virtual double get_z() const;
    virtual void print() const;
};

