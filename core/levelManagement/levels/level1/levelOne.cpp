#include "../base/Level.hpp"
#include <string>
#include "LevelOne.hpp"
// #include <SFML/Graphics"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
void LevelOne::setTextures(){
    // this->sky.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/sky.png",  sf::IntRect(0,0, 800, 600));
    this->road.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/start.png");
}   

void LevelOne::setSprites(){
    sf::Sprite skySprite;
    sf::Sprite road;
    
    skySprite.setTexture(this->sky);
    road.setTexture(this->road);
    // skySprite.setScale(800 / skySprite.getLocalBounds().width, 600/ skySprite.getLocalBounds().height);
    // sf::VideoMode::getDesktopMode.
    // sf::VideoMod
    //   std::cout << sf::VideoMode::getDesktopMode().width << ", " << sf::VideoMode::getDesktopMode().height;
    road.setScale(  
                    sf::VideoMode::getDesktopMode().width / road.getLocalBounds().width, 
                    sf::VideoMode::getDesktopMode().height / road.getLocalBounds().height
                 );
    this->addImage(skySprite);
    this->addImage(road);
    this->skySprite = skySprite;
}

LevelOne::LevelOne(){
    std::vector<Level::EnemyInfo> enemyTypes;
    EnemyInfo hoodedOccult;
    hoodedOccult.count = 1;
    hoodedOccult.typeName = "hooded-occult";
    enemyTypes.push_back(hoodedOccult);
    Level("level one", enemyTypes);
    this->setLevelTitle("level one");
    this->setEnemyTypes(enemyTypes);
    // skySprite.setTexture(this->sky);
    // sf::Sprite skySprite;
    // sf::Sprite road;
    this->setTextures();
    this->setSprites();
}   

void LevelOne::moveSky( sf::Vector2f movement){
    this->skySprite.move(movement);
}