#include "rectangle.hpp"


namespace bricks {

Rectangle::Rectangle(sf::Color& a_color, float a_xPos, float a_yPos, float a_Width, float a_Height)
: Shape(new sf::RectangleShape{sf::Vector2f(a_Width, a_Height)}, a_color, a_xPos, a_yPos)
{}


} //bricks