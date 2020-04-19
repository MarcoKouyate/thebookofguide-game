#include "Character.h"
#include <iostream>


void Character::die() {
	std::string message = name + " has reached the end of the journey.";
	cocos2d::log(message.c_str());

	SceneManager::getInstance()->lose();
}

void Character::rest() {
	std::string message = name + " is resting now";
	cocos2d::log(message.c_str());
}



