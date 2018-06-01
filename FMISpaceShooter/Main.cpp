#include <iostream>
#include <windows.h>
#include <time.h>
#include "Renderer.h"
#include "InputHandler.h"
#include "SpaceShooter.h"

int main() {
	clock_t tStart = clock();

	SpaceShooter* spaceShooter;

	Renderer::renderStartScreen();
	switch (InputHandler::handleGameMenu()) {
	case Choice::NEW_GAME: spaceShooter = new SpaceShooter(); break;
	case Choice::LOAD_GAME: spaceShooter = new SpaceShooter(SpaceShooter::getSavePath()); break;
	case Choice::HELP: SpaceShooter::printHelp();
	case Choice::EXIT: return 0;
	}

	do {
		//renderGameScreen();
		//InputHandler::listenForCommand();
		//completeUserCommandIfPresent();
		//performEnemyAction();
		//checkForCollisions();
		//moveProjectiles();
		//moveEnemies();
	} while (false);


	printf("\n\n\nTime taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	return 0;
}