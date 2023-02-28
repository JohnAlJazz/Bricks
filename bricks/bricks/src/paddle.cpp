#include "paddle.hpp"
#include <iostream>


namespace bricks {

Paddle::Paddle(float a_xVelocity, float a_yVelocity, sf::Color& a_color, float a_xPos, float a_yPos, float a_width, float a_height)
: Rectangle(a_color, a_xPos, a_yPos, a_width, a_height)
, m_xVelocity(a_xVelocity)
, m_yVelocity(a_yVelocity)
, m_width(a_width)
{}

void Paddle::Move(sf::Event&a_event, size_t a_screenWidth) {
    if(a_event.type == sf::Event::KeyPressed) {
        if(a_event.key.code == sf::Keyboard::Left && xPos() >= 0) {
            m_shape->move(-m_xVelocity, 0);
        }
        if(a_event.key.code == sf::Keyboard::Right && xPos() <= a_screenWidth - m_width) {
            m_shape->move(m_xVelocity, 0);
        }
    }         
}

} //bricks
