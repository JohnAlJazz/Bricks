#ifndef ABSTRACT_SHAPE_H__
#define ABSTRACT_SHAPE_H__

#include <SFML/Graphics.hpp>

namespace bricks {

class AbstractShape {
public:
    virtual void SetShapeColor(const sf::Color& a_color) = 0;
    virtual void SetShapePosition(float a_x, float a_y) = 0;

    virtual ~AbstractShape() = default;

protected:
    AbstractShape() = default;
    AbstractShape(const AbstractShape&) = default;
    AbstractShape& operator=(const AbstractShape&) = default;    

};


} //bricks

#endif //ABSTRACT_SHAPE_H__