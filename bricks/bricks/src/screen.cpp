#include "screen.hpp"

namespace bricks {

Screen::Screen(size_t a_width, size_t a_height, const char* a_screenNane)
: m_window(sf::VideoMode(a_width, a_height), a_screenNane)
{}



} //bricks