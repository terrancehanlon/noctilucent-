#ifndef LEVELMANAGER_INCLUDE
#define LEVELMANAGER_INCLUDE

#include <stack> 
#include "./Level.hpp"

class LevelManager {
    private:
        std::stack<Level> levelStack;
        TextureManager tm;
        void initiateLevels();
        bool init = true;

    public:
        LevelManager(TextureManager tm);
        std::stack<Level> getLevelStack();
        void setLevelStack(std::stack<Level> levelStack);
        Level drawLevel(Level level, sf::RenderWindow &window, sf::Time frameTime, sf::Vector2f);
        void updateLevel(Level level, sf::RenderWindow &window, sf::Time frameTime);
        
};

#endif