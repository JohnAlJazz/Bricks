#ifndef BREAKABLE_BRICK_H__
#define BREAKABLE_BRICK_H__


#include "rectangle.hpp"

namespace bricks{

class BreakableBrick : public Rectangle {
public:
    BreakableBrick(int a_strength, sf::Color& a_color, float a_xPos, float a_yPos, float a_width, float a_height);

    void DecrementStrength() noexcept;

private:
    int m_strength;
};

#include "inl/breakableBrick.hxx"

} //bricks


#endif //BREAKABLE_BRICK_H__