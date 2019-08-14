#include <SFML/Graphics.hpp>
#include <string>
#include "./Ability.hpp"

Ability::Ability(int dmg, int cost, std::string name){

}

void Ability::draw(sf::RenderWindow &window){
    this->animatedSprite.setPosition(this->cordX, this->cordY);
    this->on = true;
    window.draw(this->animatedSprite);
}
