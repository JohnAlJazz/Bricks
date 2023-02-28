#include "ball.hpp"


inline float Ball::CenterXOfBall() {
    return xPos() + m_radius; 
}

inline float Ball::CenterYOfBall() {
    return yPos() + m_radius; 
}

inline float Ball::Diameter() {
    return 2 * m_radius; 
}

inline void Ball::SetXVelocity() {
    m_xVelocity *= -1;
}

inline void Ball::SetYVelocity() {
    m_yVelocity *= -1;
}

inline bool Ball::Collision(const sf::FloatRect& a_object) {
    return m_shape->getGlobalBounds().intersects(a_object);
}
