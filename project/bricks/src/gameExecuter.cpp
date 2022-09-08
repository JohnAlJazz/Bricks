#include "gameExecuter.hpp"
#include "screen.hpp"
#include "shape.hpp"

#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

static void ScoreDisplay(sf::RenderWindow& a_window, int& a_score) {
    sf::Text text, scr;
    sf::Font font;
    font.loadFromFile("/home/johnal/Desktop/cpp/fonts/aftermat.ttf");
    if (!font.loadFromFile("/home/johnal/Desktop/cpp/fonts/aftermat.ttf")){
        std::cout << "couldn't load font\n";
    }    
    std::ostringstream score;
    score << a_score;
    text.setFont(font);
    scr.setFont(font);
    text.setString("SCORE");
    scr.setString(score.str());
    text.setPosition(0, 0);
    scr.setPosition(120, 0);
  
    text.setCharacterSize(40);
    scr.setCharacterSize(40);
    text.setFillColor(sf::Color::Cyan);
    scr.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold);
    scr.setStyle(sf::Text::Bold);
    a_window.draw(text);
    a_window.draw(scr);       
}



static void AvoidCollisions(Ball& a_ball, std::vector<BreakableBrick>& a_breakable, int& a_score) {

    struct CheckBrick {
        Ball&  ball;
        BreakableBrick& breakable;
        int& score;
        void operator()() { 
            if(breakable.Strength() == 0 && breakable.IsBroken() == false) {
                breakable.SetShapeColor(sf::Color::Transparent);
                breakable.Break(); 
                score += 10;                                               
            } 

            if((ball.Collision(breakable.GetGlobalBounds())) && (breakable.Strength() > 0)) {                
                breakable.DecrementStrength();
    
                float distanceX = abs(ball.CenterXOfBall() - breakable.CenterXOfBrick());
                float distanceY = abs(ball.CenterYOfBall() - breakable.CenterYOfBrick());
                if((distanceX <= ((breakable.Width() + ball.Diameter()) / 2)))  {
            
                    ball.SetXVelocity();                    
                }
                if((distanceY <= ((breakable.Height() + ball.Diameter()) / 2))){
                                      
                    ball.SetYVelocity();                    
                }
                    
                // if((distanceX <= ((breakable.Width() + ball.Diameter()) / 2)) && (distanceX > (breakable.CenterXOfBrick() / 2))) {
            
                //     ball.SetXVelocity();
                //     std::cout << "HERE\n";
                // }
                // if((distanceY <= ((breakable.Height() + ball.Diameter()) / 2)) && (distanceY > (breakable.CenterYOfBrick() / 2))) {
                                      
                //     ball.SetYVelocity();
                //     std::cout << "HERE22222\n";
                // }
            }
        }
    };
        for(size_t i = 0; i < a_breakable.size(); ++i) {
            CheckBrick check{a_ball, a_breakable[i], a_score};            
            check.operator()();
        }        
}


void GameExecuter::Execute(size_t a_width, size_t a_height, const char* a_screenName) {
    
    sf::Text text;
    Screen screen{a_width, a_height, a_screenName};
    Level level = m_levels[0];        
    int score = 0;
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
        for(size_t i = 0; i < level.m_breakableBrick.size(); ++i) {
            level.m_breakableBrick[i].Draw(screen.m_window);
        }

        ScoreDisplay(screen.m_window, score);  
        AvoidCollisions(level.m_ball, level.m_breakableBrick, score);      
        level.m_paddle.Move(event, a_width);
        level.m_ball.Move(level.m_paddle, a_width, a_height);
           
        screen.m_window.display();         
    }
}




} //bricks