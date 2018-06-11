#include <iostream>
#include <windows.h>
#include "SpaceShooter.h"
#include "Renderer.h"

void SpaceShooter::printHelp() {
	system("cls");
	std::cout << "Welcome to FMISpaceShooter\n";
	std::cout << "Here you will encounter enemies bla bla bla..\n";
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
			projectiles_container.at(i).moveRight(3);

			if (projectiles_container.at(i).getPosX() >= SCREEN_WIDTH - 1) {
				projectiles_container.erase(projectiles_container.begin() + i);
				continue;
			}

			this->pixelGrid[projectiles_container.at(i).getPosY()][projectiles_container.at(i).getPosX()] = this->projectiles_container.at(i).getChar(0, 0);
		}

		if (!projectiles_container.at(i).isItFromPlayer()) {
			projectiles_container.at(i).moveLeft(2);

			if (projectiles_container.at(i).getPosX() <= 1) {
				projectiles_container.erase(projectiles_container.begin() + i);
			}

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
	enemies_container.push_back(newEnemy);
}

void SpaceShooter::checkForCollisionsBetweenProjectilesAndEnemies() {
	for (int projectileIndex = 0; projectileIndex < projectiles_container.size(); ++projectileIndex) {
		for (int enemyIndex = 0; enemyIndex < enemies_container.size(); ++enemyIndex) {
			if (projectiles_container.at(projectileIndex).isItFromPlayer()) {
				if (projectiles_container.at(projectileIndex).isInCollisionWith(enemies_container.at(enemyIndex))) {
					projectiles_container.erase(projectiles_container.begin() + projectileIndex);
					enemies_container.erase(enemies_container.begin() + enemyIndex);
					this->player.increaseScore(10);
					return;
				}
			}
			if (!projectiles_container.at(projectileIndex).isItFromPlayer()) {
				if (projectiles_container.at(projectileIndex).isInCollisionWith(player)) {
					projectiles_container.erase(projectiles_container.begin() + projectileIndex);
					this->player.reduceLives(1);
					return;
				}
			}
		}
	}
}

void SpaceShooter::checkForCollisionsBetweenPlayerAndEnemies() {
	for (int i = 0; i < this->enemies_container.size(); i++) {
		if (this->player.isInCollisionWith(enemies_container.at(i))) {
			player.reduceLives(1);
			enemies_container.erase(enemies_container.begin() + i);
		}
	}
}

void SpaceShooter::checkIfEnemySpawnRateNeedsUpdating() {
	static int previousPlayerScore;
	if (this->player.getScore() - previousPlayerScore >= 50) {
		reduceGameProgressDelay();
		previousPlayerScore = this->player.getScore();
	}
}

void SpaceShooter::reduceGameProgressDelay() {
	if (this->gameProgressDelay > 0) {
		gameProgressDelay--;
	}
}

void SpaceShooter::generateProjectileFromRandomEnemy() {
	int enemiesCount = enemies_container.size();

	if (enemiesCount <= 0) {
		return;
	}

	int selectedEnemyIndex = rand() % enemiesCount;
	int enemyGunPosX = enemies_container.at(selectedEnemyIndex).getGunPosX() + enemies_container.at(selectedEnemyIndex).getPosX();
	int enemyGunPosY = enemies_container.at(selectedEnemyIndex).getGunPosY();
	Projectile newProjectile(enemyGunPosX, enemyGunPosY, false);
	projectiles_container.push_back(newProjectile);
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

	this->gameProgressDelay = 20;
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

void SpaceShooter::generateEnemyProjectiles() {
	static int updateSinceLastProjectile;

	if (updateSinceLastProjectile >= gameProgressDelay / 2) {
		generateProjectileFromRandomEnemy();
		updateSinceLastProjectile = 0;
	}

	updateSinceLastProjectile++;
}

void SpaceShooter::updateScreen() {
	static int updatesSinceLastSpawnedEnemy;
	clearScreenPixelGrid();

	if (updatesSinceLastSpawnedEnemy >= gameProgressDelay) {
		spawnNewEnemy();
		updatesSinceLastSpawnedEnemy = 0;
	}

	checkIfEnemySpawnRateNeedsUpdating();
	checkForCollisionsBetweenProjectilesAndEnemies();
	checkForCollisionsBetweenPlayerAndEnemies();
	updateProjectilePositions();
	updateEnemyPositions();
	updatePlayerPositioningOnScreen();
	updatesSinceLastSpawnedEnemy++;
}

char* SpaceShooter::getPixelGrid() {
	return &(pixelGrid[0][0]);
}

Player* SpaceShooter::getPlayer() {
	return &player;
}
