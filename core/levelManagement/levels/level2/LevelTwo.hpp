#ifndef LEVELTWO_INCLUDE
#define LEVELTWO_INCLUDE


#include "../base/Level.hpp"
#include <string>
#include <vector>

class LevelTwo : public Level{
    Dummy dummy;
    private:
        sf::Texture sky;
        sf::Texture road;
        sf::Texture character;
        TextureManager tm;
        
        
        // vector<Dummy> 

    public:
        LevelTwo(sf::Texture dummy, sf::Texture background, TextureManager tm);
        void displayEnemies(sf::RenderWindow &window);
        void setSprites();
        void setTextures(sf::Texture texture);
        void setEnemies(sf::Texture texutre, TextureManager tm);
        sf::Texture getTexture();
        void setTexture(const sf::Texture& texture);
        void setDummy(Dummy dummy);
        void draw(sf::RenderWindow &window);
        std::vector<Dummy> getEnemies();
};

#endif