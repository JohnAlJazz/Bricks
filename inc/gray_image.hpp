#ifndef GRAY_IMAGE_H__
#define GRAY_IMAGE_H__

#include <stddef.h>/*size_t*/
#include <vector>
#include <stdio.h>


namespace experis{

namespace gfx{

typedef std::vector<std::vector<int>> Matrix;

class GrayImage{
public:
    GrayImage(size_t a_width, size_t a_height) noexcept;
    GrayImage(size_t a_width, size_t a_height, size_t a_colorDepth) noexcept;
    GrayImage(size_t a_width, size_t a_height, size_t a_colorDepth, size_t a_initValue) noexcept;
    GrayImage(const GrayImage& a_other) = default;
    GrayImage& operator=(const GrayImage& a_other) = default;
    ~GrayImage() = default; 

    inline void SetPixelValues(size_t a_values) {m_PixelValue = a_values;};
    inline size_t GetHeight() const noexcept{return m_height;};
    inline size_t GetWidth() const noexcept {return m_width;};
    inline size_t GetColorDepth() const noexcept{return m_colorDepth;};
    inline size_t GetPixelValue() const noexcept{return m_PixelValue;};
    inline Matrix GetMatrix() const noexcept {return m_matrix;};
    inline void SetMatrix(Matrix a_matrix) noexcept {m_matrix = a_matrix;};

    inline void Clear() noexcept {
        Clear(0);
    }
    void Clear(size_t a_color) noexcept;

    GrayImage& operator&=(const GrayImage& a_other) noexcept;
    GrayImage& operator|=(const GrayImage& a_other) noexcept;
    GrayImage& operator^=(const GrayImage& a_other) noexcept;
    inline GrayImage operator&(const GrayImage& a_other) const noexcept {
    GrayImage img(*this); return img &= a_other;}
    inline GrayImage operator|(const GrayImage& a_other) const noexcept {
    GrayImage img(*this); return img |= a_other;}
    inline GrayImage operator^(const GrayImage& a_other) const noexcept {
    GrayImage img(*this); return img ^= a_other;}

    void SaveImageToFile(const char* a_file);
    void PrintMatrix();

private:
    size_t m_width;
    size_t m_height;
    size_t m_colorDepth;
    size_t m_PixelValue;
    Matrix m_matrix;    
};


inline bool operator==(const GrayImage& a_first, const GrayImage& a_second) {
    return a_first.GetColorDepth() == a_second.GetColorDepth() && a_first.GetMatrix() == a_second.GetMatrix();
}
inline bool operator!=(const GrayImage& a_first, const GrayImage& a_second) {
    return !(a_first == a_second);
}

} //gfx

} //experis


#endif //