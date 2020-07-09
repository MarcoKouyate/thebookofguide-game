#pragma once
#include "Character.h"
#include "ui/WordSelectionMenu.h"
#include <map>


class Traveler : public Character, public WordLogicObserver {
public:
	void updateFromWordLogic(bool result) override;
	Traveler(std::shared_ptr<WordSelectionMenu> wordSelection);

private:
	void createActions();
	void explore();
	void sleep();
	void think();


	std::string getStatusMessage();
	void status();

	std::shared_ptr<WordSelectionMenu> wordSelectionMenu;
	int moral;
	const int MAX_MORAL = 4;
	cocos2d::Label* infos;
};
