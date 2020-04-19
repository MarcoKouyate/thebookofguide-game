#include "Actionable.h"


cocos2d::Menu* Actionable::getMenu() {
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

cocos2d::ui::Button* Actionable::getButton() {
	return button;
}