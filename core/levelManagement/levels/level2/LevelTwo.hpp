#ifndef LEVELTWO_INCLUDE
#define LEVELTWO_INCLUDE


#include "../base/Level.hpp"
#include <string>
#include <vector>

class LevelTwo : public Level{
    private:
        sf::Texture sky;
        sf::Texture road;
        sf::Texture character;
        // vector<Dummy> 

    public:
        LevelTwo(std::vector<Dummy> dummies);
        void setSprites();
        void setTextures();
        void setEnemies();
        sf::Texture getTexture();
        void setTexture(sf::Texture texture);
};

#endif