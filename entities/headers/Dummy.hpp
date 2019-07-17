#ifndef DUMMY_INCLUDE
#define DUMMY_INCLUDE

#include <string>
#include <SFML/Graphics.hpp>
#include "../../lib/AnimatedSprite.hpp"
#include <vector>

class Dummy
{
    private:
        std::string name;
        int health;
        sf::Texture texture;
        Animation ani_attack;
        Animation ani_idle;
        Animation ani_walk;
        void setUpWalk();   

    public:
        Dummy(std::string name, std::string path, float startX, float startY);
        void setPosition(float x, float y);
        sf::Sprite drawEnemy();
        AnimatedSprite ani;
        Animation attack();
        Animation idle();
        Animation walk();
        void setTexture(sf::Texture text);
        sf::Texture getTexture();
};


#endif