#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "characters/Beast.h"
#include "characters/Traveler.h"
#include "props/CampFire.h"

#include "cocos2d.h"


cocos2d::Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    auto layer = GameScene::create();

    scene->addChild(layer);

    return scene;
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }


    Traveler* traveler = new Traveler;
    Beast* beast = new Beast;
    CampFire* fire = new CampFire;

    makeScene();

    this->addChild(fire->getMenu(), 3);


    return true;
}


void GameScene::makeScene() {
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    cocos2d::Label* label = cocos2d::Label::createWithTTF("Game Scene", "fonts/arial.ttf", 26);
    cocos2d::Sprite* travelerSprite = cocos2d::Sprite::create("img/traveler_sketch.png");
    cocos2d::Sprite* beastSprite = cocos2d::Sprite::create("img/beast_sketch.png");
    cocos2d::Sprite* background = cocos2d::Sprite::create("img/forest_bg.jpg");
    cocos2d::Sprite* fire = cocos2d::Sprite::create("img/fire.png");

    travelerSprite->setPosition(visibleSize.width / 2 + visibleSize.width / 4, visibleSize.height / 2 - 50);
    background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    background->setScale(1.4);
    fire->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 65);
    fire->setScale(0.2);
    beastSprite->setPosition(visibleSize.width / 2 - visibleSize.width / 5, visibleSize.height / 2 - 50);
    travelerSprite->setScale(0.3f);
    beastSprite->setScale(0.4f);

    label->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    //travelerSprite->addChild(label, 1);

    this->addChild(travelerSprite, 2);
    this->addChild(beastSprite, 2);
    this->addChild(fire, 2);
    this->addChild(background, 1);
}
