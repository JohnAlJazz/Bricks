#include "gray_image.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>

typedef experis::gfx::GrayImage GrayImage;
typedef std::vector<std::vector<int>> Matrix;

static Matrix InitMatrix(size_t a_width, size_t a_height, size_t a_initial) {
    return Matrix(a_height, std::vector<int>(a_width, a_initial));    
}

GrayImage::GrayImage(size_t a_width, size_t a_height) noexcept
: m_width(a_width)
, m_height(a_height)
, m_colorDepth(15)
, m_PixelValue(15)
, m_matrix(InitMatrix(a_width, a_height, m_PixelValue)) {}

GrayImage::GrayImage(size_t a_width, size_t a_height, size_t a_colorDepth) noexcept
: m_width(a_width)
, m_height(a_height)
, m_colorDepth(a_colorDepth)
, m_PixelValue(a_colorDepth) 
, m_matrix(InitMatrix(a_width, a_height, m_PixelValue)) {}


GrayImage::GrayImage(size_t a_width, size_t a_height, size_t a_colorDepth, size_t a_initValue) noexcept
: m_width(a_width)
, m_height(a_height)
, m_colorDepth(a_colorDepth)
, m_PixelValue(a_initValue)
, m_matrix(InitMatrix(a_width, a_height, a_initValue)) {}

struct OperatorAnd {   
    int operator()(int a_first, int a_second) {return a_first & a_second;}
};

struct OperatorOr {
    int operator()(int a_first, int a_second) {return a_first | a_second;}
};    

struct OperatorXor {
    int operator()(int a_first, int a_second) {return a_first ^ a_second;}
};

template <typename F>
void CombinedImage(GrayImage& a_first, const GrayImage& a_second, F a_functionObject) { 
    if(a_first.GetWidth() != a_second.GetWidth() || a_first.GetHeight() != a_second.GetHeight()) {
        return;
    }  
    Matrix matrix = InitMatrix(a_first.GetWidth(), a_first.GetHeight(), a_first.GetPixelValue());
    for(size_t i = 0; i < a_first.GetWidth(); ++i) {
        for(size_t j = 0; j < a_first.GetHeight(); ++j) {
            matrix[i][j] = a_functionObject(a_first.GetPixelValue(), a_second.GetPixelValue());
        }        
    }
    a_first.SetMatrix(matrix);   
} 

GrayImage& GrayImage::operator&=(const GrayImage& a_other) noexcept {       
    CombinedImage(*this, a_other, OperatorAnd{});    
    m_PixelValue = a_other.GetPixelValue();
       return *this;
}

GrayImage& GrayImage::operator|=(const GrayImage& a_other) noexcept {   
    CombinedImage(*this, a_other, OperatorOr{});       
    m_PixelValue = a_other.GetPixelValue();    
    return *this;   
}

GrayImage& GrayImage::operator^=(const GrayImage& a_other) noexcept {    
    CombinedImage(*this, a_other, OperatorXor{});
    m_PixelValue = a_other.GetPixelValue();
    return *this;   
}


void GrayImage::PrintMatrix() {
    for(size_t i = 0; i < m_matrix.size(); ++i) {
        for(size_t j = 0; j < m_matrix[i].size(); ++j) {
            std::cout << m_matrix[i][j] << " ";            
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void GrayImage::Clear(size_t a_color) noexcept {
    // Matrix m = InitMatrix(m_width, m_height, a_color);
    // SetMatrix(m);
    m_PixelValue = a_color;
}

void GrayImage::SaveImageToFile(const char* a_file) {
    std::ofstream imageToFile; 
    imageToFile.open(a_file);
    imageToFile << "P2" << '\n' << m_height << " " << m_width << '\n' << m_colorDepth << '\n';
    for(size_t i = 0; i < m_matrix.size(); ++i) {
        for(size_t j = 0; j < m_matrix[i].size(); ++j) {
            imageToFile << m_matrix[i][j] << " ";            
        }
        imageToFile << '\n';
    }
    imageToFile.close();
}

// static void ReadImageFromFile() {
//     // string line;
//     std::ifstream myfile ("example.txt");
//     if (myfile.is_open())
//     {
//         while ( getline (myfile,line) )
//         {
//         cout << line << '\n';
//         }
//         myfile.close();
        // }
//   
// }
