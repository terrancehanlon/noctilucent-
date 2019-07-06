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
    setUpIdle();
    idle();
    // this->ani.play(ani_swing);
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

void Player::setCurrentAnimation(Animation animation){
    this->currentAnimation = animation;
}

Animation Player::getCurrentAnimation(){
    return this->currentAnimation;
}

void Player::setUpIdle(){
    this->ani_idle.setSpriteSheet(this->texture);
    this->ani_idle.addFrame(sf::IntRect(16, 9, 26, 45));
    this->ani_idle.addFrame(sf::IntRect(64, 9, 26, 45));
    this->ani_idle.addFrame(sf::IntRect(112, 10, 26, 45));
    this->ani_idle.addFrame(sf::IntRect(160, 10, 26, 45));

}

Animation Player::idle(){
    // this->ani.play(this->ani_idle);
    return this->ani_idle;
}

void Player::setupSwing(){
    Animation swinging;
    //key down  
    this->ani_swing.setSpriteSheet(this->texture);
    this->ani_swing.addFrame(sf::IntRect(14, 96, 25, 45));
    this->ani_swing.addFrame(sf::IntRect(61, 97, 25, 45));
    this->ani_swing.addFrame(sf::IntRect(109, 97, 25, 45));
    this->ani_swing.addFrame(sf::IntRect(157, 97, 24, 45));
    // swinging.addFrame(sf::IntRect(230, 0, 48, ));
    this->ani_swing.addFrame(sf::IntRect( 194, 98, 38, 44));
}


Animation Player::swing(){
    // this->ani.play(this->ani_swing);
    return this->ani_swing;

}
