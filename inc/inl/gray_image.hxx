#ifndef GRAY_IMAGE_HXX
#define GRAY_IMAGE_HXX

typedef int PixelType;
typedef std::vector<PixelType> Matrix;

inline int gfx::GrayImage::GetHeight() const noexcept{return m_height;}

inline int gfx::GrayImage::GetWidth() const noexcept {return m_width;}

inline int gfx::GrayImage::GetColorDepth() const noexcept{return m_colorDepth;}

inline int gfx::GrayImage::GetPixelValue() const noexcept{return m_PixelValue;}

inline Matrix gfx::GrayImage::GetMatrix() const noexcept {return m_matrix;}

inline void gfx::GrayImage::SetMatrix(Matrix a_matrix) noexcept {m_matrix = a_matrix;}

inline void gfx::GrayImage::Clear() noexcept {Clear(0);}

inline gfx::GrayImage gfx::GrayImage::operator&(const GrayImage& a_other) const noexcept {
    GrayImage img(*this);
    return img &= a_other;
}
inline gfx::GrayImage gfx::GrayImage::operator|(const GrayImage& a_other) const noexcept {
    GrayImage img(*this);
    return img |= a_other;
}

inline gfx::GrayImage gfx::GrayImage::operator^(const GrayImage& a_other) const noexcept {
    GrayImage img(*this);
    return img ^= a_other;
}

inline gfx::PixelType& gfx::GrayImage::at(int a_i, int a_j) {
    return m_matrix[m_width * a_j + a_i];
}

inline gfx::PixelType const& gfx::GrayImage::at(int a_i, int a_j) const {
    return m_matrix[m_width * a_j + a_i];
}

inline bool gfx::operator==(const gfx::GrayImage& a_first, const gfx::GrayImage& a_second) {
    return a_first.GetColorDepth() == a_second.GetColorDepth() && a_first.GetMatrix() == a_second.GetMatrix();
}
inline bool gfx::operator!=(const gfx::GrayImage& a_first, const gfx::GrayImage& a_second) {
    return !(a_first == a_second);
}


#endif //