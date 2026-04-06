#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "characters/Beast.h"
#include "characters/Traveler.h"
#include "props/CampFire.h"
#include "props/ActionManager.h"
#include "ui/DialogueBox.h"
#include "ui/WordSelectionMenu.h"

#include "cocos2d.h"

#include "logic/WordLogic.h"


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

    enableTouch();
    makeScene();
    return true;
}

void GameScene::enableTouch() {
    auto touchListener = cocos2d::EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = [](cocos2d::Touch* touch, cocos2d::Event* event) {
        return true; 
    };

    touchListener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event) {
        DialogueBox::getInstance()->next();
    };

    touchListener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void GameScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    DialogueBox::getInstance()->next();
}
void GameScene::onTouch(cocos2d::Event* event)
{
    DialogueBox::getInstance()->next();
}
;

void GameScene::makeScene() {
    std::vector<std::string> words = { "Book", "Travel", "Ice Cream", "Handbag", "Oasis" };
    std::shared_ptr<WordLogic> wordLogic = std::make_shared<WordLogic>();
    std::shared_ptr<WordSelectionMenu> wordSelectionMenu = std::make_shared<WordSelectionMenu>(words, wordLogic);
    Traveler* traveler = new Traveler(wordSelectionMenu);
    wordLogic->subscribe(traveler);
    Beast* beast = new Beast;
    CampFire* fire = new CampFire;

    cocos2d::ui::Button* travelerSprite = traveler->getButton();
    cocos2d::ui::Button* beastSprite = beast->getButton();
    cocos2d::ui::Button* fireSprite = fire->getButton();
    cocos2d::Layer* gameLayer = cocos2d::LayerColor::create();
    cocos2d::Layer* uiLayer = cocos2d::LayerColor::create();




    gameLayer->addChild(travelerSprite);
    gameLayer->addChild(beastSprite);
    gameLayer->addChild(fireSprite);
    uiLayer->addChild(wordSelectionMenu->getMenu());

    cocos2d::Sprite* background = cocos2d::Sprite::create("img/forest_bg.jpg");
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();  

    gameLayer->setContentSize(visibleSize);
    //gameLayer->setColor(cocos2d::Color3B(0, 0, 255));
    //gameLayer->setOpacity(128);
    gameLayer->setPosition(cocos2d::Vec2(0, 0));

    uiLayer->setContentSize(visibleSize);
    //uiLayer->setColor(cocos2d::Color3B(255, 0, 0));
    uiLayer->setOpacity(128);
    uiLayer->setPosition(cocos2d::Vec2(0, 0));

    this->addChild(uiLayer, 3);
    this->addChild(gameLayer, 2);
    this->addChild(background, 1);

    //disable buttons
    gameLayer->setTouchEnabled(false);
    uiLayer->setTouchEnabled(true);

    //placement de sprites
    DialogueBox::getInstance()->getLabel()->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 + visibleSize.height / 4));
    travelerSprite->setPosition(cocos2d::Vec2(visibleSize.width / 2 + visibleSize.width / 4, visibleSize.height / 2 - 50));
    background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    background->setScale(1.4);
    fireSprite->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 - 65));
    fireSprite->setScale(0.2);
    beastSprite->setPosition(cocos2d::Vec2(visibleSize.width / 2 - visibleSize.width / 5, visibleSize.height / 2 - 50));
    travelerSprite->setScale(0.3f);
    beastSprite->setScale(0.4f);
    
    
    this->addChild(fire->getMenu(), 3);
    this->addChild(beast->getMenu(), 3);
    this->addChild(traveler->getMenu(), 3);
    this->addChild(DialogueBox::getInstance()->getLabel(), 3);

    fire->getMenu()->setVisible(false);
    beast->getMenu()->setVisible(false);
    traveler->getMenu()->setVisible(false);
}


