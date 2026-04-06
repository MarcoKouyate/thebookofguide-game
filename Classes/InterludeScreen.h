#pragma once
#include "cocos2d/cocos/2d/CCScene.h"
#include "cocos2d/cocos/2d/CCLabel.h"

class InterludeScreen : public cocos2d::Scene
{
public:
    static InterludeScreen* createScene();

    virtual bool init();
    void changeTitle(const std::string& title);

    // implement the "static create()" method manually
    CREATE_FUNC(InterludeScreen);

private: 
    cocos2d::Label* label;
};