#pragma once
#include "ui/Actionable.h"

class CampFire : public Actionable {
public:
	CampFire() {
		createMenu();
	}

	void createMenu() {
		actions = {
		std::make_pair("Fuel the fire", [this](cocos2d::Ref*) { fuel(); }),
		std::make_pair("Start a fire", [this](cocos2d::Ref*) { startFire(); })
		};
	}

	void fuel() {
		cocos2d::log("You fueled the fire");
	}

	void startFire() {
		cocos2d::log("You started a fire");
	}
};