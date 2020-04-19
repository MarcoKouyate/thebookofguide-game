#include "LosingScreen.h"

#include "cocos2d/cocos/2d/CCScene.h"
#include "cocos2d/cocos/2d/CCLabel.h"

cocos2d::Scene* LosingScreen::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    auto layer = LosingScreen::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool LosingScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    
    cocos2d::Label* label = cocos2d::Label::createWithTTF("Game Over", "fonts/arial.ttf", 26);
    label->setPosition(200, 200);
    this -> addChild(label);

    return true;
}
