#ifndef GRAY_SHAPE_H
#define GRAY_SHAPE_H

#include "gray_image.hpp"


class AbstractGraphicShape {
public:
    virtual~AbstractGraphicShape() = default;
    virtual void Draw(gfx::GrayImage& a_img, int a_width, int a_color) = 0;     
protected:
    AbstractGraphicShape() = default;
    AbstractGraphicShape(const AbstractGraphicShape& a_abs) = default;
    AbstractGraphicShape& operator=(const AbstractGraphicShape& a_abs) = default;
};

#endif //GRAY_SHAPE_H

