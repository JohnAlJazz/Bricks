#ifndef SCREEN_H__
#define SCREEN_H__

#include <SFML/Graphics.hpp>

namespace bricks {

class Screen {
public:
    Screen(size_t a_width, size_t a_height, const char* a_screenNane);

    sf::RenderWindow m_window;

};


} //bricks

#endif //SCREEN_H__