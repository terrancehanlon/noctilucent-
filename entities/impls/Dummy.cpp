#include "../headers/Dummy.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream> 

Dummy::Dummy(std::string name,std::string path, float startX, float startY, TextureManager tm){
    this->name = name;
    this->tm = tm;
    this->texture = tm.getRef("dummy");
    setTexture(this->texture);
    this->ani = AnimatedSprite(sf::seconds(0.9), true, false);
    this->ani.setPosition(sf::Vector2f(startX, startY));
    this->ani.scale(2.0,2.0);
    this->setUpWalk();
    // std::cout <<"making dummy" << std::endl;
}

void Dummy::setUpWalk(){  
    // std::cout << "length " + std::to_string(tm.length()) << std::endl;
    this->ani_walk.setSpriteSheet(this->tm.getRef("dummy"));
    this->ani_walk.addFrame(sf::IntRect(458, 6, 43, 54));
    this->ani_walk.addFrame(sf::IntRect(2, 5, 59, 55));
    this->ani_walk.addFrame(sf::IntRect(74, 6, 46, 54));
    this->ani_walk.addFrame(sf::IntRect(150, 6, 19, 54));
    this->ani_walk.addFrame(sf::IntRect(201, 6, 45, 54));
    this->ani_walk.addFrame(sf::IntRect(259, 5, 59, 50));
    this->ani_walk.addFrame(sf::IntRect(331, 6, 43, 54));
    this->ani_walk.addFrame(sf::IntRect(406, 6, 20, 54));
    this->ani_walk.addFrame(sf::IntRect(458, 6, 43, 54));
    this->ani_walk.addFrame(sf::IntRect(2, 5, 59, 55)); 
}

Dummy::Dummy(){

}

Animation Dummy::walk(){  
    return this->ani_walk;
} 

void Dummy::setTexture(const sf::Texture& text){
    this->texture = text;
}

sf::Texture Dummy::getTexture(){
    return this->texture;
}

void Dummy::display(sf::RenderWindow &window){
    // this->ani.play(this->walk());
    window.draw(ani);
}