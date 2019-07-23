#include "LevelManager.hpp"
#include "./Level.hpp"

#include <stack>
#include <iostream>

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


void LevelManager::drawLevel(Level level, sf::RenderWindow &window){
    for(int i = 0; i < level.getImages().size(); i++){
        // sf::Sprite sprite = level.getImages().at(i);
        window.draw(level.getImages().at(i));
    }

    for(int i = 0; i < level.getEntities().size(); i++){
        // std::cout << level.getEntities().size() << std::endl;
        level.getEntities().at(i).ani.play(level.getEntities().at(i).walk());
        window.draw(level.getEntities().at(i).ani);
    }
}


