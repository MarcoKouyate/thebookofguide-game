#pragma once
#include <functional>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "props/ActionManager.h"

//class ActionManager {
//public:
//	static std::function<void(cocos2d::Ref*)> action(void(*function)());
//};

//std::function<void(cocos2d::Ref*)> ActionManager::action(void(*function)()) {
//	return [&](cocos2d::Ref* sender) {
//		function();
//	};
//}

class IActionable {
public:
	virtual cocos2d::Menu* getMenu() = 0;
	virtual void createMenu() = 0;
	virtual cocos2d::ui::Button* getButton() = 0;
};

class Actionable : public IActionable {
public:
	Actionable(){
		button = cocos2d::ui::Button::create();
		button->addTouchEventListener(CC_CALLBACK_2(Actionable::openMenu, this));
	}

	virtual cocos2d::Menu* getMenu() override;
	virtual cocos2d::ui::Button* getButton() override;
	virtual void createMenu() override;
	virtual void openMenu(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

protected:
	cocos2d::ui::Button* button = nullptr;
	std::map<const char*, std::function<void(cocos2d::Ref*)>> actions;
	cocos2d::Menu* menu = nullptr;
};