#include "Level.hpp"
#include <vector>



std::vector<sf::Sprite> Level::getImages(){
    return this->images;
}

void Level::addImage(sf::Sprite sprite){
    // sprite.setTexture(texture);
    this->images.push_back(sprite);
}

Level::Level(){

}

Level::Level(std::string name){

}

std::vector<Dummy> Level::getEntities(){
    return this->entities;
};