#include <iostream>
#include <windows.h>
#include "InputHandler.h"
#include "Renderer.h"

Choice InputHandler::handleGameMenu() {
	do {
		if (GetAsyncKeyState(0x45)) {
			return Choice::EXIT;
		}

		if (GetAsyncKeyState(0x4E)) {
			return Choice::NEW_GAME;
		}

		if (GetAsyncKeyState(0x4C)) {
			return Choice::LOAD_GAME;
		}

		if (GetAsyncKeyState(0x48)) {
			return Choice::HELP;
		}

		Sleep(50);
	} while (true);
}

char* InputHandler::getSavePath()
{
	std::cout << "Please enter game save file path> ";
	char* path = new char[1024];
	std::cin.getline(path, 1024);
	return path;
}

int InputHandler::setDifficulty()
{
	Renderer::renderDifficultySelectionScreen();
	do {
		if (GetAsyncKeyState(0x45)) {
			return DIFFICULTY_EASY;
		}

		if (GetAsyncKeyState(0x4D)) {
			return DIFFICULTY_MEDIUM;
		}

		if (GetAsyncKeyState(0x49)) {
			return DIFFICULTY_INTERMEDIATE;
		}


		Sleep(50);
	} while (true);
}

void InputHandler::completeUserCommands(SpaceShooter& spaceShooter) {
	if (GetAsyncKeyState(VK_UP)) {
		spaceShooter.getPlayer()->moveUp();
	}

	if (GetAsyncKeyState(VK_DOWN)) {
		spaceShooter.getPlayer()->moveDown();
	}

	if (GetAsyncKeyState(VK_LEFT)) {
		spaceShooter.getPlayer()->moveLeft();
	}

	if (GetAsyncKeyState(VK_RIGHT)) {
		spaceShooter.getPlayer()->moveRight();
	}

	if (GetAsyncKeyState(VK_SPACE)) {
		//Projectile newProjectile(spaceShooter.getPlayer()->gunPosX, spaceShooter.getPlayer()->gunPosY, true);
		//spaceShooter.projectiles.push_back(newProjectile);
	}
}
