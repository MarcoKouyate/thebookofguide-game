#pragma once
#include "cocos2d/cocos/2d/CCScene.h"

class LosingScreen : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(LosingScreen);
};