#include "./ActionBar.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

ActionBar::ActionBar(TextureManager tm){
    this->tm = tm;
    this->actionbar.setTexture(this->tm.getRef("actionbar"));
    this->actionbar.setPosition(sf::Vector2f(0, 0));
    this->actionbar.scale(3, 3);
}

void ActionBar::drawActionBar(sf::RenderWindow &window){
    // std::printf("drawing action bar", "%s");
    // window.draw((*this->actionbar));
}