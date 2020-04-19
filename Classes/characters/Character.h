#pragma once

#include <string>
#include "cocos2d.h"
#include "SceneManager.h"
#include "ui/Actionable.h"

class ICharacter {
public:
	virtual void die() = 0;
};


class Character : public ICharacter, public Actionable {
public:
	void die() override;

	Character(std::string name) : name(name) {}

	void rest();

protected:
	std::string name;
	unsigned char energy;
	unsigned char hunger;
	unsigned char cold;
};

