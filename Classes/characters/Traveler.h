#pragma once
#include "Character.h"
#include <map>


class Traveler : public Character {
public:
	void createActions();
	void explore();
	void injectMenu();

	Traveler();
};
