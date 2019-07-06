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

    public:
        Animation swing2;
        Animation ani_idle;
        AnimatedSprite ani;
        Player(std::string name, std::string path);
        Player();
        void setHealth(int health);
        int getHealth();
        void swing();
        void setUpIdle();
        void idle();
};


#endif