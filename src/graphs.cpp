#include "graphs.hpp" 
#include <math.h> /*abs*/
#include <iostream>
#include <stddef.h> /*size_t*/
#include <vector>
#include <algorithm>


Point::Point(int a_x, int a_y)
: m_x(a_x)
, m_y(a_y)
{}


Line::Line(Point a_p1, Point a_p2) noexcept 
: m_p1(a_p1) 
, m_p2(a_p2) 
{}


void Line::Draw(gfx::GrayImage& a_image, int a_width, int a_color) {
    int xdelta = m_p2.m_x - m_p1.m_x;
    int ydelta = m_p2.m_y - m_p1.m_y; 
    for(int i = 0; i < a_width; ++i) {
        if(abs(xdelta) >= (ydelta)) {
            for(int x = m_p1.m_x; x < m_p2.m_x; ++x) {
                int y = m_p1.m_y + i + ydelta * (x - m_p1.m_x) / xdelta;
                a_image.at(y, x) = a_color;
            }
        }      
        else {
             for(int y = m_p1.m_y; y < m_p2.m_y; ++y) {
                int x = m_p1.m_x + i + xdelta * (y - m_p1.m_y) / ydelta;
                a_image.at(y, x) = a_color;
            }
        }
    }     
}



Circle::Circle(int a_radius, Point a_center) noexcept 
: m_radius(a_radius)
, m_center(a_center) {}


void Circle::Draw(gfx::GrayImage& a_image, int a_width, int a_color) { 
    int x = 0;  
    int y = m_radius;  
    a_image.at(m_center.m_y + m_radius, m_center.m_x) = a_color;  
    a_image.at(m_center.m_y - m_radius, m_center.m_x) = a_color;  
    a_image.at(m_center.m_y, m_center.m_x - m_radius) = a_color;  
    a_image.at(m_center.m_y, m_center.m_x + m_radius) = a_color;  
    double p = 5 / 4 - m_radius;  
    while (x<=y)  
    {  
        if(p < 0) {  
            p += (4 * x) + 6;  
        }
        else {  
            p += (2 * (x - y)) + 5;  
            y--;  
        }  
            x++;  
        a_image.at(m_center.m_y + y, m_center.m_x + x) = a_color;  
        a_image.at(m_center.m_y + y, m_center.m_x - x) = a_color;  
        a_image.at(m_center.m_y - y, m_center.m_x + x) = a_color;  
        a_image.at(m_center.m_y - y, m_center.m_x + x) = a_color;  
        a_image.at(m_center.m_y + y, m_center.m_x + x) = a_color;  
        a_image.at(m_center.m_y - y, m_center.m_x + x) = a_color;  
        a_image.at(m_center.m_y + y, m_center.m_x - x) = a_color;  
        a_image.at(m_center.m_y - y, m_center.m_x - x) = a_color;  
    }     
}


Square::Square(Point a_point, int a_sideL)
:m_point(a_point)
, m_sideLength(a_sideL) {}

void Square::Draw(gfx::GrayImage& a_image, int a_width, int a_color) {
    int len = m_sideLength;
    for(int i = 0; i < a_width; ++i){          
        for(int x = 0; x <= len; ++x) {
            a_image.at(m_point.m_y - i, m_point.m_x + x - i) = a_color;
            a_image.at(m_point.m_y + m_sideLength + i,  m_point.m_x + x - i) = a_color; 
            a_image.at(m_point.m_y + x - i, m_point.m_x - i) = a_color;
            a_image.at(m_point.m_y + x - i, m_point.m_x + m_sideLength + i) = a_color;           
        }        
        len += 2;
    }    
}


void ComplexShape::Add(AbstractGraphicShape& a_shape) {
    m_shapes.push_back(&a_shape);
}


void ComplexShape::Draw(gfx::GrayImage& a_image, int a_width, int a_color) {  

    struct DrawShape{
        gfx::GrayImage& img;
        int width;
        int color;
        void operator()(AbstractGraphicShape* a_shape) {
            a_shape->Draw(img, width, color);
        }
    };
    for_each(m_shapes.begin(), m_shapes.end(), DrawShape{a_image, a_width, a_color});   
}



