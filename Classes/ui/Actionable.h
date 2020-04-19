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
	virtual std::function<void(cocos2d::Ref*)> openMenu() = 0;
	virtual cocos2d::Menu* getMenu() = 0;
};