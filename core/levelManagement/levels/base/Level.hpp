#ifndef LEVEL_INCLUDE
#define LEVEL_INCLUDE

#include <string>
#include <SFML/Graphics.hpp>
#include "/home/terrance/Desktop/games2/noctilucent-/lib/AnimatedSprite.hpp"
#include <vector>

class Level{

    private:
        std::string levelTitle;                                                                         

    public:
        std::vector<sf::Sprite> images;
        std::string getLevelTitle();
        Level();
        Level(std::string name);
        std::vector<sf::Sprite> getImages(); 
        void addImage(sf::Sprite sprite);   
        

};

#endif