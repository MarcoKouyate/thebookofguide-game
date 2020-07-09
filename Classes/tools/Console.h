#pragma once
#include "cocos2d.h"
#include <string>

class Console {
public:
	static void log(std::string input) {
		cocos2d::log(input.c_str());
	}

private: 
	Console() {}
};