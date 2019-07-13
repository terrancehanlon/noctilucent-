#include <LevelEngine.hpp>
#include <SFML/Graphics.hpp>
LevelEngine::LevelEngine(sf::RenderWindow *mainWindow){

}

void LevelEngine::drawSprite(sf::Sprite sprite){
    
}

sf::RenderWindow LevelEngine::initWindow(){
    sf::RenderWindow _window(sf::VideoMode(800, 600), "Noctu");
    _window.setFramerateLimit(60);

}