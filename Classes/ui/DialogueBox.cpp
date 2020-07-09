#include "DialogueBox.h"


DialogueBox* DialogueBox::instance = nullptr;

DialogueBox::DialogueBox() {
	label = cocos2d::Label::create("", "Helvetica", 15);
	label->setWidth(300);
}

cocos2d::Label* DialogueBox:: getLabel() {
	return label;
}

void DialogueBox::disable() {
	label->setVisible(false);
	rendering = false;
}

void DialogueBox::log(std::string value) {
	label->setVisible(true);
	label->setString(value);
}

void DialogueBox::next() {
	if (index >= messages.size()) {
		disable();
	}
	else {
		if (messages.size() > 0 && rendering) {
			log(messages.at(index));
			index++;
		}
	}
}

void DialogueBox::log(std::vector<std::string> values) {
	rendering = true;
	index = 0;
	messages = values;
	next();
}