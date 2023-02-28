#include "ball.hpp"
#include <iostream>

namespace bricks{

Ball::Ball(float a_xVelocity, float a_yVelocity, float a_radius, sf::Color& a_color, float a_xPos, float a_yPos)
: Shape(new sf::CircleShape{a_radius}, a_color, a_xPos, a_yPos)
, m_xVelocity(a_xVelocity)
, m_yVelocity(a_yVelocity)
, m_radius(a_radius)
{}

void Ball::Move(Shape& a_object, size_t a_width, size_t a_height) {
    if(m_shape->getGlobalBounds().intersects(a_object.GetGlobalBounds())) {        
        m_yVelocity *= -1;
    }
    
   
    if(xPos() <= 0) {            
            m_xVelocity *= -1;
        } 
        else if(xPos() >= a_width) {            
            m_xVelocity *= -1;
        } 
        else if(yPos() <= 0) {            
            m_yVelocity *= -1;
        } 
        else if(yPos() >= a_height) {            
            m_yVelocity *= -1;
        }   
        m_shape->move(m_xVelocity, m_yVelocity);      
}

    






} //bricks