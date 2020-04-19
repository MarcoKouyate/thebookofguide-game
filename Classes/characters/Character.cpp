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


std::function<void(cocos2d::Ref*)> Character::openMenu() {
	return [&](cocos2d::Ref* sender) {
		SceneManager::getInstance()->lose();
	};
}

cocos2d::Menu* Character::getMenu() {
	cocos2d::Vector<cocos2d::MenuItem*> menuItems;


	std::map<const char*, std::function<void(cocos2d::Ref*)>>::iterator action;
	int iteration = 0;

	for (action = actions.begin(); action != actions.end(); action++)
	{
		cocos2d::MenuItemFont* button = cocos2d::MenuItemFont::create(action->first, action->second);
		button->setPosition(0, iteration * 50);
		menuItems.pushBack(button);
		iteration++;
	}


	// create menu, it's an autorelease object
	return cocos2d::Menu::createWithArray(menuItems);
}
