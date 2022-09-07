#include "level.hpp"
#include <iostream>

namespace bricks{

static Paddle InitPaddle(std::ifstream& a_level) {

    float xVel;
    float yVel;
    float xPos;
    float yPos;
    float width;
    float height;

    a_level >> xVel >> yVel >> xPos >> yPos >> width >> height;   
    sf::Color color(sf::Color::Green); 
    return Paddle{xVel, yVel, color, xPos, yPos, width, height};     
}

static Rectangle InitBrick(std::ifstream& a_level) {
   
    float xPos;
    float yPos;
    float width;
    float height;

    a_level >> xPos >> yPos >> width >> height;   
    sf::Color color(sf::Color::Red); 
    return Rectangle(color, xPos, yPos, width, height);     
}


static BreakableBrick InitBreakableBrick(std::ifstream& a_level) {
   
    int strength;
    float xPos;
    float yPos;
    float width;
    float height;

    a_level >> strength >> xPos >> yPos >> width >> height;   
    sf::Color color(sf::Color::White); 
    return BreakableBrick(strength, color, xPos, yPos, width, height);     
}

static Ball InitBall(std::ifstream& a_level) {
   
    float xVel;
    float yVel;
    float xPos;
    float yPos;
    float radius;    

    a_level >> xVel >> yVel >> radius >> xPos >> yPos;   
    sf::Color color(sf::Color::Blue); 
    return Ball(xVel, yVel, radius, color, xPos, yPos);     
}


Level::Level(std::ifstream& a_level)
: m_paddle(InitPaddle(a_level))
, m_brick(InitBrick(a_level))
, m_breakableBrick(InitBreakableBrick(a_level))
, m_ball(InitBall(a_level))
{}



std::vector<Shape> Level::Shapes() {

    std::vector<Shape> shapesOfLevel;    
    shapesOfLevel.push_back(m_paddle);
    shapesOfLevel.push_back(m_brick);
    shapesOfLevel.push_back(m_breakableBrick);
    shapesOfLevel.push_back(m_ball);
    return shapesOfLevel;
}


} //bricks