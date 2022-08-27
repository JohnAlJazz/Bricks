#ifndef CIRCLE_H__
#define CIRCLE_H__

#include "shapes.hpp"


class Circle : public Shapes {
public:
    Circle(double m_radius);
    double Surface();

private:
    double m_radius;
};







#endif// 