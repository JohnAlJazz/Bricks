#ifndef PADDLE_H__
#define PADDLE_H__

#include "rectangle.hpp"

namespace bricks {

class Paddle : public Rectangle {
public:
    Paddle(float a_xVelocity, float a_yVelocity, sf::Color& a_color, float a_xPos, float a_yPos, float a_width, float a_height);
    Paddle(const Paddle&) = default;
    Paddle& operator=(const Paddle&) = default;
    ~Paddle() = default;
    
    void Move(sf::Event&a_event, size_t a_screenWidth);

private:
    float m_xVelocity;
    float m_yVelocity;  
    float m_width;
};


} //bricks

#endif //PADDLE_H__ 