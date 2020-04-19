#pragma once
#include "Character.h"
#include <map>


class Traveler : public Character {
public:
	void createMenu();
	void explore();
	void injectMenu();

	Traveler();
};
