#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>
#include "Player.hpp"

int main()
{
    //     swinging.setSpriteSheet(texture);
    // swinging.addFrame(sf::IntRect(0, 0, 48, 48));
    // swinging.addFrame(sf::IntRect(500, 95, 48, 48));
    // swinging.addFrame(sf::IntRect(200, 95, 48, 48));


    // setup window
    sf::Vector2i screenDimensions(800,600);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Animations!");
    window.setFramerateLimit(60);

    // load texture (spritesheet)
    sf::Texture texture;
    if (!texture.loadFromFile("dragonBig.png"))
    {
        std::cout << "Failed to load player spritesheet!" << std::endl;
        return 1;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);


    // set up the animations for all four directions (set spritesheet and push frames)
    Animation swinging;
    //key down
    swinging.setSpriteSheet(texture);
    swinging.addFrame(sf::IntRect(150, 0, 48, 48));
    swinging.addFrame(sf::IntRect(190, 0, 48, 48));
    // swinging.addFrame(sf::IntRect(230, 0, 48, 48));
    swinging.addFrame(sf::IntRect( 0, 0, 48, 48));

    Animation walkingAnimationLeft;
    walkingAnimationLeft.setSpriteSheet(texture);
    walkingAnimationLeft.addFrame(sf::IntRect(11, 50, 48, 48));
    walkingAnimationLeft.addFrame(sf::IntRect(57, 50, 48, 48));
    walkingAnimationLeft.addFrame(sf::IntRect(104, 50, 48, 48));
    walkingAnimationLeft.addFrame(sf::IntRect( 11, 50, 48, 48));

    Animation walkingAnimationRight;
    walkingAnimationRight.setSpriteSheet(texture);
    walkingAnimationRight.addFrame(sf::IntRect(11, 50, 48, 48));
    walkingAnimationRight.addFrame(sf::IntRect(57, 50, 48, 48));
    walkingAnimationRight.addFrame(sf::IntRect(104, 50, 48, 48));
    walkingAnimationRight.addFrame(sf::IntRect( 11, 50, 48, 48));
    

    Animation walkingAnimationUp;
    walkingAnimationUp.setSpriteSheet(texture);
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect( 0, 96, 32, 32));


    Animation* currentAnimation = &swinging;

    // set up AnimatedSprite
    AnimatedSprite animatedSprite(sf::seconds(0.2), true, false);
    animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));

    sf::Clock frameClock;



    float speed = 80.f;
    bool noKeyWasPressed = true;
    bool flipped = false;
    animatedSprite.scale(2.0, 2.0);

    Player pl("name", texture);

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            currentAnimation = &walkingAnimationUp;
            movement.y -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            // currentAnimation = &swinging;
            
            // movement.y += speed;
            noKeyWasPressed = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if(flipped) animatedSprite.scale(-1, 1);    
            flipped = false;    
            currentAnimation = &walkingAnimationLeft;
            movement.x -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            currentAnimation = &walkingAnimationRight;
            if(!flipped) animatedSprite.scale(-1, 1); 
            flipped = true;  
            movement.x += speed;
            noKeyWasPressed = false;
        }
        animatedSprite.play(*currentAnimation);
        animatedSprite.move(movement * frameTime.asSeconds());

        // if no key was pressed stop the animation
        if (noKeyWasPressed)
        {
            animatedSprite.stop();
        }
        noKeyWasPressed = true;

        // update AnimatedSprite
        // animatedSprite.play(pl->ani);
        animatedSprite.update(frameTime);

        // draw
        window.clear();
        window.draw(animatedSprite);
        window.display();
    }

    return 0;
}