#include "breakableBrick.hpp"

inline void BreakableBrick::DecrementStrength() noexcept{
    --m_strength;
}