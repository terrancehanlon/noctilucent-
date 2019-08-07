#include "LevelManager.hpp"
#include "./Level.hpp"

#include <stack>
#include <iostream>
// #include "../../../entities/headers/HoodedOccult.hpp"

LevelManager::LevelManager(TextureManager tm){
    this->tm = tm;
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
    // std::cout << level.getLevelTitle() << std::endl;
    for(int i = 0; i < level.getImages().size(); i++){
        // sf::Sprite sprite = level.getImages().at(i);
        window.draw(level.getImages().at(i));
    }

    // for(int i = 0; i < level.getEntities().size(); i++){
    //     // std::cout << dummy.<< std::endl;
    //     Dummy dummy = level.getEntities().at(i);
    //     dummy.ani.play(dummy.walk());
    //     window.draw(dummy.ani);
    // }
    // std::cout << "ENEMY TYPE COUNT: " + std::to_string(level.getEnemyTypeCount()) << std::endl;
    if(level.getEnemyTypeCount() > 0){
        for(int i = 0; i < level.getEnemyTypes().size(); i++){
            if(level.getEnemyTypes().at(i).typeName.compare("dummy") == 0){
                // for(int j = 0; j < level.getEnemyTypes().at(i).count; j++){
                //     Dummy dummy("dummy", "/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", 250, 150, this->tm);
                //     dummy.ani.play(dummy.walk());
                //     window.draw(dummy.ani);
                // }
            }
            else if(level.getEnemyTypes().at(i).typeName.compare("hooded-occult") == 0){
                HoodedOccult hoodedOccult(level.getEnemyTypes().at(i).xPosition,
                 level.getEnemyTypes().at(i).yPosition, tm);
                hoodedOccult.ani.play(hoodedOccult.idle());
                window.draw(hoodedOccult.ani);
            }
        }
    }
}


