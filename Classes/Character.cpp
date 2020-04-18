#include "Character.h"
#include <iostream>


void Character::die() {
	std::string message = name + " has reached the end of the journey.";
	cocos2d::log(message.c_str());
}