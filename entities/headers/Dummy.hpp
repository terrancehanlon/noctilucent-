#ifndef DUMMY_INCLUDE
#define DUMMY_INCLUDE

#include <string>
#include <SFML/Graphics.hpp>
#include "../../lib/AnimatedSprite.hpp"
#include <vector>
#include "../../core/TextureManager.hpp"

class Dummy
{
    private:
        std::string name;
        int health;
        sf::Texture texture;
        Animation ani_attack;
        Animation ani_idle;
        Animation ani_walk;
        TextureManager tm;
        void setUpWalk();
         

    public:
        Dummy(std::string name, std::string path, float startX, float startY, TextureManager tm);
        Dummy();
        void setPosition(float x, float y);
        sf::Sprite drawEnemy();
        AnimatedSprite ani;
        Animation attack();
        Animation idle();
        Animation walk();
        void setTexture(const sf::Texture& text);
        sf::Texture getTexture();
        void display(sf::RenderWindow &window);
};


#endif