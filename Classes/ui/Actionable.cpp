#include "Actionable.h"


cocos2d::Menu* Actionable::getMenu() {
	int test;

	if (!menu) {
		createMenu();
	}

	return menu;
}

void Actionable::createMenu() {
	cocos2d::Vector<cocos2d::MenuItem*> menuItems;


	std::map<const char*, std::function<void(cocos2d::Ref*)>>::iterator action;
	int iteration = 0;

	for (action = actions.begin(); action != actions.end(); action++)
	{
		cocos2d::MenuItemFont* button = cocos2d::MenuItemFont::create(action->first, action->second);
		button->setPosition(0, iteration * 50);
		menuItems.pushBack(button);
		iteration++;
	}


	// create menu, it's an autorelease object
	menu = cocos2d::Menu::createWithArray(menuItems);
}

cocos2d::ui::Button* Actionable::getButton() {
	return button;
}


void Actionable::openMenu(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
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