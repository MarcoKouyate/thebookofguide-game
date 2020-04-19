#pragma once
#include <functional>
#include "cocos2d.h"


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
};

class Actionable : public IActionable {
public:
	virtual cocos2d::Menu* getMenu();

protected:
	std::map<const char*, std::function<void(cocos2d::Ref*)>> actions;
};