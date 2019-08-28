#include "AnimationHandler.hpp"
#include "../../lib/Animation.hpp"
#include <iostream>


void AnimationHandler::addAnimation(std::string key, Animation animation){
    this->animations[key] = animation;
    // return;
};

Animation& AnimationHandler::getAnimation(std::string key){
    std << cout 
    if(this->animations.size() == 0){
        std::cout<< "empty map" << std::endl;
        // return nullptr;
    }
    return this->animations.at(key);
};

