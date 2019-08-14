#ifndef ABILITY_INCLUDE
#define ABILITY_INCLUDE

#include <string>
#include <SFML/Graphics.hpp>
#include "../../lib/AnimatedSprite.hpp"
#include "../../lib/Animation.hpp"

class Ability {

    private:
        int cost;
        int damage;
        std::string name;
        
    public:
        int speed;
        bool on;
        int cordX;
        int cordY;
        Animation animation;
        AnimatedSprite animatedSprite;
        Ability(int cost, int damage, std::string name);
        Ability(){};
        int getDamage();
        void setDamage(int damage);
        int getCost();
        void setCOst(int cost);
        void draw(sf::RenderWindow &window);


};


#endif