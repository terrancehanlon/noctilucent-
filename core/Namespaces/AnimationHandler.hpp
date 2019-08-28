
#ifndef ANIMATIONHANDLER_INCLUDE
#define ANIMATIONHANDLER_INCLUDE

#include "../../lib/AnimatedSprite.hpp"
#include "../../lib/Animation.hpp"
#include <map>
#include <string>


    class AnimationHandler {

        public:
            std::map<std::string, Animation> animations;
            Animation& getAnimation(std::string key);
            void addAnimation(std::string key, Animation animation);

    };



#endif