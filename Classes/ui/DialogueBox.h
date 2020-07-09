#pragma once
#include "cocos2d.h"

class DialogueBox {
public:
	void log(std::string value);
	void log(std::vector<std::string> values);

	cocos2d::Label* getLabel();

	void disable();
	void next();

	static DialogueBox* getInstance() {
		if (!instance) instance = new DialogueBox;
		return instance;
	}

private:
	DialogueBox();

	cocos2d::Label* label;
	static DialogueBox* instance;
	std::vector<std::string> messages;
	size_t index;
	bool rendering = false;
};