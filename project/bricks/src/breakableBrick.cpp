#include "breakableBrick.hpp"


namespace bricks{

BreakableBrick::BreakableBrick(int a_strength, sf::Color& a_color, float a_xPos, float a_yPos, float a_width, float a_height)
: Rectangle(a_color, a_xPos, a_yPos, a_width, a_height)
, m_strength(a_strength)
{}






} //bricks


