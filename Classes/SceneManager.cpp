#include "SceneManager.h"
#include "InterludeScreen.h"
#include "cocos/base/CCDirector.h"
#include "GameScene.h"

void SceneManager::scene() {
	interlude("Day 1");
}

void SceneManager::startGame() {
	auto gameScene = GameScene::createScene();
	cocos2d::Director::getInstance()->runWithScene(gameScene);
}

void SceneManager::interlude(const std::string& title) {
	auto interludeScreen = InterludeScreen::createScene();
	interludeScreen->changeTitle(title);
	cocos2d::Director::getInstance()->replaceScene(interludeScreen);
}
