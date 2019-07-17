#include "../base/Level.hpp"
#include <string>
#include "LevelTwo.hpp"
// #include <SFML/Graphics"
#include <SFML/Graphics.hpp>
#include <iostream>
void LevelTwo::setTextures(){
    // this->sky.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/sky.png",  sf::IntRect(0,0, 800, 600));
    this->road.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/sky.png",sf::IntRect(0,0, 800, 600));
    this->character.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", sf::IntRect(0, 0, 10, 10));
}  

void LevelTwo::setSprites(){
    // sf::Sprite skySprite;
    sf::Sprite road;
    // skySprite.setTexture(this->sky);
    road.setTexture(this->road);
    // skySprite.setScale(800 / skySprite.getLocalBounds().width, 600/ skySprite.getLocalBounds().height);
    road.setScale(800 / road.getLocalBounds().width, 600/ road.getLocalBounds().height);
    // this->addImage(skySprite);
    this->addImage(road);

}

LevelTwo::LevelTwo(){
    Level("level two");
    // skySprite.setTexture(this->sky);
    // sf::Sprite skySprite;
    std::cout <<"level two" <<std::endl;
    // sf::Sprite road;
    this->setTextures();
    this->setSprites();
    this->setEnemies();
}   

void LevelTwo::setEnemies(){
    std::cout <<"creating dummy" <<std::endl;
    Dummy dummy("dummy", "/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", 150, 150);
    dummy.ani.play(dummy.walk());
    this->addEntitiy(dummy.ani);
    // this->entities.push_back(dummy);
    std::cout <<this->entities.size() <<std::endl;
}

sf::Texture LevelTwo::getTexture(){
    return this->character;
}

void LevelTwo::setTexture(sf::Texture texture){
    this->character = texture;
}