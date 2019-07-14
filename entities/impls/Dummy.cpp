#include "../headers/Dummy.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream> 

Dummy::Dummy(std::string name, std::string path, float startX, float startY){
    this->name = name;
    this->texture.loadFromFile(path);

    this->ani = AnimatedSprite(sf::seconds(0.2), true, false);
    this->ani.setPosition(sf::Vector2f(startX, startY));
    this->ani.scale(2.0,2.0);
    this->setUpWalk();

}

void Dummy::setUpWalk(){
    this->ani_walk.setSpriteSheet(this->texture);
    // this->ani_walk.addFrame(sf::IntRect(458, 6, 43, 54));
    this->ani_walk.addFrame(sf::IntRect(2, 5, 59, 55));
    this->ani_walk.addFrame(sf::IntRect(74, 6, 46, 54));
    this->ani_walk.addFrame(sf::IntRect(150, 6, 19, 54));
    this->ani_walk.addFrame(sf::IntRect(201, 6, 45, 54));
    this->ani_walk.addFrame(sf::IntRect(259, 5, 59, 55));
    this->ani_walk.addFrame(sf::IntRect(331, 6, 43, 54));
    this->ani_walk.addFrame(sf::IntRect(406, 6, 20, 54));
    this->ani_walk.addFrame(sf::IntRect(458, 6, 43, 54));
    // this->ani_walk.addFrame(sf::IntRect(2, 5, 59, 55));
}

Animation Dummy::walk(){
    return this->ani_walk;
}