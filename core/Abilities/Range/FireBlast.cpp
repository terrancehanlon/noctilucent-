#include <SFML/Graphics.hpp>
#include <string>
#include "./FireBlast.hpp"
#include "../../Namespaces/ImageManager.cpp"
#include "../../Namespaces/TextureManager.cpp"
#include "../../TextureManager.hpp"
// #include

FireBlast::FireBlast(sf::RenderWindow &window){
    Ability(1, 1, "Fire blast");
    Animation animation;
    animation.setSpriteSheet(textm::TextM::gettext());
    animation.addFrame(sf::IntRect(1,4, 12, 12));
    this->animatedSprite.play(animation);
    this->animatedSprite.setPosition(50, 50);
    this->animatedSprite.setScale(5, 5);
    window.draw(this->animatedSprite);
};

