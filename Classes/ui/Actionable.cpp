#include "Actionable.h"
#include "DialogueBox.h"

cocos2d::Menu* Actionable::getMenu() {
	if (!menu) {
		menu = createMenu();
	}

	return menu;
}

cocos2d::Menu* Actionable::createMenu() {
	cocos2d::Vector<cocos2d::MenuItem*> menuItems;
	std::map<const char*, std::function<void(cocos2d::Ref*)>>::iterator action;
	
	// TODO replace with for loop
	// TODO manage spacing between items 

	for (action = actions.begin(); action != actions.end(); action++)
	{
		cocos2d::MenuItemFont* item = cocos2d::MenuItemFont::create(action->first, action->second);
		menuItems.pushBack(item);
	}
	
	cocos2d::Menu* menu = cocos2d::Menu::createWithArray(menuItems);
	menu->setScale(0.5);

	cocos2d::ui::Button* button = getButton();
	float margin = 30;
	menu->setPosition(button->getPositionX() + margin, button->getPositionY() + margin);
	cocos2d::Vec2 point(0, 0);
	menu->setAnchorPoint(point);
	menu->alignItemsVertically();

	return menu;
}

cocos2d::ui::Button* Actionable::getButton() {
	return button;
}


void Actionable::openMenu(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		DialogueBox::getInstance()->disable();
		ActionManager::getInstance()->replaceMenu(getMenu());
		break;

	default:
		break;
	}
}