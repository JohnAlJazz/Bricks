#include "shape.hpp"

namespace bricks {

Shape::Shape(sf::Shape* a_shape, sf::Color& a_color, float a_xPos, float a_yPos)
: m_shape(a_shape)
{
    SetShapeColor(a_color);
    SetShapePosition(a_xPos, a_yPos);
}

Shape::~Shape() {
    // delete m_shape;
}

sf::FloatRect Shape::GetGlobalBounds() {
    return m_shape->getGlobalBounds();    
}











}//bricks