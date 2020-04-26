#include "Beast.h"

Beast::Beast (): 
	Character("The Beast") 
{
	createActions();
	button->init("img/beast_sketch.png");
}


void Beast::createActions() {
	actions = {
		std::make_pair("Rest", [this](cocos2d::Ref*) { rest(); }),
		std::make_pair("Die", [this](cocos2d::Ref*) { die(); })
	};
}