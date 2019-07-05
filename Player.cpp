#include "Player.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
Player::Player(std::string name, sf::Texture texture){
    this->name = name;
    this->ani = AnimatedSprite(sf::seconds(0.2), true, false);
    setupSwing();
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
    swinging.setSpriteSheet(this->texture);
    swinging.addFrame(sf::IntRect(150, 0, 48, 48));
    swinging.addFrame(sf::IntRect(190, 0, 48, 48));
    // swinging.addFrame(sf::IntRect(230, 0, 48, 48));
    swinging.addFrame(sf::IntRect( 0, 0, 48, 48));

    

    animation_object animation_object2 = {
        "swing", swinging
    };

    this->animations.push_back(animation_object2);
    this->swing2 = swinging;
}


void Player::swing(){
    sf::Vector2f movement(0.f, 0.f);
    sf::Clock frameClock;
    sf::Time frameTime = frameClock.restart();
    std::cout << "also here" << std::endl;
    for(int i = 0; i < animations.size(); i++){
        if(this->animations.at(i).name == "swing"){
            this->ani.play(this->animations.at(i).animation);
            this->ani.move(movement * frameTime.asSeconds());
        }
    }     
}
