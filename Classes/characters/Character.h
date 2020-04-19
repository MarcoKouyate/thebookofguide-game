#pragma once

#include <string>
#include "cocos2d.h"
#include "SceneManager.h"
#include "ui/Actionable.h"

class ICharacter {
public:
	virtual void die() = 0;
};


class Character : public ICharacter, public IActionable {
public:
	void die() override;

	Character(std::string name) : name(name) {}

	void rest();
	cocos2d::Menu* Character::getMenu();

	std::function<void(cocos2d::Ref*)> openMenu() override;

protected:
	std::string name;
	unsigned char energy;
	unsigned char hunger;
	unsigned char cold;
	std::map<const char*, std::function<void(cocos2d::Ref*)>> actions;
};

