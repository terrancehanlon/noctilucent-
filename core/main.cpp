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
#include "./UI/ActionBar.hpp"
// #include "load.cpp"
#include "./Abilities/Range/FireBlast.hpp"
#include <stack>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void init(){
    // textm::TextM.
    // textm::TextM:    
    // textm::TextM::setFile();xx`x`
    // textm::TextM::fbText = textm.TextM::fbText.loadFromFile(imageHandler::fireblast);
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
    tm.loadTexture("actionbar", "/home/terrance/Desktop/games2/noctilucent-/assets/ab-fb.png");

    sf::Vector2i screenDimensions(2000,2000);
    
    sf::RenderWindow *win;
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Animations!", sf::Style::Fullscreen);
    window.setFramerateLimit(60);


    Level currentLevel;
    LevelOne levelone;
    // LevelTwo leveltwo(dummyTexture, backGround, tm);
    LevelManager levelManger(tm);



    
    sf::Clock frameClock;

    float speed = 180.f;
    bool noKeyWasPressed = true;
    bool flipped = false;
    
    bool init = true;
    bool updatingLevel = false;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////      PLAYER ESSENTIALS         /////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    //animations
    Animation currentAnimation;

    //UI set up
    ActionBar actionbar(tm);




    
    currentLevel = levelone;
//   CURL *curl;
//   CURLcode res;
 
//   curl = curl_easy_init();
//   if(curl) {
//     curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:4567/frank-says");
//     /* example.com is redirected, so we tell libcurl to follow redirection */ 
//     curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
//     /* Perform the request, res will get the return code */ 
//     res = curl_easy_perform(curl);
//     // std::cout << "hererere" << std::endl;
//     std::cout <<res << std::endl;
//     /* Check for errors */ 
//     if(res != CURLE_OK)
//       fprintf(stderr, "curl_easy_perform() failed: %s\n",
//               curl_easy_strerror(res));
 
//     /* always cleanup */ 
//     curl_easy_cleanup(curl);
//   }

    bool shiftingUp = true;
    bool ability = false;
    bool abilityMove = true;
    std::stack<int> abilityStack;

    HoodedOccult hoodie(10.0f, 50.0f, tm);
    

    // pl.ani.play(pl.lay());
        Player pl("name","/home/terrance/Desktop/games2/noctilucent-/assets/pixel.png");
        pl.setPosition(sf::VideoMode::getDesktopMode().width /4, sf::VideoMode::getDesktopMode().height - (sf::VideoMode::getDesktopMode().height / 2.8 ));
    while (window.isOpen())
    {
        currentAnimation = pl.walk(); 
        sf::Time frameTime = frameClock.restart();
        // dummy.display(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        

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
 
            if(!flipped) pl.ani.scale(-1, 1);    
            flipped = true;    
            currentAnimation = pl.walk();
            movement.x -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if(flipped) pl.ani.scale(-1, 1); 
            flipped = false;  
            currentAnimation = pl.walk();
            movement.x += speed;
            noKeyWasPressed = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
            ability = true;
            noKeyWasPressed = false;    
        }
        if (noKeyWasPressed)
        {
            
            currentAnimation = pl.walk();
            if(abilityMove){
            ability = false;

            }
            
        }
        noKeyWasPressed = true;

        // std::cout << std::to_string(frameTime.asMilliseconds()) << std::endl;
    window.clear();
        pl.ani.play(currentAnimation);
        pl.ani.update(frameTime);
        pl.ani.move(movement * frameTime.asSeconds());

        hoodie.ani.play(hoodie.idle());
        hoodie.ani.update(frameTime);

        // window.draw(hoodie.ani);
        

        // currentLevel = levelManger.drawLevel(currentLevel, window, frameTime, movement);

        
        if(updatingLevel){
            levelManger.updateLevel(currentLevel, window, frameTime);
        }
        if(!updatingLevel){
             currentLevel = levelManger.drawLevel(currentLevel, window, frameTime, movement);
            updatingLevel = true;
        }
        if(ability){
            if(abilityMove){
                // int x = pl.ani.getPosition().x;
                abilityStack.push(pl.ani.getPosition().x);
                abilityMove = false;
            }
            int newX = abilityStack.top();
            abilityStack.pop();
            FireBlast fireBlast((newX + 1), pl.ani.getPosition().y);
            // pl.fire(fireBlast)
            fireBlast.draw(window);
            newX = newX + 1;
            abilityStack.push(newX);
            // std::cout << "ability : " + std::to_string(abilityStack.top)_
        }
        // window.draw(levelone->getImages().at(0));
        pl.display(window);
        // actionbar.drawActionBar(window);
        window.draw(actionbar.actionbar);
        // hoodie.display(window);


        
        window.display();
    }

    return 0;
}