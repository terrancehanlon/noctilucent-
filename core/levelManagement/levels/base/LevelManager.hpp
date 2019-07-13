#ifndef LEVELMANAGER_INCLUDE
#define LEVELMANAGER_INCLUDE

#include <stack> 
#include "./Level.hpp"

class LevelManager {
    private:
        std::stack<Level> levelStack;
        void initiateLevels();

    public:
        LevelManager();
        std::stack<Level> getLevelStack();
        void setLevelStack(std::stack<Level> levelStack);
        void drawLevel(Level level, sf::RenderWindow window);
        
};

#endif