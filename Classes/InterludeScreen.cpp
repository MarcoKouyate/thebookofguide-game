#include "InterludeScreen.h"

#include "cocos2d/cocos/2d/CCScene.h"


InterludeScreen* InterludeScreen::createScene()
{
    return InterludeScreen::create();
}

// on "init" you need to initialize your instance
bool InterludeScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    
    label = cocos2d::Label::createWithTTF("Game Over", "fonts/arial.ttf", 26);
    label->setPosition(200, 200);
    this -> addChild(label);

    return true;
}

void InterludeScreen::changeTitle(const std::string& title) {
    label->setString(title);
}
