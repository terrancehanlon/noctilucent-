#include "../base/Level.hpp"
#include <string>
#include "LevelTwo.hpp"
// #include <SFML/Graphics"
#include <SFML/Graphics.hpp>
#include <iostream>
void LevelTwo::setTextures(sf::Texture texture){
    this->sky.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/road-road.png",  sf::IntRect(0,0, 800, 600));
    // texture.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/sky.png",sf::IntRect(0,0, 800, 600));
    // this->road = texture;
    // texture.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", sf::IntRect(0, 0, 10, 10));
    // this->character = texture;
    // this->road.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/sky.png",sf::IntRect(0,0, 800, 600));
    // this->character.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", sf::IntRect(0, 0, 10, 10));
    // setTexture(this->character);
}  

void LevelTwo::setSprites(){
    // sf::Sprite skySprite;
    sf::Sprite road;
    // skySprite.setTexture(this->sky);
    road.setTexture(this->sky);
    // skySprite.setScale(800 / skySprite.getLocalBounds().width, 600/ skySprite.getLocalBounds().height);
    road.setScale(800 / road.getLocalBounds().width, 600/ road.getLocalBounds().height);
    // this->addImage(skySprite);
    this->addImage(road);

}

LevelTwo::LevelTwo(sf::Texture texture, sf::Texture background, TextureManager tm){
    std::vector<Level::EnemyInfo> enemyTypes;
    EnemyInfo enemyInfo;
    enemyInfo.typeName = "dummy";
    enemyInfo.count = 1;
    enemyTypes.push_back(enemyInfo);
    this->tm = tm;  
    Level("level two", enemyTypes);
    this->setLevelTitle("Level two");
    this->setEnemyTypes(enemyTypes);
    // skySprite.setTexture(this->sky);
    // sf::Sprite skySprite;
    // std::cout <<"level two" <<std::endl;
    // sf::Sprite road;
    // this->setTextures(background);
    // this->sky = background;
    this->setTextures(texture);
    this->setSprites();
    this->setEnemies(texture, tm);
    // this->displayEnemies(&window, this->entities.at(0));
}   

void LevelTwo::setEnemies(sf::Texture texture, TextureManager textMan){
    std::cout <<"creating dummy" <<std::endl;
    Dummy dummy("dummy", "/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", 250, 150, this->tm);
    // setTexture(dummy.getTexture());
    // dummy.ani.play(dummy.walk());
    this->addEntitiy(dummy);
    this->setDummy(dummy);
    // this->entities.push_back(dummy);
    std::cout <<this->entities.size() <<std::endl;
}

sf::Texture LevelTwo::getTexture(){
    return this->character;
}

void LevelTwo::setTexture(const sf::Texture& texture){
    this->character = texture;
}

void LevelTwo::displayEnemies(sf::RenderWindow &window){
    std::cout << "Drawing enemies" << std::endl;
    Dummy dummy("dummy", "/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", 150, 150, this->tm);
    dummy.ani.play(dummy.walk());
    setDummy(dummy);
    window.draw(dummy.ani);
}

void LevelTwo::setDummy(Dummy dummy){
    this->dummy = dummy;
}

void LevelTwo::draw(sf::RenderWindow &window){
    sf::Text text;
    sf::Font font;
    font.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/arial.ttf");
    text.setFont(font);
    text.setString("Test");
    text.setCharacterSize(24);
    text.move(100.f, 100.f);    
    window.draw(text);
    // std::cout << std::to_string(this->tm.length());
    Dummy dummy("dummy", "/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", 200, 150, this->tm);
    // dummy.ani.play(dummy.walk())
    std::vector<Dummy> dummies;
    // dummies.push_back(dummy);
    entities.push_back(dummy);
    // Level::draw(window, dummies);
    // std::cout << std::to_string(entities.size());
    // entities.at(0).ani.play(entities.at(0).walk());
    dummy.ani.play(dummy.walk());
    window.draw(dummy.ani);
    // window.draw(entities.at(0).ani);
    // Level::draw(window);
    // Level::draw(window);
    // sf::Sprite road;
    // road.setTexture(this->sky);
    // road.setScale(800 / road.getLocalBounds().width, 600/ road.getLocalBounds().height);
    // window.draw(road);
    // window.draw(dummy.ani);
}

std::vector<Dummy> LevelTwo::getEnemies(){
     Dummy dummy("dummy", "/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", 150, 150, this->tm);
    // dummy.ani.play(dummy.walk())
    std::vector<Dummy> dummies;
    return dummies;
}