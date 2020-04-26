#include "Traveler.h"
#include "props/ActionManager.h"


Traveler::Traveler() : 
	Character("The Traveler") 
{
	createMenu();
	button = cocos2d::ui::Button::create("img/traveler_sketch.png");
	button->addTouchEventListener(CC_CALLBACK_2(Traveler::openMenu, this));
}

void Traveler::createMenu() {
	actions = {
		std::make_pair("Explore", [this](cocos2d::Ref*) { explore(); }),
		std::make_pair("Die", [this](cocos2d::Ref*) { die(); })
	};
}

void Traveler::explore() {
	std::string message = name + " is exploring";
	cocos2d::log(message.c_str());
}

void Traveler::openMenu(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
    cocos2d::ui::ListView* listView = static_cast<cocos2d::ui::ListView*>(sender);

    switch (type)
    {
    case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_START:

		cocos2d::log("select child start index = %ld", listView->getCurSelectedIndex());

        break;

    case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END:
		cocos2d::log("select child end index = %ld", listView->getCurSelectedIndex());

        break;

    default:
        break;
    }

	ActionManager::getInstance()->replaceMenu(getMenu());
	cocos2d::log("change menu !");
}