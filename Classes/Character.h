#pragma once

#include <string>
#include "cocos2d.h"

enum class state { critical, heavy, moderate, light, normal };

class ICharacter {
public:
	virtual void die() = 0;
};

class Character : ICharacter {
public:
	virtual void die() override;

protected:
	std::string name;
	unsigned char energy;
	unsigned char hunger;
	unsigned char cold;
};

class Traveler : public Character {
public:
	Traveler() {
		name = "The Traveler";
	}
};


class Beast : public Character {
public:
	Beast() {
		name = "The Beast";
	}
};