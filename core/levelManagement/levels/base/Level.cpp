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

void Level::addEntitiy(Dummy dummy){
    this->entities.push_back(dummy);
}

void Level::draw(sf::RenderWindow &window){
    // std::cout << std::to_string(this->tm.length());
    // Dummy dummy("dummy", "/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", 150, 150, this->tm);
    if(entities.size() > 0){
    entities.at(0).ani.play(entities.at(0).walk());
    window.draw(entities.at(0).ani);
    }
    // sf::Sprite road;
    // road.setTexture(this->sky);
    // road.setScale(800 / road.getLocalBounds().width, 600/ road.getLocalBounds().height);
    // window.draw(road);
    // window.draw(dummy.ani);
}