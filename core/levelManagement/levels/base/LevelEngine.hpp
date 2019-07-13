#ifndef LEVELENGINE_INCLUDE
#define LEVELENGINE_INCLUDE

#include <stack> 
#include <SFML/Graphics.hpp>

class LevelEngine {
    private:
        sf::RenderWindow window;

    public:
        LevelEngine(sf::RenderWindow *window);
        sf::RenderWindow initWindow();
        void drawSprite(sf::Sprite sprite);


};

#endif