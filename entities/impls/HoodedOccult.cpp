#include "../headers/HoodedOccult.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
HoodedOccult::HoodedOccult(float startX, float startY, TextureManager tm){
    this->tm = tm;
    this->ani = AnimatedSprite(sf::seconds(0.9), true, false);
    this->ani.setPosition(sf::Vector2f(startX, startY));
    this->ani.setScale(sf::Vector2f(3.0f, 3.0f));
    this->setUpIdle();
    std::cout << "creating occ" << std::endl;
}

void HoodedOccult::setUpIdle(){
    // std::cout << "Creating idle" << std::endl;
    this->ani_idle.setSpriteSheet(this->tm.getRef("hooded-occult"));
    this->ani_idle.addFrame(sf::IntRect(9, 1, 14, 31));
    this->ani_idle.addFrame(sf::IntRect(41, 1, 14, 31));
    this->ani_idle.addFrame(sf::IntRect(73, 1, 14, 31));
    this->ani_idle.addFrame(sf::IntRect(105, 1, 14, 31));
    this->ani_idle.addFrame(sf::IntRect(137, 1, 14, 31));
    this->ani_idle.addFrame(sf::IntRect(137, 33, 16, 31));
    this->ani_idle.addFrame(sf::IntRect(169, 33, 17, 31));
    this->ani_idle.addFrame(sf::IntRect(201, 33, 21, 31));
}

void HoodedOccult::display(sf::RenderWindow &window){
    window.draw(ani);
}

Animation HoodedOccult::idle(){
    return this->ani_idle;
}