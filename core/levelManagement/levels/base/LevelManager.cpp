#include "LevelManager.hpp"
#include "./Level.hpp"

#include <stack>
#include <iostream>
#include <string>
// #include "../../../entities/headers/HoodedOccult.hpp"

std::vector<HoodedOccult> hoodies;

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

int x = 1;
sf::Clock frameClock;
sf::Time frameTimeClock = frameClock.restart();

Level LevelManager::drawLevel(Level level, sf::RenderWindow &window, sf::Time frameTime, sf::Vector2f movement){
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
            // std::cout << std::to_string(frameTime.asMilliseconds()) << std::endl;
float frameCounter = 0, switchFrame = 100, frameSpeed = 500;
frameCounter += frameSpeed * frameClock.restart().asSeconds();
    
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
                sf::Clock clockFrame;
                sf::Time fTime=clockFrame.restart();
                HoodedOccult hoodedOccult(level.getEnemyTypes().at(i).xPosition,
                level.getEnemyTypes().at(i).yPosition, tm);
                // hoodedOccult.ani.play(hoodedOccult.idle());
                // if(init){
                //     hoodies.push_back(hoodedOccult);
                // }
                // std::cout << std::to_string(frameTime.asSeconds()) << std::endl;
                level.occ.push_back(new HoodedOccult(level.getEnemyTypes().at(i).xPosition,
                level.getEnemyTypes().at(i).yPosition, tm));
                // hoodedOccult.ani.update(frameTime);
                // hoodedOccult.ani.setFrame(hoodedOccult.ani.getFrameTime().asSeconds++);
                // hoodedOccult.ani.move(movement * frameTime.asSeconds());
                // std::cout << std::to_string(frameTime.asMicroseconds()) << std::endl;
                // this->init = false;
                window.draw(hoodedOccult.ani);
            }                                                                                           
        }
    }
    return level;
}
//losing reference because im storing in vector which copies the object
void LevelManager::updateLevel(Level level, sf::RenderWindow &window, sf::Time frameTime){
        sf::Clock clockFrame;
        sf::Time fTime=clockFrame.restart();
        for(int i = 0; i < level.getImages().size(); i++){
        // sf::Sprite sprite = level.getImages().at(i);
        window.draw(level.getImages().at(i));
    }

    for(int i = 0; i < level.occ.size(); i++){
        std::cout << "level occ" << std::endl;
        // level.occ.ge
        // AnimatedSprite spr = level.occ.at(i).ani; 
        // level.occ.at(i).ani.play(level.occ.at(i).idle());
        // hoodies.at(0).ani.play(hoodies.at(0).idle());
        // hoodies.at(0).ani.update(fTime);
        // sf::Time time;
        // time = time.asSeconds + 1000;
        // level.occ.at(i).ani.update(time);   
        // level.occ.at(i).ani.update(fTime);
        level.occ.at(i)->ani.play(level.occ.at(i)->idle());
        level.occ.at(i)->ani.update(frameTime);
        window.draw(level.occ.at(i)->ani);   
        // window.draw(hoodies.at(0).ani);
        // hoodies.pop_back();
    }
}


