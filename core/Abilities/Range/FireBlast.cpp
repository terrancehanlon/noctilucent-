#include <SFML/Graphics.hpp>
#include <string>
#include "./FireBlast.hpp"
#include "../../TextureManager.hpp"
#include <iostream>
// #include

FireBlast::FireBlast(sf::RenderWindow &window){
    Ability(1, 1, "Fire blast");
    Animation animation;
    this->texture.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/fireblast.png");
    animation.setSpriteSheet(this->texture);
    animation.addFrame(sf::IntRect(1,4, 12, 12));
    this->animatedSprite.play(animation);
    this->animatedSprite.setPosition(50, 50);
    this->animatedSprite.setScale(5, 5);
    std::cout << "DRAWING BLAST" << std::endl;
    window.draw(this->animatedSprite);
};

