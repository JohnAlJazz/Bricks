#include "gray_image.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>

typedef gfx::GrayImage GrayImage;
typedef std::vector<int> Matrix;

static Matrix InitMatrix(int a_width, int a_height, int a_initial) {
    return Matrix(a_width * a_height, a_initial);    
}

GrayImage::GrayImage(int a_width, int a_height, int a_colorDepth) noexcept
: m_width(a_width)
, m_height(a_height)
, m_colorDepth(a_colorDepth)
, m_PixelValue(a_colorDepth) 
, m_matrix(InitMatrix(a_width, a_height, 0)) {}


GrayImage::GrayImage(int a_width, int a_height, int a_colorDepth = 15, int a_initValue = 15) noexcept
: m_width(a_width)
, m_height(a_height)
, m_colorDepth(a_colorDepth)
, m_PixelValue(a_initValue)
, m_matrix(InitMatrix(a_width, a_height, a_initValue)) {}


template <typename F>
void CombinedImage(GrayImage& a_img, F a_functionObject) {      
    int w = a_img.GetWidth();
    int h = a_img.GetHeight();
    for(int i = 0; i < w; ++i) {
        for(int j = 0; j < h; ++j) {
            a_functionObject(i, j);
        }        
    }       
} 

GrayImage& GrayImage::operator&=(const GrayImage& a_other) noexcept { 
    struct AndOperator {
        GrayImage& a_this;
        GrayImage const& a_other;
        void operator()(int i, int j) {
           a_this.at(i, j) &= a_other.at(i, j); 
        }
    };
    CombinedImage(*this, AndOperator{*this, a_other});    
    m_PixelValue = a_other.GetPixelValue();
    return *this;
}

GrayImage& GrayImage::operator|=(const GrayImage& a_other) noexcept {  
    struct OrOperator {
        GrayImage& a_this;
        GrayImage const& a_other;
        void operator()(int i, int j) {
            a_this.at(i, j) |= a_other.at(i ,j);
        }
    };
    CombinedImage(*this, OrOperator{*this, a_other});       
    m_PixelValue = a_other.GetPixelValue();    
    return *this;   
}

GrayImage& GrayImage::operator^=(const GrayImage& a_other) noexcept { 
    struct XorOperator {
        GrayImage& a_this;
        GrayImage const& a_other;
        void operator()(int i, int j) {
            a_this.at(i, j) ^= a_other.at(i, j);
        }
    };   
    CombinedImage(*this, XorOperator{*this, a_other});
    m_PixelValue = a_other.GetPixelValue();
    return *this;   
}
 
void GrayImage::PrintMatrix() {
    for(int i = 0; i < m_height; ++i) {
        for(int j = 0; j < m_width; ++j) {
            std::cout << at(i, j) << " ";            
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void GrayImage::Clear(int a_color) noexcept {    
    struct ChangeColor {
        GrayImage& a_this;
        int color;
        void operator()(int i, int j) {
            a_this.at(i, j) = color;
        }
    };
    CombinedImage(*this, ChangeColor{*this, a_color});   
}


void GrayImage::SaveImageToFile(const char* a_file) {
    std::ofstream imageToFile; 
    imageToFile.open(a_file);
    imageToFile << "P2" << '\n' << m_height << " " << m_width << '\n' << m_colorDepth << '\n';
    for(int i = 0; i < m_width; ++i) {
        for(int j = 0; j < m_height; ++j) {
            imageToFile << at(i, j) << " ";            
        }
        imageToFile << '\n';
    }    
}

template <typename F>
static void PixelActions(GrayImage& a_img, F a_objFunc) {
    int w = a_img.GetWidth();
    int h = a_img.GetHeight();
    for(int i = 0; i < w; ++i) {
        for(int j = 0; j < h; ++j) {
            a_objFunc(i, j);
        }        
    } 
}

GrayImage gfx::ReadImageFromFile(const char* a_image) {
    std::ifstream file(a_image);
    std::string GrayMap;
    file >> GrayMap;
    // if(GrayMap != "P2" || GrayMap != "p2") {
    //     throw::std::   
    // }
    int width = 0;
    int height = 0;
    int depth = 0;   
    file >> width >> height >> depth;
    GrayImage img(width, height, depth, 0);

    struct CopyFromFile {
        GrayImage& m_image;
        std::ifstream& m_buffer;        
        void operator()(int i, int j) {
            int pixel = 0;
            m_buffer >> pixel;
            m_image.at(i, j) = pixel;
        }
    };
    PixelActions(img, CopyFromFile{img, file});   
    return img;  
}










