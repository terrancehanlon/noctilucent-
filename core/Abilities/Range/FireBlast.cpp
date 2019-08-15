#include <SFML/Graphics.hpp>
#include <string>
#include "./FireBlast.hpp"
#include "../../TextureManager.hpp"
#include <iostream>
// #include

FireBlast::FireBlast(int x, int y){
    Ability(1, 1, "Fire blast");
    Animation animation;
    this->speed = 8;
    this->texture.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/fireblast.png");
    animation.setSpriteSheet(this->texture);
    animation.addFrame(sf::IntRect(1,4, 12, 12));
    this->animatedSprite.play(animation);
    // this->animatedSprite.setPosition(50, 50);
    this->cordX = x + 5;
    this->cordY = y;
    this->animatedSprite.setScale(5, 5);
    this->animatedSprite.rotate(90.0f);
    std::cout << "DRAWING BLAST" << std::endl;
    // window.draw(this->animatedSprite);
};

