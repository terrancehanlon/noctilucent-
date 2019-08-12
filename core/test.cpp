#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
int main(){

    sf::Clock clock1;
    sf::Time fTime = clock1.restart();

    for(int i = 0; i < 100000; i++){}
    for(int i = 0; i < 100000; i++){}
    for(int i = 0; i < 100000; i++){}
    for(int i = 0; i < 100000; i++){}
    for(int i = 0; i < 100000; i++){}
    std::cout << std::to_string(fTime.asSeconds()) << std::endl;


    return 0;
}