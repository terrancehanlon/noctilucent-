#ifndef LEVELMANAGER_INCLUDE
#define LEVELMANAGER_INCLUDE

#include <stack> 
#include "./Level.hpp"

class LevelManager {
    private:
        std::stack<Level> levelStack;
        TextureManager tm;
        void initiateLevels();

    public:
        LevelManager(TextureManager tm);
        std::stack<Level> getLevelStack();
        void setLevelStack(std::stack<Level> levelStack);
        void drawLevel(Level level, sf::RenderWindow &window);
        
};

#endif