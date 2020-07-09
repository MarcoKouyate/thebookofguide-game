#pragma once
#include "2d/CCNode.h"

class ActionManager {
public:
	static ActionManager* getInstance();
	cocos2d::Node* getActiveMenu();
	void replaceMenu(cocos2d::Node* newMenu);

private:
	static ActionManager* instance;
	cocos2d::Node* activeMenu = nullptr;
};

