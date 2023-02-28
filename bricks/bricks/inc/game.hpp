#ifndef GAME_H__
#define GAME_H__

#include <iostream>

#include "../inc/gameExecuter.hpp"

namespace bricks {

class Game {
public:
    Game(const char* a_gameFile);
   
    Game(const Game&) = default;
    Game& operator=(const Game&) = default;
    ~Game() = default;
   
    void Run() {
        
        m_executer.Execute(800, 800, "bricks");
    }

private:
    GameExecuter m_executer;
};


} //bricks

#endif //GAME_H__