#include <iostream>
#include <windows.h>
#include <time.h>
#include "Renderer.h"
#include "InputHandler.h"
#include "SpaceShooter.h"
#include "Entity.h"

void render() {
	static int counter = 0;
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			std::cout << " ";
			if (j == counter) {
				std::cout << "-";
			}
			/*	if (j == counter + 1) {
					std::cout << "-";
				}
				if (j == counter + 2) {
					std::cout << "!";
				}*/
		}
		std::cout << std::endl;
	}

	if (counter >= SCREEN_WIDTH) {
		counter = 0;
	}
	else {
		counter++;
	}
}

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
			render();
			std::cout << "FPS: " << CLOCKS_PER_SEC / delta_ticks;
			reset = true;
			delta_ticks = 0;
		}


	}
}

void test2() {
	clock_t current_ticks, delta_ticks = 0;
	while (true) {
		current_ticks = clock();
		render();
		//Sleep(10);
		delta_ticks = clock() - current_ticks;
		if (delta_ticks > 0)
			std::cout << CLOCKS_PER_SEC / delta_ticks << std::endl;
	}
}


//TODO:
//
//fix printHelp
//create game loop
//start implementing entity
//start implementing player
//start implementing projectiles
//handle collisions using collision masks and probably a delegate for that
//add moving patterns (buildings?mountains) in the background
//add renderGameScreen to Renderer (taking SpaceShooter as an argument)
//show difficulty in renderGameScreen
//add enemy lives
//add player shoot projectile
//add player score (to renderGameScreen aswell)
//add player lives (to renderGameScreen aswell)
//

SpaceShooter* getStartScreenInput() {
	switch (InputHandler::handleGameMenu()) {
	    case Choice::NEW_GAME:		return new SpaceShooter(InputHandler::setDifficulty()); break;
	    case Choice::LOAD_GAME:		return new SpaceShooter(InputHandler::getSavePath()); break;
	    case Choice::HELP:			SpaceShooter::printHelp(); getStartScreenInput(); break;
	    case Choice::EXIT:			exit(EXIT_SUCCESS); //Obreak;
	}
}

int main() {
	clock_t tStart = clock();

	Renderer::renderStartScreen();
	SpaceShooter* spaceShooter = getStartScreenInput();

	//spawnPlayer();
	Renderer::renderGameScreen(spaceShooter);

	clock_t initial_ticks = 0, delta_ticks = 0;
	do {
		static bool reset = false;

		if (reset) {
			initial_ticks = clock();
			reset = false;
		}

		delta_ticks = clock() - initial_ticks;

		//completeUserCommandIfPresent();
		//performEnemyAction();
		//checkForCollisions();
		//moveProjectiles();
		//moveEnemies();
		//spawnEnemy();
		if (delta_ticks > spaceShooter->getDifficulty()) {
			Renderer::renderGameScreen(spaceShooter);
			std::cout << "FPS: " << CLOCKS_PER_SEC / delta_ticks;
			reset = true;
			delta_ticks = 0;
		}
	} while (true);


	printf("\n\n\nTime taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	return 0;
}