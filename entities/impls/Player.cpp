#include "../headers/Player.hpp"
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
    std::cout << "creating" << std::endl;
    setupSwing();
    setUpIdle();
    setUpWalk();
    setUpLay();
    idle();
    // this->ani.play(ani_swing);
}

// void Player::drawPlayer(){
//     sf::Texture texture;
//     texture.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/sky.png",  sf::IntRect(0,0, 800, 600));
//     this->avatar.setTexture(texture);
// }
void Player::display(sf::RenderWindow &window){
    window.draw(this->ani);
}

Player::Player(){
    this->name = "";
}

void Player::setHealth(int health){
    this->health = health;
}

void Player::setPosition(float x, float y){
    this->ani.setPosition(sf::Vector2f(x, y));
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
    //key down  
    this->ani_swing.setSpriteSheet(this->texture);
    this->ani_swing.addFrame(sf::IntRect(14, 96, 25, 45));
    this->ani_swing.addFrame(sf::IntRect(61, 97, 25, 45));
    this->ani_swing.addFrame(sf::IntRect(109, 97, 25, 45));
    this->ani_swing.addFrame(sf::IntRect(157, 97, 24, 45));
    // swinging.addFrame(sf::IntRect(230, 0, 48, ));
    this->ani_swing.addFrame(sf::IntRect( 194, 98, 38, 44));
}

void Player::setUpLay(){
    this->ani_lay.setSpriteSheet(this->texture);
    this->ani_lay.addFrame(sf::IntRect(6, 178, 39, 12));
    this->ani_lay.addFrame(sf::IntRect(57, 168, 35, 22));
    this->ani_lay.addFrame(sf::IntRect(108, 159, 27, 31));
    this->ani_lay.addFrame(sf::IntRect(157, 159, 26, 31));
    this->ani_lay.addFrame(sf::IntRect(205, 159, 26, 31));
    this->ani_lay.addFrame(sf::IntRect(253, 159, 26, 31));
    this->ani_lay.addFrame(sf::IntRect(301, 159, 26, 31));
    this->ani_lay.addFrame(sf::IntRect(351, 157, 23, 33));
    this->ani_lay.addFrame(sf::IntRect(16, 61, 25, 33));

}

void Player::setUpWalk  (){
    std::cout << "Setting up walk" << std::endl;

    this->ani_walk.setSpriteSheet(this->texture);
    // this->ani_walk.addFrame(sf::IntRect(16, 9, 26, 37));
    this->ani_walk.addFrame(sf::IntRect(16, 61, 25, 33));
    this->ani_walk.addFrame(sf::IntRect(60, 60, 29, 33));
    this->ani_walk.addFrame(sf::IntRect(107, 59, 32, 35));
    this->ani_walk.addFrame(sf::IntRect(160, 60, 25, 35));
    this->ani_walk.addFrame(sf::IntRect(211, 61, 20, 33));
    this->ani_walk.addFrame(sf::IntRect(249, 60, 31, 32));
    this->ani_walk.addFrame(sf::IntRect(296, 59, 31, 35));
    this->ani_walk.addFrame(sf::IntRect(345, 59, 31, 35));
}

Animation Player::lay(){
    return this->ani_lay;
}

Animation Player::walk(){
    return this->ani_walk;
}


Animation Player::swing(){
    // this->ani.play(this->ani_swing);
    return this->ani_swing;

}
