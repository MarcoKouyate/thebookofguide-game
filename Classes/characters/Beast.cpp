#include "Beast.h"

Beast::Beast (): 
	Character("The Beast") 
{
	createMenu();
	button = cocos2d::ui::Button::create("img/beast_sketch.png");
}


void Beast::createMenu() {
	actions = {
		std::make_pair("Rest", [this](cocos2d::Ref*) { rest(); }),
		std::make_pair("Die", [this](cocos2d::Ref*) { die(); })
	};
}