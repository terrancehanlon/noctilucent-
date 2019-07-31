#ifndef LEVELONE_INCLUDE
#define LEVELONE_INCLUDE


#include "../base/Level.hpp"
#include <string>


class LevelOne : public Level{
    private:
        sf::Texture sky;
        sf::Texture road;
        sf::Sprite roadSprite;
        sf::Sprite skySprite;

    public:
        LevelOne();
        void setSprites();
        void setTextures();
        void moveSky(sf::Vector2f movement);
};

#endif