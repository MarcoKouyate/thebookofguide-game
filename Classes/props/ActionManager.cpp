#include "ActionManager.h"

ActionManager* ActionManager::instance = nullptr;

ActionManager* ActionManager::getInstance() {
	if (!instance) {
		instance = new ActionManager;
	}

	return instance;
}

void ActionManager::replaceMenu(cocos2d::Node* newMenu) {
	activeMenu = newMenu;
}

cocos2d::Node* ActionManager::getActiveMenu() {
	return activeMenu;
}

ActionManager::ActionManager() {

}