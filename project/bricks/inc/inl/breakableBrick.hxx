#include "breakableBrick.hpp"

inline void BreakableBrick::DecrementStrength() noexcept{
    --m_strength;
}

inline float BreakableBrick::CenterXOfBrick() {
    return xPos() + m_width / 2;
}

inline float BreakableBrick::CenterYOfBrick() {
    return yPos() + m_height / 2;
}

inline int BreakableBrick::Strength() {
    return m_strength;
}

inline sf::FloatRect BreakableBrick::GlobalBounds() {
    return m_shape->getGlobalBounds();
}

inline float BreakableBrick::Width() {
    return m_width;
}

inline float BreakableBrick::Height() {
    return m_height;
}

inline bool BreakableBrick::IsBroken() {
    return m_isBroken;
}

inline void BreakableBrick::Break() {
    m_isBroken = true;
}