#include "LevelManager.hpp"
#include "./Level.hpp"

#include <stack>


LevelManager::LevelManager(){
    std::stack<Level> levelStack;
    this->levelStack = levelStack;
}

std::stack<Level> LevelManager::getLevelStack(){
    return this->levelStack;
}

void LevelManager::setLevelStack(std::stack<Level> levelStack){
    this->levelStack = levelStack;
}


void LevelManager::drawLevel(Level level, sf::RenderWindow window){
    for(int i = 0; i < level.getImages().size(); i++){
        // sf::Sprite sprite = level.getImages().at(i);
        window.draw(level.getImages().at(i));
    }
}


