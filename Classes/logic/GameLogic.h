#pragma once
#include "SceneManager.h"


class GameLogic {
public:
	void start();
	void lose();

	static GameLogic* getInstance() {
		if (!instance) {
			instance = new GameLogic();
		}
		return instance;
	}

private:
	GameLogic(){};

	static GameLogic* instance;
	SceneManager sceneManager;
};