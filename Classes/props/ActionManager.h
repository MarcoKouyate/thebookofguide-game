#pragma once
#include "2d/CCNode.h"

class ActionManager {
public:
	static ActionManager* getInstance();

	void replaceMenu(cocos2d::Node* newMenu);

	cocos2d::Node* getActiveMenu();



private:
	static ActionManager* instance;
	cocos2d::Node* activeMenu = nullptr;

	ActionManager();
};

