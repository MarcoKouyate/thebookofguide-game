#include "GameLogic.h"
#include <vector>
#include "tools/Console.h"



GameLogic* GameLogic::instance = nullptr;

void GameLogic::start() {
	sceneManager.startGame();
	//sceneManager.interlude("Day 1");
}

void GameLogic::lose() {
	sceneManager.interlude("Game Over");
}