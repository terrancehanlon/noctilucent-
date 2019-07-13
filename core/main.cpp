#include <SFML/Graphics.hpp>
#include "../lib/AnimatedSprite.hpp"
#include "../lib/AnimatedSprite.hpp"
#include <iostream>
#include "../entities/headers/Player.hpp"
#include "./levelManagement/levels/base/LevelManager.hpp"
#include "./levelManagement/levels/base/LevelEngine.hpp"
#include "./levelManagement/levels/level1/LevelOne.hpp"
#include "./levelManagement/levels/level2/LevelTwo.hpp"


int main()
{

enum GameState{
    Intro,
    Running,
    Pause,
    Death,
    End
};

    GameState gameState = GameState::Intro;
    Level currentLevel;
    LevelOne levelone("name");
    LevelTwo leveltwo("name");
    LevelManager levelManger;


    // setup window
    sf::Vector2i screenDimensions(800,600);
    
    sf::RenderWindow *win;
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Animations!");
    window.setFramerateLimit(60);

    // LevelEngine engine(win);

    // load texture (spritesheet)
    sf::Texture texture;
    if (!texture.loadFromFile("dragonBig.png"))
    {
        std::cout << "Failed to load player spritesheet!" << std::endl;
        return 1;
    }

    Animation currentAnimation;
    sf::Clock frameClock;

    float speed = 180.f;
    bool noKeyWasPressed = true;
    bool flipped = false;
    
    bool init = true;

    Player pl("name", "dragonBig.png");
    Player pl2("name2", "dragonBig.png");
    pl.setPosition(5, screenDimensions.y - 150);
    pl2.ani.setColor(sf::Color::Red);
    // window.draw(sprite);
    currentAnimation = pl.idle();
    // sf::Sprite sp = levelone.getImages().at(0);
    currentLevel = levelone;
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        sf::Time frameTime = frameClock.restart();

        // if a key was pressed set the correct animation and move correctly
        sf::Vector2f movement(0.f, 0.f);
        sf::Vector2f movement2(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            currentAnimation = pl.walk();
            movement.y -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            // currentAnimation = &swinging;
            currentAnimation = pl.swing();
            // movement.y += speed;
            noKeyWasPressed = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if(flipped) pl.ani.scale(-1, 1);    
            flipped = false;    
            currentAnimation = pl.walk();
            movement.x -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            //currentAnimation = &walkingAnimationRight;
            if(!flipped) pl.ani.scale(-1, 1); 
            flipped = true;  
            currentAnimation = pl.walk();
            movement.x += speed;
            noKeyWasPressed = false;
        }
        // animatedSprite.play(*currentAnimation);
        // animatedSprite.move(movement * frameTime.asSeconds());

        // if no key was pressed stop the animation
        if (noKeyWasPressed)
        {
            // pl.ani.stop();
            currentAnimation = pl.idle();
        }
        noKeyWasPressed = true;

        // update AnimatedSprite
        // animatedSprite.play(pl->ani);    
        pl.ani.play(currentAnimation);
        pl.ani.update(frameTime);
        pl.ani.move(movement * frameTime.asSeconds());  

        

        pl2.ani.play(pl2.idle());     

        if(pl.ani.getPosition().x > screenDimensions.x){
            std::cout << "Player off screen" << std::endl;
            currentLevel = leveltwo;
            pl.setPosition(5, screenDimensions.y - 150);
        }else{
            std::cout << "Player on screen" << std::endl;
        }      

        if( pl.ani.getGlobalBounds().intersects(pl2.ani.getGlobalBounds()) ){
            // std::cout << "COLLISION" << std::endl;
        }
        else{
            // std::cout << "NO COLLISION" << std::endl;
        }

        
        // draw
        window.clear();
        levelManger.drawLevel(currentLevel, window);
        // window.draw(sprite);
        // window.draw(road);

        
        // window.draw(levelone->getImages().at(0));

        window.draw(pl.ani);
        // window.draw(pl2.ani);
        
        window.display();
    }

    return 0;
}