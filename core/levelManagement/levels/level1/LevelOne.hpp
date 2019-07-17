#ifndef LEVELONE_INCLUDE
#define LEVELONE_INCLUDE


#include "../base/Level.hpp"
#include <string>


class LevelOne : public Level{
    private:
        sf::Texture sky;
        sf::Texture road;

    public:
        LevelOne();
        void setSprites();
        void setTextures();
};

#endif