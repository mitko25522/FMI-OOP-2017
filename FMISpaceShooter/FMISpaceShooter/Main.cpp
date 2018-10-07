#include <iostream>
#include <windows.h>
#include <time.h>
#include "SpaceShooter.h"
#include "Renderer.h"
#include "InputHandler.h"
#include "Enemy.h"

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

	Renderer::renderInitialGameScreen(spaceShooter);
	clock_t initial_ticks = 0, delta_ticks = 0;
	do {
		static bool itsTimeForNextFrame = false;

		if (itsTimeForNextFrame) {
			initial_ticks = clock();
			itsTimeForNextFrame = false;
		}

		delta_ticks = clock() - initial_ticks;

		try {
			if (delta_ticks > spaceShooter->getDifficulty()) {
				InputHandler::completeUserCommands(*spaceShooter);
				spaceShooter->generateEnemyProjectiles();
				spaceShooter->updateScreen();
				Renderer::modifyRenderedScreen(spaceShooter);
				//std::cout << "FPS: " << CLOCKS_PER_SEC / delta_ticks;
				itsTimeForNextFrame = true;
				delta_ticks = 0;
			}
		}
		catch (const std::out_of_range&) {
			continue;
		}

		if (spaceShooter->getPlayer()->getScore() >= BOSS_SPAWN_SCORE && spaceShooter->noBossHasBeenSpawnedYet) {
			spaceShooter->startBossFight();
		}

		if (spaceShooter->getPlayer()->getRemainingLives() <= 0) {
			Renderer::printGameOverScreen(spaceShooter);
			break;
		}

	} while (true);

	return 0;
}