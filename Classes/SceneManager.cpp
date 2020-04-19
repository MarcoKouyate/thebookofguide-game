#include "SceneManager.h"
#include "LosingScreen.h"
#include "cocos/base/CCDirector.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager()
{}

void SceneManager::lose() {
	cocos2d::log("GAME OVER");
	auto losingScreen = LosingScreen::createScene();
	cocos2d::Director::getInstance()->replaceScene(losingScreen);
}

SceneManager* SceneManager::getInstance(){
	if (!instance)
	{ 
		instance = new SceneManager;
	}
		

	return instance;
}