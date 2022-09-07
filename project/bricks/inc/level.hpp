#ifndef LEVEL_H__
#define LEVEL_H__

#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "abstractShape.hpp"
#include "paddle.hpp"
#include "rectangle.hpp"
#include "breakableBrick.hpp"
#include "ball.hpp"

namespace bricks {

class Level {
public:
    Level(std::ifstream& a_level);

    std::vector<Shape> Shapes();
   

    Paddle m_paddle;
    Rectangle m_brick;
    BreakableBrick m_breakableBrick;    
    Ball m_ball;
};


} //bricks


#endif //LEVEL_H__