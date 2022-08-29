#ifndef GRAPHS_H__
#define GRAPHS_H__

#include "graphic_shape.hpp"
#include <vector>


class Point {
public:
    Point(int a_x, int a_y);

    int m_x;
    int m_y;
};

class Line : public AbstractGraphicShape {
public:
    Line() = default;
    Line(Point a_p1, Point a_p2) noexcept;
    Line(const Line& a_line) = default;
    Line& operator=(const Line& a_line) = default;
    ~Line() = default;

    void Draw(gfx::GrayImage& a_img, int width, int color);
    
private:
    Point m_p1;
    Point m_p2;        
};


class Circle : public AbstractGraphicShape {
public:
    Circle() = default;
    Circle(int a_radius, Point a_center) noexcept;
    Circle(const Circle& a_circle) = default;
    Circle& operator=(const Circle& a_circle) = default;
    ~Circle() = default;

    void Draw(gfx::GrayImage& a_image, int a_width, int a_color);
    
private:
    int m_radius; 
    Point m_center;     
};


class Square : public AbstractGraphicShape {
public:
    Square() = default;
    Square(Point a_point, int a_sideL);
    Square(const Square& a_square) = default;
    Square& operator=(const Square& a_square) = default;
    ~Square() = default;    

    void Draw(gfx::GrayImage&, int width, int color);
    
private:
    Point m_point;
    int m_sideLength;    
};


class ComplexShape : public AbstractGraphicShape {
public:
    ComplexShape() = default;
    ComplexShape(const ComplexShape& a_square) = default;
    ComplexShape& operator=(const ComplexShape& a_square) = default;
    ~ComplexShape() = default;

    void Add(AbstractGraphicShape& a_shape);
    void Draw(gfx::GrayImage& a_img, int a_width, int a_color);
   
private:
    std::vector<AbstractGraphicShape*> m_shapes;
};

#endif //GRAPHS_H__



