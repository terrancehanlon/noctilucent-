#include "Level.hpp"
#include <vector>
#include <iostream>
#include <iomanip>




std::vector<sf::Sprite> Level::getImages(){
    return this->images;
}

void Level::addImage(sf::Sprite sprite){
    // sprite.setTexture(texture);
    this->images.push_back(sprite);
}

Level::Level(){

}

Level::Level(std::string name, std::vector<Level::EnemyInfo> enemyTypes){
this->levelTitle = name;
this->enemieTypes = enemyTypes;
// std::cout << this->levelTitle + " type size in level construct " + std::to_string(enemyTypes.size()) << std::endl;
}

std::vector<Dummy> Level::getEntities(){
    return this->entities;
};

void Level::addEntitiy(Dummy dummy){
    this->entities.push_back(dummy);
}

int Level::getEnemyTypeCount(){
    return this->enemieTypes.size();
}

std::vector<Level::EnemyInfo> Level::getEnemyTypes(){
    return this->enemieTypes;
}

void Level::draw(sf::RenderWindow &window, std::vector<Dummy> enemies){
    // std::cout << std::to_string(this->tm.length());
    // Dummy dummy("dummy", "/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", 150, 150, this->tm);
    if(enemies.size() > 0){
    enemies.at(0).ani.play(enemies.at(0).walk());
    window.draw(enemies.at(0).ani);
    }
    // sf::Sprite road;
    // road.setTexture(this->sky);
    // road.setScale(800 / road.getLocalBounds().width, 600/ road.getLocalBounds().height);
    // window.draw(road);
    // window.draw(dummy.ani);
}

std::string Level::getLevelTitle(){
    return this->levelTitle;
}

void Level::setLevelTitle(std::string levelTitle){
    this->levelTitle = levelTitle;
}

void Level::setEnemyTypes(std::vector<EnemyInfo> info){
    this->enemieTypes = info;
}

//984.615385

bool Level::checkIfConstraint(float x, float y){
    for(int i = 0; i < this->constraints.size(); i++){
        std::cout << "CHECKING: " + std::to_string(x) << std::endl;
        //kinda ugly to check this way?
        if(x >= this->constraints.at(i).xRangeStart){
            if(x <= this->constraints.at(i).xRangeDone){
                return true;
            }
        }
        // if(
        //     x >= this->constraints.at(i).xRangeStart && 
        //     x <= this->constraints.at(i).xRangeDone  && 
        //     y >= this->constraints.at(i).yRangeStart &&
        //     y <= this->constraints.at(i).yRangeDone){
        //         std::cout << "CONSTRAINT =======" << std::endl;
        //         return true;
        // }
    }

    return false;
}

void Level::insertConstraint(LevelConstraints constraint){
    this->constraints.push_back(constraint);
}

