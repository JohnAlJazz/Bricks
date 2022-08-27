#ifndef GRAY_IMAGE_H__
#define GRAY_IMAGE_H__

#include <stddef.h>/*int*/
#include <vector>
#include <stdio.h>

namespace gfx{



class GrayImage{
public:

    typedef int PixelType;
    typedef std::vector<PixelType> Matrix;
    GrayImage(int a_width, int a_height, int a_colorDepth = 15)  noexcept;    
    GrayImage(int a_width, int a_height, int a_colorDepth, int a_initValue) noexcept;
    GrayImage(const GrayImage& a_other) = default;
    GrayImage& operator=(const GrayImage& a_other) = default;
    ~GrayImage() = default; 

    int GetHeight() const noexcept;
    int GetWidth() const noexcept;
    int GetColorDepth() const noexcept;
    int GetPixelValue() const noexcept;
    Matrix GetMatrix() const noexcept;
    void SetMatrix(Matrix a_matrix) noexcept;


    PixelType& at(int a_h, int a_w);
    PixelType const& at(int a_h, int a_w) const;

    void Clear(int a_color = 0) noexcept;

    GrayImage& operator&=(const GrayImage& a_other) noexcept;
    GrayImage& operator|=(const GrayImage& a_other) noexcept;
    GrayImage& operator^=(const GrayImage& a_other) noexcept;
    GrayImage operator&(const GrayImage& a_other) const noexcept;
    GrayImage operator|(const GrayImage& a_other) const noexcept;
    GrayImage operator^(const GrayImage& a_other) const noexcept;

    void SaveImageToFile(const char* a_file);    
    void PrintMatrix();

private:
    int m_width;
    int m_height;
    int m_colorDepth;
    int m_PixelValue;
    Matrix m_matrix;    
};

GrayImage ReadImageFromFile(const char* a_image);

bool operator==(const GrayImage& a_first, const GrayImage& a_second); 
bool operator!=(const GrayImage& a_first, const GrayImage& a_second);


#include "inl/gray_image.hxx"

} //gfx

#endif //