#ifndef FIREBLAST_INCLUDE
#define FIREBLAST_INCLUDE
#include "../Ability.hpp"
#include <SFML/Graphics.hpp>


class FireBlast : public Ability {

    public:
        FireBlast(int x, int y);
        sf::Texture texture;
    


};

#endif