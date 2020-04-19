#include "Traveler.h"


Traveler::Traveler() : 
	Character("The Traveler") 
{
	createMenu();
}

void Traveler::createMenu() {
	actions = {
		std::make_pair("Explore", [this](cocos2d::Ref*) { explore(); }),
		std::make_pair("Die", [this](cocos2d::Ref*) { die(); })
	};
}

void Traveler::explore() {
	std::string message = name + " is exploring";
	cocos2d::log(message.c_str());
}