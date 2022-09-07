#ifndef GAME_EXECUTER_H__
#define GAME_EXECUTER_H__

#include "level.hpp"

#include <vector>
#include <fstream>

namespace bricks {

class GameExecuter {
public:
    GameExecuter(const char* a_gameFile);
    GameExecuter(const GameExecuter&) = default;
    GameExecuter& operator=(const GameExecuter&) = default;
    ~GameExecuter() = default;
    void Execute(size_t a_width, size_t a_height, const char* a_screenNane);
    
private:
    std::vector<Level> m_levels;
private:
    typedef std::vector<Level> Levels;
    Levels RenderFileToLevel(const char* a_gameFile);
};


} //bricks


#endif //GAME_EXECUTER_H__