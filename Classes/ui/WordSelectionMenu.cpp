#include "WordSelectionMenu.h"

WordSelectionMenu::WordSelectionMenu(std::vector<std::string> words, std::shared_ptr<WordLogic> wordLogic) : wordLogic(wordLogic) {
	cocos2d::Vector<cocos2d::MenuItem*> menuItems;

	for (std::string word : words)
	{
		cocos2d::MenuItemFont* item = cocos2d::MenuItemFont::create(word, [&, word](cocos2d::Ref*) {  select(word); });
		menuItems.pushBack(item);
	}


	menu = cocos2d::Menu::createWithArray(menuItems);
	menu->alignItemsVertically();
}

cocos2d::Menu* WordSelectionMenu::getMenu() {
	return menu;
}

void WordSelectionMenu::select(std::string value) {
	std::string message = value + " has been selected!";
	selectedWords.push_back(value);

	if (selectedWords.size() >= 3) {
		submit();
	}

	cocos2d::log(message.c_str());
}


void WordSelectionMenu::submit() {
	enable(false);

	std::vector<std::string> messages = wordLogic->choose(selectedWords.at(0), selectedWords.at(1), selectedWords.at(2));
	wordLogic->clear();
	DialogueBox::getInstance()->log(messages);
}

void WordSelectionMenu::enable(bool input) {
	menu->setVisible(input);
}

void WordSelectionMenu::reset() {
	selectedWords.clear();
}

void WordSelectionMenu::open() {
	reset();
	enable(true);
}

