#include "Player.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
Player::Player(std::string name, std::string path){
    this->name = name;
    this->texture.loadFromFile(path);
    //sets up sprite
    this->ani = AnimatedSprite(sf::seconds(0.2), true, false);
    this->ani.setPosition(sf::Vector2f(400, 300));
    this->ani.scale(2.0,2.0);
    
    //sets up animations
    setupSwing();
    // this->ani.play(swing2);
}

Player::Player(){
    this->name = "";
}

void Player::setHealth(int health){
    this->health = health;
}

int Player::getHealth(){
    return this->health;
}

void Player::init(){
    // setupSwing();
}

void Player::setupSwing(){
    Animation swinging;
    
    
    //key down  
    this->swing2.setSpriteSheet(this->texture);
    this->swing2.addFrame(sf::IntRect(150, 0, 48, 48));
    this->swing2.addFrame(sf::IntRect(190, 0, 48, 48));
    // swinging.addFrame(sf::IntRect(230, 0, 48, 48));
    this->swing2.addFrame(sf::IntRect( 0, 0, 48, 48));

}


void Player::swing(){
    this->ani.play(this->swing2);
    // sf::Vector2f movement(0.f, 0.f);
    // sf::Clock frameClock;
    // sf::Time frameTime = frameClock.restart();
    // // std::cout << "also here" << std::endl;
    // // for(int i = 0; i < animations.size(); i++){
    // //     if(this->animations.at(i).name == "swing"){
    // //         this->ani.play(this->animations.at(i).animation);
    // //         this->ani.move(movement * frameTime.asSeconds());
    // //     }
    // // }     
    // this->ani.play(swing2);
    // this->ani.move(movement * frameTime.asSeconds());
}
