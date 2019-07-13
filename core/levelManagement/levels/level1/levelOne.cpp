#include "../base/Level.hpp"
#include <string>
#include "LevelOne.hpp"
// #include <SFML/Graphics"
#include <SFML/Graphics.hpp>
void LevelOne::setUpTextures(){
    this->texture1.loadFromFile("../../../assets/sky.png");
};

LevelOne::LevelOne(std::string nameOfLevel){
    Level(name);
    sf::Sprite sprite;
    sprite.setTexture(this->texture1);
    this->setUpTextures();
    this->addImage(sprite);
}   