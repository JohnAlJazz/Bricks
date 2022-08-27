#include "graphs.hpp" 
#include <math.h> /*abs*/
#include <iostream>
#include <stddef.h> /*size_t*/
#include <vector>

Line::Line(Point a_p1, Point a_p2) noexcept 
: m_p1(a_p1) 
, m_p2(a_p2) {}

void Line::Draw(gfx::GrayImage& a_image, int a_width, int a_color) {
    int Xdelta = m_p2.m_x - m_p1.m_x;
    int Ydelta = m_p2.m_y - m_p1.m_y; 
    for(int i = 0; i < a_width; ++i) {
        if(abs(Xdelta) >= (Ydelta)) {
            for(int x = m_p1.m_x; x < m_p2.m_x; ++x) {
                int y = m_p1.m_y + i + Ydelta * (x - m_p1.m_x) / Xdelta;
                a_image.at(y, x) = a_color;
            }
        }      
        else {
             for(int y = m_p1.m_y; y < m_p2.m_y; ++y) {
                int x = m_p1.m_x + i + Xdelta * (y - m_p1.m_y) / Ydelta;
                a_image.at(y, x) = a_color;
            }
        }
    }     
    a_image.SaveImageToFile("line");
}

void Line::Erase(gfx::GrayImage& a_img) {
    a_img.Clear(); 
    a_img.SaveImageToFile("line");   
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
    a_image.SaveImageToFile("circle");
}

void Circle::Erase(gfx::GrayImage& a_img){
    a_img.Clear();
    a_img.SaveImageToFile("circle");
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
    a_image.SaveImageToFile("square");
}

void Square::Erase(gfx::GrayImage& a_img){
    a_img.Clear();
    a_img.SaveImageToFile("square");
}


ComplexShape::ComplexShape(const std::vector<Line> a_lines, const std::vector<Circle> a_circles, const std::vector<Square> a_squares)
: m_lines(a_lines)
, m_circles(a_circles)
, m_squares(a_squares) {}


void ComplexShape::Draw(gfx::GrayImage& a_image, int a_width, int a_color) {    
    size_t linesLength = m_lines.size();
    size_t circlesLength = m_circles.size();
    size_t squaresLength = m_squares.size(); 
    
    for(size_t i = 0; i < linesLength; ++i) {
        m_lines[i].Draw(a_image, a_width, a_color);
    }
    for(size_t i = 0; i < circlesLength; ++i) {
        m_circles[i].Draw(a_image, a_width, a_color);
    }
    for(size_t i = 0; i < squaresLength; ++i) {
        m_squares[i].Draw(a_image, a_width, a_color);
    }
    a_image.SaveImageToFile("complex shape");
}

void ComplexShape::Erase(gfx::GrayImage& a_img){
     size_t linesLength = m_lines.size();
    size_t circlesLength = m_circles.size();
    size_t squaresLength = m_squares.size(); 
    for(size_t i = 0; i < linesLength; ++i) {
        m_lines[i].Erase(a_img);
    }
    for(size_t i = 0; i < circlesLength; ++i) {
        m_circles[i].Erase(a_img);
    }
    for(size_t i = 0; i < squaresLength; ++i) {
        m_squares[i].Erase(a_img);
    } 
    a_img.SaveImageToFile("complex shape");
}






// void drawCircle(gfx::GrayImage& a_image, int xc, int yc, int x, int y, int a_color) {
//     a_image.at(xc+x, yc+y) = a_color;
//     a_image.at(xc-x, yc+y) = a_color;
//     a_image.at(xc+x, yc-y) = a_color;
//     a_image.at(xc-x, yc-y) = a_color;
//     a_image.at(xc+y, yc+x) = a_color;
//     a_image.at(xc-y, yc+x) = a_color;
//     a_image.at(xc+y, yc-x) = a_color;
//     a_image.at(xc-y, yc-x) = a_color;
// }


