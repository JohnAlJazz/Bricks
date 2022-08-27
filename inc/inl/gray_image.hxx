#ifndef GRAY_IMAGE_HXX
#define GRAY_IMAGE_HXX

typedef int PixelType;
typedef std::vector<PixelType> Matrix;

inline int GrayImage::GetHeight() const noexcept{return m_height;}

inline int GrayImage::GetWidth() const noexcept {return m_width;}

inline int GrayImage::GetColorDepth() const noexcept{return m_colorDepth;}

inline int GrayImage::GetPixelValue() const noexcept{return m_PixelValue;}

inline Matrix GrayImage::GetMatrix() const noexcept {return m_matrix;}

inline void GrayImage::SetMatrix(Matrix a_matrix) noexcept {m_matrix = a_matrix;}


inline GrayImage GrayImage::operator&(const GrayImage& a_other) const noexcept {
    GrayImage img(*this);
    return img &= a_other;
}
inline GrayImage GrayImage::operator|(const GrayImage& a_other) const noexcept {
    GrayImage img(*this);
    return img |= a_other;
}

inline GrayImage GrayImage::operator^(const GrayImage& a_other) const noexcept {
    GrayImage img(*this);
    return img ^= a_other;
}

inline PixelType& GrayImage::at(int a_i, int a_j) {
    return m_matrix[m_height * a_j + a_i];
}

inline PixelType const& GrayImage::at(int a_i, int a_j) const {
    return m_matrix[m_height * a_j + a_i];
}

inline bool operator==(const GrayImage& a_first, const GrayImage& a_second) {
    return a_first.GetColorDepth() == a_second.GetColorDepth() && a_first.GetMatrix() == a_second.GetMatrix();
}
inline bool operator!=(const GrayImage& a_first, const GrayImage& a_second) {
    return !(a_first == a_second);
}


#endif //