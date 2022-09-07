#ifndef RECTANGLE_H__
#define RECTANGLE_H__

#include "shape.hpp"

namespace bricks {

class Rectangle : public Shape {
public:
    Rectangle(sf::Color& a_color, float a_xPos, float a_yPos, float a_Width, float a_Height);  
    Rectangle(const Rectangle&) = default;
    Rectangle& operator=(const Rectangle&) = default;
    ~Rectangle() = default;
};


}//bricks

#endif //RECTANGLE_H__

