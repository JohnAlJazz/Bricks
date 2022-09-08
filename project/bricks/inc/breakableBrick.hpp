#ifndef BREAKABLE_BRICK_H__
#define BREAKABLE_BRICK_H__


#include "rectangle.hpp"

namespace bricks{

class BreakableBrick : public Rectangle {
public:
    BreakableBrick(int a_strength, sf::Color& a_color, float a_xPos, float a_yPos, float a_width, float a_height);

    void DecrementStrength() noexcept;
    int Strength();
    float CenterXOfBrick();
    float CenterYOfBrick();
    float Width();
    float Height();
    sf::FloatRect GlobalBounds();
    bool IsBroken();
    void Break();

private:
    int m_strength;
    float m_width;
    float m_height;
    bool m_isBroken;
};

#include "inl/breakableBrick.hxx"

} //bricks


#endif //BREAKABLE_BRICK_H__