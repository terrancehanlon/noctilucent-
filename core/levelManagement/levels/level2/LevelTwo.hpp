#ifndef LEVELTWO_INCLUDE
#define LEVELTWO_INCLUDE


#include "../base/Level.hpp"
#include <string>


class LevelTwo : public Level{
    private:
        sf::Texture sky;
        sf::Texture road;

    public:
        LevelTwo(std::string name);
        void setSprites();
        void setTextures();
};

#endif