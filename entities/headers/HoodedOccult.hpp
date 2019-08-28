#ifndef HOODEDOCCULT_INCLUDE
#define HOODEDOCCULT_INCLUDE

#include <string>
#include <SFML/Graphics.hpp>
#include "../../lib/AnimatedSprite.hpp"
#include <vector>
#include "../../core/TextureManager.hpp"

class HoodedOccult 
{
    private:
        std::string name;
        int health;
        TextureManager tm;
        Animation ani_idle;
        Animation ani_walk;
        static Animation static_idle;
        void setUpIdle();
        void setUpWalk();

    public:
        HoodedOccult(float startX, float startY, TextureManager tm);
        AnimatedSprite ani;
        Animation walk();
        Animation idle();
        void display(sf::RenderWindow &window);
        static Animation static_walk(TextureManager tm);
};




#endif