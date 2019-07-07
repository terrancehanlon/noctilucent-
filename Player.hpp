#ifndef PLAYER_INCLUDE
#define PLAYER_INCLUDE

#include <string>
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <vector>

// struct animation_object {
//     std::string name;
//     Animation animation;
// };

class Player
{
    struct animation_object {
    std::string name;
    sf::Texture texture;
};

    private:
        int health;
        std::string name;
        sf::Texture texture;
        Animation animation;
        std::vector<animation_object> animations;
        void init();
        void setupSwing();
        void setUpIdle();
        void setUpWalk();
        Animation ani_swing;
        Animation ani_idle;
        Animation ani_walk;

    public:
        Animation currentAnimation;
        AnimatedSprite ani;
        Player(std::string name, std::string path);
        Player();
        void setHealth(int health);
        int getHealth();
        Animation swing(); 
        Animation idle();
        Animation walk();
        void setCurrentAnimation(Animation animation);
        Animation getCurrentAnimation();
};


#endif