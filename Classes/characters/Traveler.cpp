#include "Traveler.h"
#include "logic/WordLogic.h"
#include "ui/DialogueBox.h"

Traveler::Traveler(std::shared_ptr<WordSelectionMenu> wordSelectionMenu) :
	Character("The Traveler"), 
	wordSelectionMenu(wordSelectionMenu),
	moral(3)
{
	createActions();
	button->init("img/traveler_sketch.png");
	infos = cocos2d::Label::create(getStatusMessage(), "Helvetica", 30);
	infos->setPosition(200.f, 0.f);
	button->addChild(infos);
}

void Traveler::createActions() {
	actions = {
		std::make_pair("Explore", [this](cocos2d::Ref*) { explore(); }),
		std::make_pair("Die", [this](cocos2d::Ref*) { die(); }),
		std::make_pair("Sleep", [this](cocos2d::Ref*) { sleep(); }),
		std::make_pair("Think", [this](cocos2d::Ref*) { think(); })
	};
}

void Traveler::sleep() {
	std::string message = name + " is sleeping";
	std::vector<std::string> sentences = { "Sentence 1", "Sentence 2!" , "Last sentence !" };
	DialogueBox::getInstance()->log(sentences);
}

void Traveler::think() {
	wordSelectionMenu->open();
	DialogueBox::getInstance()->disable();
	menu->setVisible(false);
}

void Traveler::explore() {
	std::string message = name + " is exploring";
	DialogueBox::getInstance()->log(message.c_str());
}

void Traveler::updateFromWordLogic(bool result) {
	if (result) {
		cocos2d::log("Your moral is getting BETTER");
		moral++;
		status();
	}
	else {
		cocos2d::log("Your moral is getting WORSE");
		moral--;
		status();
	}
}

void Traveler::status() {
	if (moral <= 0) {
		die();
	}
	else if (moral > MAX_MORAL) {
		moral = MAX_MORAL;
	}

	infos->setString(getStatusMessage());
}

std::string Traveler::getStatusMessage() {
	return "Moral : " + std::to_string(moral);
}
