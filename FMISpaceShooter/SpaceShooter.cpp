#include <iostream>
#include <windows.h>
#include "SpaceShooter.h"
#include "Renderer.h"

void SpaceShooter::printHelp() {
	system("cls");
	std::cout << "Welcome to FMISpaceShooter\n";
	std::cout << "Here you will encounter enemies_container bla bla bla..\n";
	std::cout << "Bla bla bla bla bla..\n";
	std::cout << "Bla bla bla bla bla..\n";
	std::cout << "Bla bla bla bla bla..\n";
	std::cout << "Bla bla bla bla bla..\n";
	std::cout << "Bla bla bla bla bla..\n";
	std::cout << "Bla bla bla bla bla..\n";

	std::cout << "\n\nPress \"Escape\" to go back to the start screen.\n";
	do {
		if (GetAsyncKeyState(VK_ESCAPE)) {
			system("cls");
			Renderer::printStaticStartScreen();
			return;
		}
		Sleep(50);
	} while (true);
}

int SpaceShooter::getDifficulty() {
	return this->difficulty;
}

void SpaceShooter::updatePlayerPositioningOnScreen() {
	int playerPrevPosX = player.getPosX();
	int playerPrevPosY = player.getPosY();

	int currentPlayerIndexX = 0;
	int currentPlayerIndexY = 0;

	for (int i = playerPrevPosY; i < playerPrevPosY + player.getHeight(); i++) {
		for (int j = playerPrevPosX; j < playerPrevPosX + player.getWidth(); j++) {
			this->pixelGrid[i][j] = player.getChar(currentPlayerIndexY, currentPlayerIndexX);
			currentPlayerIndexX++;
		}
		currentPlayerIndexX = 0;
		currentPlayerIndexY++;
	}
}

void SpaceShooter::updateProjectilePositions() {
	for (int i = 0; i < projectiles_container.size(); i++) {
		if (projectiles_container.at(i).isItFromPlayer()) {
			projectiles_container.at(i).moveRight(2);
			if (projectiles_container.at(i).getPosX() >= SCREEN_WIDTH - 1) {
				projectiles_container.erase(projectiles_container.begin() + i);
				continue;
			}
			this->pixelGrid[projectiles_container.at(i).getPosY()][projectiles_container.at(i).getPosX()] = this->projectiles_container.at(i).getChar(0, 0);
		}

		if (!projectiles_container.at(i).isItFromPlayer()) {
			projectiles_container.at(i).moveLeft(2);
			this->pixelGrid[projectiles_container.at(i).getPosY()][projectiles_container.at(i).getPosX()] = this->projectiles_container.at(i).getChar(0, 0);
		}
	}


}

void SpaceShooter::clearScreenPixelGrid() {
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			pixelGrid[i][j] = ' ';
		}
	}
}

void SpaceShooter::updateEnemyPositions() {
	for (int i = 0; i < enemies_container.size(); i++) {
		enemies_container.at(i).moveLeft(1);

		if (enemies_container.at(i).getPosX() <= 0) {
			enemies_container.erase(enemies_container.begin() + i);
		}

		for (int currentEnemyPosX = 0; currentEnemyPosX < enemies_container.at(i).getWidth(); currentEnemyPosX++) {
			this->pixelGrid[enemies_container.at(i).getPosY()][currentEnemyPosX + enemies_container.at(i).getPosX()] = enemies_container.at(i).getChar(0, currentEnemyPosX);
		}
	}
}

void SpaceShooter::spawnNewEnemy() {
	Enemy newEnemy(rand() % SCREEN_HEIGHT);
	bool isInAnyCollision = false;

	for (int i = 0; i < enemies_container.size(); i++) {
		if (newEnemy.isInCollisionWith(enemies_container.at(i))) {
			isInAnyCollision = true;
		}
	}

	if (isInAnyCollision) {
		spawnNewEnemy();
	}
	else {
		enemies_container.push_back(newEnemy);
	}
}

SpaceShooter::SpaceShooter() {
	clearScreenPixelGrid();

	this->difficulty = DIFFICULTY_MEDIUM;
	std::cout << "Selected medium difficulty\n";
	std::cout << "Starting new game\n";
	Sleep(2000);
}

SpaceShooter::SpaceShooter(int difficulty) {
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			pixelGrid[i][j] = ' ';
		}
	}

	this->difficulty = difficulty;
	std::cout << "Selected ";
	switch (difficulty) {
	case DIFFICULTY_EASY: std::cout << "easy difficulty\n"; break;
	case DIFFICULTY_MEDIUM: std::cout << "medium difficulty\n"; break;
	case DIFFICULTY_INTERMEDIATE: std::cout << "intermediate difficulty\n"; break;
	}
	std::cout << "Starting new game\n";
	Sleep(1000);
}

SpaceShooter::SpaceShooter(const SpaceShooter& other) {
	this->difficulty = other.difficulty;
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			this->pixelGrid[i][j] = other.pixelGrid[i][j];
		}
	}
	std::cout << "\n COPY\n";
}

SpaceShooter::SpaceShooter(const char* saveFilePath) {
	std::cout << "Error loading \"" << saveFilePath << "\"\n";
	delete[] saveFilePath;
}

void SpaceShooter::updateScreen() {
	static int updatesSinceLastSpawnedEnemy;
	clearScreenPixelGrid();
	if (updatesSinceLastSpawnedEnemy >= 10) {
		spawnNewEnemy();
		updatesSinceLastSpawnedEnemy = 0;
	}
	updateProjectilePositions();
	updateEnemyPositions();
	updatePlayerPositioningOnScreen();
	updatesSinceLastSpawnedEnemy++;
}

void SpaceShooter::spawnPlayer() {
	//this->player = Player();
	//entities.push_back(player);
}

char* SpaceShooter::getPixelGrid() {
	return &(pixelGrid[0][0]);
}

Player* SpaceShooter::getPlayer() {
	return &player;
}
