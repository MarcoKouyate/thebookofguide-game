#include "ActionManager.h"

ActionManager* ActionManager::instance = nullptr;

ActionManager* ActionManager::getInstance() {
	if (!instance) {
		instance = new ActionManager;
	}

	return instance;
}

void ActionManager::replaceMenu(cocos2d::Node* newMenu) {
	if (activeMenu != nullptr) {
		activeMenu->setVisible(false);
	}
	activeMenu = newMenu;
	activeMenu->setVisible(true);
}

cocos2d::Node* ActionManager::getActiveMenu() {
	return activeMenu;
}
