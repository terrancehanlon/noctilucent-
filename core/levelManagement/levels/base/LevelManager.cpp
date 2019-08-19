#include "LevelManager.hpp"
#include "./Level.hpp"

#include <stack>
#include <iostream>
#include <string>
#include "../../../../entities/headers/Player.hpp"
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
                // HoodedOccult hoodedOccult(level.getEnemyTypes().at(i).xPosition,
                // level.getEnemyTypes().at(i).yPosition, tm);
                float x = level.getEnemyTypes().at(i).xPosition;
                float y = level.getEnemyTypes().at(i).yPosition;
                HoodedOccult* h = new HoodedOccult(x, y, tm);
                h->ani.play(h->idle());
                level.occ.push_back(h);
                // window.draw(hoodedOccult.ani);
            }  
            else if(level.getEnemyTypes().at(i).typeName.compare("player") == 0){
                Player pl("name","/home/terrance/Desktop/games2/noctilucent-/assets/pixel.png");
                level.players.push_back(new Player{"name","/home/terrance/Desktop/games2/noctilucent-/assets/pixel.png"});
                window.draw(pl.ani);
            }                                                                                        
        }
    }
    return level;
}
//losing reference because im storing in vector which copies the object
void LevelManager::updateLevel(Level level, sf::RenderWindow &window, sf::Time frameTime, Animation animation){
        bool hasEnemies = false;
        for(int i = 0; i < level.getImages().size(); i++){
        window.draw(level.getImages().at(i));
    }

    for(int i = 0; i < level.occ.size(); i++){
        // std::cout << "level occ" << std::endl;
        level.occ.at(i)->ani.play(animation);
        level.occ.at(i)->ani.update(frameTime);
        window.draw(level.occ.at(i)->ani);   
    }

    for(int i = 0; i < level.players.size(); i++){
        if(init)level.players.at(i)->ani.play(level.players.at(i)->walk());
        level.players.at(i)->ani.update(frameTime);
        window.draw(level.players.at(i)->ani);
    }
}


