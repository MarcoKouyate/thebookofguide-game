#pragma once
#include <functional>
#include "cocos2d.h"
#include "ui/CocosGUI.h"


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
	virtual cocos2d::ui::Button* getButton() = 0;
};

class Actionable : public IActionable {
public:
	virtual cocos2d::Menu* getMenu();
	cocos2d::ui::Button* getButton() override;

protected:
	cocos2d::ui::Button* button;
	std::map<const char*, std::function<void(cocos2d::Ref*)>> actions;
};