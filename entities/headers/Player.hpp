#ifndef PLAYER_INCLUDE
#define PLAYER_INCLUDE

#include <string>
#include <SFML/Graphics.hpp>
#include "../../lib/AnimatedSprite.hpp"
#include <vector>
#include "../../core/Abilities/Ability.hpp"

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
        sf::Sprite avatar;
        std::string name;
        sf::Texture texture;
        Animation animation;
        std::vector<animation_object> animations;
        void init();
        void setupSwing();
        void setUpIdle();
        void setUpWalk();
        void setUpLay();
        Animation ani_lay;
        Animation ani_swing;
        Animation ani_idle;
        Animation ani_walk;
    

    public:
        void setPosition(float x, float y);
        sf::Sprite drawPlayer();
        Animation currentAnimation;
        AnimatedSprite ani;
        Player(std::string name, std::string path);
        Player();
        void setHealth(int health);
        int getHealth();
        Animation swing(); 
        Animation idle();
        Animation walk();
        Animation lay();
        void setCurrentAnimation(Animation animation);
        Animation getCurrentAnimation();
        void display(sf::RenderWindow &window);
        void update(sf::RenderWindow &window);
        int fire(Ability ability);
};


#endif