#ifndef SHAPE_H__
#define SHAPE_H__

#include "abstractShape.hpp"

namespace bricks{

class Shape : public AbstractShape {
public:
    Shape(sf::Shape* a_shape, sf::Color& a_color, float a_xPos, float a_yPos);
    Shape(const Shape&) = default;
    Shape& operator =(const Shape&) = default;
    ~Shape();

    void SetShapeColor(const sf::Color &a_color) override;
    void SetShapePosition(float a_xPos, float a_yPos) override;
    void Draw(sf::RenderWindow& a_window);
    sf::FloatRect GetGlobalBounds();

// protected:
    float xPos();
    float yPos();

protected:
    sf::Shape* m_shape;
};


#include "inl/shape.hxx"


}//bricks

#endif //SHAPE_H__