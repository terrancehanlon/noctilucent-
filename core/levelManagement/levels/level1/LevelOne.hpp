    #ifndef LEVELONE_INCLUDE
#define LEVELONE_INCLUDE


#include "../base/Level.hpp"
#include <string>


class LevelOne : public Level{
    private:
        sf::Texture texture1;

    public:
        LevelOne(std::string name);
        void setUpTextures();
};

#endif