#ifndef GRAY_SHAPE_H
#define GRAY_SHAPE_H

#include "gray_image.hpp"


class AbstractGraphicShape {
public:
    virtual void Draw(gfx::GrayImage& a_img, int a_width, int a_color) = 0;     
    virtual void Erase(gfx::GrayImage& a_img) = 0;   
};

#endif //GRAY_SHAPE_H