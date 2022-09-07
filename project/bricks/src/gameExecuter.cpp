#include "gameExecuter.hpp"
#include "screen.hpp"
#include "shape.hpp"

#include <fstream>
#include <algorithm>
#include <iostream>

namespace bricks{

std::vector<Level> GameExecuter::RenderFileToLevel(const char* a_gameFile){
    std::ifstream levels{a_gameFile};
    Levels vectorOfLevels;      

    while(! levels.eof())
    {
        Level level{levels};
        vectorOfLevels.push_back(level);        
     
    }
    return vectorOfLevels;    
}

GameExecuter::GameExecuter(const char* a_gameFile) 
: m_levels(RenderFileToLevel(a_gameFile))
{}

void GameExecuter::Execute(size_t a_width, size_t a_height, const char* a_screenName) {
    
    Screen screen{a_width, a_height, a_screenName};
    Level level = m_levels[0];        
    while(screen.m_window.isOpen())
    {
        sf::Event event;
        while(screen.m_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                screen.m_window.close();
        }

        screen.m_window.clear();       
        level.m_paddle.Draw(screen.m_window); 
        level.m_ball.Draw(screen.m_window);
        level.m_breakableBrick.Draw(screen.m_window);
        level.m_brick.Draw(screen.m_window);
        level.m_paddle.Move(event, a_width);
        level.m_ball.Move(a_width, a_height);
           
        screen.m_window.display();  
        
    }
}




} //bricks