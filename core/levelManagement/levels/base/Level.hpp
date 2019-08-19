#ifndef LEVEL_INCLUDE
#define LEVEL_INCLUDE

#include <string>
#include <SFML/Graphics.hpp>
#include "/home/terrance/Desktop/games2/noctilucent-/lib/AnimatedSprite.hpp"
#include <vector>
#include "../../../../entities/headers/Dummy.hpp"
#include "../../../../entities/headers/HoodedOccult.hpp"
#include "../../../../entities/headers/Player.hpp"
class Level{

    public: struct EnemyInfo {
        std::string typeName;
        float xPosition;
        float yPosition;
    };

    public: struct LevelConstraints {
        float xRangeStart;
        float xRangeDone;
        float yRangeStart;
        float yRangeDone;
    };

    private:
        std::string levelTitle;  
        std::vector<EnemyInfo> enemieTypes;
        std::vector<LevelConstraints> constraints;                                                                       

    public:
        std::vector<sf::Sprite> images;
        std::vector<HoodedOccult *> occ;
        std::vector<Dummy> entities;
        std::vector<Player *> players;
        std::string getLevelTitle();
        Level();
        Level(std::string name, std::vector<EnemyInfo>);
        std::vector<sf::Sprite> getImages(); 
        void addImage(sf::Sprite sprite);
        std::vector<Dummy> getEntities();
        void addEntitiy(Dummy dummy);
        void draw(sf::RenderWindow &window, std::vector<Dummy> enemies);
        int getEnemyTypeCount();  
        std::vector<EnemyInfo> getEnemyTypes();
        void setLevelTitle(std::string title);
        void setEnemyTypes(std::vector<EnemyInfo> info);
        bool checkIfConstraint(float x, float y);
        void insertConstraint(LevelConstraints constraint);


};

#endif