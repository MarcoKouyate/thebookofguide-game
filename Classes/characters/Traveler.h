#pragma once
#include "Character.h"
#include <map>


class Traveler : public Character {
public:
	void createMenu();
	void explore();
	void injectMenu();
	void openMenu(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

	Traveler();
};
