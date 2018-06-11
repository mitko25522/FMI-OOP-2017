#include <iostream>
#include <windows.h>
#include <time.h>
#include "SpaceShooter.h"
#include "Renderer.h"
#include "InputHandler.h"
#include "Enemy.h"

void test() {
	clock_t initial_ticks = 0;
	clock_t delta_ticks = 0;
	while (true) {
		static bool reset = false;

		if (reset) {
			initial_ticks = clock();
			reset = false;
		}


		delta_ticks = clock() - initial_ticks;

		if (delta_ticks > 17) {
			system("cls");
			//render();
			std::cout << "FPS: " << CLOCKS_PER_SEC / delta_ticks;
			reset = true;
			delta_ticks = 0;
		}


	}
}


//TODO:
//
//handle collisions using collision masks and probably a delegate for that
//add moving patterns (buildings?mountains) in the background
//fix updateEnemyPositions()
//fix spawnNewEnemy in okay periods of time
//fix entity.isInCollisionWith
//test collisions

SpaceShooter* getStartScreenInput() {
	switch (InputHandler::handleGameMenu()) {
	case Choice::NEW_GAME:		return new SpaceShooter(InputHandler::setDifficulty()); break;
	case Choice::LOAD_GAME:		return new SpaceShooter(InputHandler::getSavePath()); break;
	case Choice::HELP:			SpaceShooter::printHelp(); getStartScreenInput(); break;
	case Choice::EXIT:			exit(EXIT_SUCCESS); break;
	}
}

int main() {
	srand(time(NULL));

	Renderer::renderStartScreen();
	SpaceShooter* spaceShooter = getStartScreenInput();

	Renderer::renderGameScreen(spaceShooter);

	clock_t initial_ticks = 0, delta_ticks = 0;
	do {
		static bool itsTimeForNextFrame = false;

		if (itsTimeForNextFrame) {
			initial_ticks = clock();
			itsTimeForNextFrame = false;
		}

		delta_ticks = clock() - initial_ticks;
		
		//performEnemyAction();
		//checkForCollisions();
		//moveEnemies();


		if (delta_ticks > spaceShooter->getDifficulty()) {
			InputHandler::completeUserCommands(*spaceShooter);
			spaceShooter->updateScreen();
			Renderer::renderGameScreen(spaceShooter);
			std::cout << "FPS: " << CLOCKS_PER_SEC / delta_ticks;
			itsTimeForNextFrame = true;
			delta_ticks = 0;
		}
	} while (true);

	return 0;
}