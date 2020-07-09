#pragma once
#include <functional>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "props/ActionManager.h"

class Actionable {
public:
	Actionable(){
		button = cocos2d::ui::Button::create();
		button->addTouchEventListener(CC_CALLBACK_2(Actionable::openMenu, this));
	}

	// Button
	virtual cocos2d::ui::Button* getButton();

	// Built-in Menu
	virtual cocos2d::Menu* getMenu();
	virtual cocos2d::Menu* createMenu();
	virtual void openMenu(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

protected:
	cocos2d::ui::Button* button = nullptr;
	std::map<const char*, std::function<void(cocos2d::Ref*)>> actions;
	cocos2d::Menu* menu = nullptr;
};