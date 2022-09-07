#ifndef BALL_H__
#define BALL_H__

#include "shape.hpp"

namespace bricks {

class Ball : public Shape {
public:
    Ball(float a_xVelocity, float a_yVelocity, float a_radius, sf::Color& a_color, float a_xPos, float a_yPos);
    Ball(const Ball& a_ball) = default;
    Ball& operator=(const Ball&) = default;
    ~Ball() = default;
   
    void Move(Shape& a_object, size_t a_width, size_t a_height);

private:
    float m_xVelocity;
    float m_yVelocity;
};


} //bricks

#endif //BALL_H__