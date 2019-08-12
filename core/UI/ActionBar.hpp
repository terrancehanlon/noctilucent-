#ifndef ACTIONBAR_INCLUDE
#define ACTIONBAR_INCLUDE
#include <string>
#include <vector>
#include "../TextureManager.hpp"

struct ability {
    int index; //hotkey
    std::string name;
    int damage;
    int cost;
};

class ActionBar {

    private:
        std::vector<ability> currentAbilities;
    public:
        sf::Sprite actionbar;
        TextureManager tm;
        ActionBar(TextureManager tm);
        std::vector<ability> getAllAbilities();
        void setAbilitiy(ability);
        ability useAbility(int indexOfAbility);
        void drawActionBar(sf::RenderWindow &window);



};


#endif