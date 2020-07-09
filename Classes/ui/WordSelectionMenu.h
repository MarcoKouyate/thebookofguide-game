#pragma once

#include "cocos2d.h"
#include "logic/WordLogic.h"
#include "DialogueBox.h"



class WordSelectionMenu {
public:
	cocos2d::Menu* getMenu();
	void select(std::string value);
	void enable(bool input);
	void reset();
	void open();

	WordSelectionMenu(std::vector<std::string> words, std::shared_ptr<WordLogic> wordLogic);


private:
	void submit();

	cocos2d::Menu* menu;
	std::vector<std::string> selectedWords;
	std::shared_ptr<WordLogic> wordLogic;
};