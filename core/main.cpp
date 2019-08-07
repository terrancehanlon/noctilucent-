#include <SFML/Graphics.hpp>
#include "../lib/AnimatedSprite.hpp"
#include "../lib/AnimatedSprite.hpp"
#include <iostream>
#include "../entities/headers/Player.hpp"
#include "levelManagement/levels/base/LevelManager.hpp"
#include "levelManagement/levels/base/LevelEngine.hpp"
#include "levelManagement/levels/level1/LevelOne.hpp"
#include "levelManagement/levels/level2/LevelTwo.hpp"
#include <vector>
#include "TextureManager.hpp"
#include <curl/curl.h>
#include <string>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main()
{

enum GameState{
    Intro,
    Running,
    Pause,
    Death,
    End
};

    sf::Sprite sprite22;
    sf::Texture text22;

    text22.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/hooded-sprite-side.png");
    sprite22.setTexture(text22);
            sprite22.scale(3.3f, 3.3f);
    TextureManager tm;

    tm.loadTexture("dummy", "/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png");
    tm.loadTexture("hooded-occult", "/home/terrance/Desktop/games2/noctilucent-/assets/hooded-occult.png");

    sf::Vector2i screenDimensions(2000,2000);
    
    sf::RenderWindow *win;
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Animations!", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    std::vector<sf::Texture> textures;
    std::vector<Dummy> dummies;
    sf::Texture text;
    sf::Texture dummyTexture;
    sf::Texture backGround;
    backGround.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/sky.png");
    dummyTexture.loadFromFile("/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png");
    GameState gameState = GameState::Intro;
    Level currentLevel;
    LevelOne levelone;
    LevelTwo leveltwo(dummyTexture, backGround, tm);
    LevelManager levelManger(tm);

    // textures.push_back(leveltwo.getTexture());
    // text = leveltwo.getTexture();
    // setup window


    // LevelEngine engine(win);

    // load texture (spritesheet)
    // sf::Texture texture;
    // if (!texture.loadFromFile("dragonBig.png"))
    // {
    //     std::cout << "Failed to load player spritesheet!" << std::endl;
    //     return 1;
    // }


    Animation currentAnimation;
    Animation dummyAnimation;
    sf::Clock frameClock;

    float speed = 180.f;
    bool noKeyWasPressed = true;
    bool flipped = false;
    
    bool init = true;

    std::vector<Player> players;
    Player pl("name", "/home/terrance/Desktop/games2/noctilucent-/assets/pixel.png");
    float originalY = pl.ani.getPosition().y;
    // Dummy dm("name", "/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", 100, 100, tm);
    // players.push_back(pl);
    // players.at(0).se
    // Player pl2("name2", "dragonBig.png");
    //Dummy dummy("dummy", "/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", 150, 150);
    pl.setPosition(0, sf::VideoMode::getDesktopMode().height - (sf::VideoMode::getDesktopMode().height / 2.8 ));
    // pl2.ani.setColor(sf::Color::Red);
    // window.draw(sprite);
    currentAnimation = pl.walk();
    
    
    // sf::Sprite sp = levelone.getImages().at(0);
    currentLevel = levelone;
    Dummy dm("name", "/home/terrance/Desktop/games2/noctilucent-/assets/dummy.png", 10, 10, tm);
    dummyAnimation = dm.walk();
    dm.ani.play(dummyAnimation);

  CURL *curl;
  CURLcode res;
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:4567/frank-says");
    /* example.com is redirected, so we tell libcurl to follow redirection */ 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    // std::cout << "hererere" << std::endl;
    std::cout <<res << std::endl;
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }

    bool shiftingUp = true;

    // pl.ani.play(pl.lay());
    while (window.isOpen())
    {
        // dummy.display(window);
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
            // movement.y -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            // currentAnimation = &swinging;
            currentAnimation = pl.swing();
            if(shiftingUp){
                std::cout << "JUMPING" << std::endl;
                pl.setPosition(pl.ani.getPosition().x, pl.ani.getPosition().y - 10);
                shiftingUp = false;
            }
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
            if(!shiftingUp){
                std::cout << "JUMPING down" << std::endl;
                pl.setPosition(pl.ani.getPosition().x, pl.ani.getPosition().y + 10);
                shiftingUp = !shiftingUp;
            }
            if(!flipped) pl.ani.scale(-1, 1); 
            flipped = true;  
            currentAnimation = pl.walk();
            movement.x += speed;
            noKeyWasPressed = false;
        }
        if (noKeyWasPressed)
        {
            if(shiftingUp == false){
                pl.setPosition(pl.ani.getPosition().x, originalY);
            }
            shiftingUp = true;
            // pl.ani.stop();
            // shiftingUp = true;
            // if(shiftingUp){
            // pl.setPosition(pl.ani.getPosition().x, pl.ani.getPosition().y + 50);
            // shiftingUp = !shiftingUp;
            // }
            
            currentAnimation = pl.walk();
            // dummyAnimation = dummy.walk();
            
        }
        noKeyWasPressed = true;

        pl.ani.play(currentAnimation);
        pl.ani.update(frameTime);
        pl.ani.move(movement * frameTime.asSeconds());
        levelone.moveSky(movement * frameTime.asSeconds()); 
        

        if(pl.ani.getPosition().x > screenDimensions.x){
            // std::cout << "Player off screen" << std::endl;
            currentLevel = leveltwo;
            // leveltwo.displayEnemies(window);
            pl.setPosition(5, screenDimensions.y - 150);
        }else{
            // std::cout << "Player on screen" << std::endl;
        }      

        // if( pl.ani.getGlobalBounds().intersects(pl2.ani.getGlobalBounds()) ){
        //     // std::cout << "COLLISION" << std::endl;
        // }
        // else{
        //     // std::cout << "NO COLLISION" << std::endl;
        // }

        
        // draw
        window.clear();
        levelManger.drawLevel(currentLevel, window);
        // leveltwo.draw(window);
        // window.draw(sprite);
        // window.draw(road);

        
        // window.draw(levelone->getImages().at(0));
       
        pl.display(window);
        // leveltwo.draw(window);
        // window.draw(dm.ani);
        window.draw(sprite22);
        // leveltwo.draw(window);
        // currentLevel.draw(window, leveltwo.getEnemies());
        // dummy.display(window);
        // window.draw(dummy.ani);
        // window.draw(pl2.ani);
        
        window.display();
    }

    return 0;
}