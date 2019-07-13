#include "../base/Level.hpp"
#include <string>
#include "LevelOne.hpp"
// #include <SFML/Graphics"
#include <SFML/Graphics.hpp>
void LevelOne::setTextures(){
    this->sky.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/sky.png",  sf::IntRect(0,0, 800, 600));
    this->road.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/road.png",sf::IntRect(0,0, 800, 600));
}   

void LevelOne::setSprites(){
    sf::Sprite skySprite;
    sf::Sprite road;
    skySprite.setTexture(this->sky);
    road.setTexture(this->road);
    skySprite.setScale(800 / skySprite.getLocalBounds().width, 600/ skySprite.getLocalBounds().height);
    road.setScale(800 / road.getLocalBounds().width, 600/ road.getLocalBounds().height);
    this->addImage(skySprite);
    this->addImage(road);

}

LevelOne::LevelOne(std::string nameOfLevel){
    Level(name);
    // skySprite.setTexture(this->sky);
    // sf::Sprite skySprite;
    // sf::Sprite road;
    this->setTextures();
    this->setSprites();
}   