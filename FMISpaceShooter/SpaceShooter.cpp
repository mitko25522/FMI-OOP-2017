#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include "SpaceShooter.h"
#include "Renderer.h"

void SpaceShooter::printHelp() {
	Renderer::clearScreen();
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
			Renderer::clearScreen();
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
	int playerPosX_inPixelGrid = player.getPosX();
	int playerPosY_inPixelGrid = player.getPosY();

	int currentPlayerIndexX = 0;
	int currentPlayerIndexY = 0;

	for (int i = playerPosY_inPixelGrid; i < playerPosY_inPixelGrid + player.getHeight(); i++) {
		for (int j = playerPosX_inPixelGrid; j < playerPosX_inPixelGrid + player.getWidth(); j++) {
			this->updatedScreen[i][j] = player.getChar(currentPlayerIndexY, currentPlayerIndexX);
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

			this->updatedScreen[projectiles_container.at(i).getPosY()][projectiles_container.at(i).getPosX()] = this->projectiles_container.at(i).getChar(0, 0);
		}

		if (!projectiles_container.at(i).isItFromPlayer()) {
			projectiles_container.at(i).moveLeft(2);

			if (projectiles_container.at(i).getPosX() <= 1) {
				projectiles_container.erase(projectiles_container.begin() + i);
			}

			this->updatedScreen[projectiles_container.at(i).getPosY()][projectiles_container.at(i).getPosX()] = this->projectiles_container.at(i).getChar(0, 0);
		}
	}


}

void SpaceShooter::clearScreenPixelGrid() {
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			updatedScreen[i][j] = ' ';
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
			this->updatedScreen[enemies_container.at(i).getPosY()][currentEnemyPosX + enemies_container.at(i).getPosX()] = enemies_container.at(i).getChar(0, currentEnemyPosX);
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
				if (bossFightIsInAction) {
					if (projectiles_container.at(projectileIndex).isInCollisionWith(boss_container.at(0))) {
						projectiles_container.erase(projectiles_container.begin() + projectileIndex);
						boss_container.at(0).reduceLives(1);
						this->player.increaseScore(10);
						return;
					}
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

void SpaceShooter::checkForCollisionBetweenPlayerAndBoss() {
	if (this->player.isInCollisionWith(boss_container.at(0))) {
		this->player.reduceLives(PLAYER_MAX_LIVES);
	}
}

void SpaceShooter::checkIfEnemySpawnRateNeedsUpdating() {
	static int previousPlayerScore;
	if (this->player.getScore() - previousPlayerScore >= 30) {
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

void SpaceShooter::generateBossProjectiles() {
	static bool trigger = false;
	static int shotsCount = 0;
	static bool shotsDelayInProgress;

	if (shotsDelayInProgress == false) {
		shotsCount++;

		if (shotsCount > 3) {
			shotsDelayInProgress = true;
		}
	}
	else if (shotsDelayInProgress == true) {
		shotsCount--;

		if (shotsCount < 0) {
			shotsDelayInProgress = false;
		}

		return;
	}

	if (trigger == false)
		for (int i = 0; i < 7; i++) {
			int currentGunPosX = this->boss_container.at(0).getGunPosX(i) + this->boss_container.at(0).getPosX();
			int currentGunPosY = this->boss_container.at(0).getGunPosY(i) + this->boss_container.at(0).getPosY();
			Projectile newProjectile(currentGunPosX, currentGunPosY, false);
			projectiles_container.push_back(newProjectile);
			trigger = true;
			if (i + 1 == 7) {
				return;
			}
		}

	if (trigger == true) {
		int currentGunPosX = this->boss_container.at(0).getGunPosX(2) + this->boss_container.at(0).getPosX();
		int currentGunPosY = this->boss_container.at(0).getGunPosY(2) + this->boss_container.at(0).getPosY();
		Projectile newProjectile(currentGunPosX, currentGunPosY, false);
		projectiles_container.push_back(newProjectile);

		int currentGunPosX2 = this->boss_container.at(0).getGunPosX(3) + this->boss_container.at(0).getPosX();
		int currentGunPosY2 = this->boss_container.at(0).getGunPosY(3) + this->boss_container.at(0).getPosY();
		Projectile newProjectile2(currentGunPosX2, currentGunPosY2, false);
		projectiles_container.push_back(newProjectile2);
		trigger = false;

		int currentGunPosX3 = this->boss_container.at(0).getGunPosX(4) + this->boss_container.at(0).getPosX();
		int currentGunPosY3 = this->boss_container.at(0).getGunPosY(4) + this->boss_container.at(0).getPosY();
		Projectile newProjectile3(currentGunPosX3, currentGunPosY3, false);
		projectiles_container.push_back(newProjectile3);
		trigger = false;
		return;
	}

}

//mess
void SpaceShooter::updateBossPosition() {
	static int updateCount;
	int bossPosX_inPixelGrid = boss_container.at(0).getPosX();
	int bossPosY_inPixelGrid = boss_container.at(0).getPosY();

	int currentBossIndexX = 0;
	int currentBossIndexY = 0;

	if (updateCount >= 10) {
		//min: ((SCREEN_WIDTH / 2) + (SCREEN_WIDTH/4))
		//max: SCREEN_WIDTH - boss_container.at(0).getWidth()
		//min + rand() % (( max + 1 ) - min)
		boss_container.at(0).changeXPosTo(((SCREEN_WIDTH / 2) + (SCREEN_WIDTH / 8)) + rand() % ((SCREEN_WIDTH - boss_container.at(0).getWidth() + 1) - ((SCREEN_WIDTH / 2) + (SCREEN_WIDTH / 8))));
		boss_container.at(0).changeYPosTo(std::rand() % (SCREEN_HEIGHT - boss_container.at(0).getHeight() + 1));

		updateCount = 0;
	}

	for (int i = bossPosY_inPixelGrid; i < bossPosY_inPixelGrid + boss_container.at(0).getHeight(); i++) {
		for (int j = bossPosX_inPixelGrid; j < bossPosX_inPixelGrid + boss_container.at(0).getWidth(); j++) {
			this->updatedScreen[i][j] = boss_container.at(0).getChar(currentBossIndexY, currentBossIndexX);
			currentBossIndexX++;
		}
		currentBossIndexX = 0;
		currentBossIndexY++;
	}

	updateCount++;
}

void SpaceShooter::checkIfBossDed() {
	if (boss_container.at(0).getRemainingLives() <= 0) {
		boss_container.erase(boss_container.begin());
		bossFightIsInAction = false;
	}
}

SpaceShooter::SpaceShooter() {
	clearScreenPixelGrid();

	noBossHasBeenSpawnedYet = true;
	bossFightIsInAction = false;
	this->gameProgressDelay = 20;
	this->difficulty = DIFFICULTY_MEDIUM;
	std::cout << "Selected medium difficulty\n";
	std::cout << "Starting new game\n";
	Sleep(2000);
}

SpaceShooter::SpaceShooter(int difficulty) {
	clearScreenPixelGrid();

	noBossHasBeenSpawnedYet = true;
	bossFightIsInAction = false;
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
	this->gameProgressDelay = other.gameProgressDelay;
	this->bossFightIsInAction = other.bossFightIsInAction;
	this->noBossHasBeenSpawnedYet = other.noBossHasBeenSpawnedYet;

	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			this->updatedScreen[i][j] = other.updatedScreen[i][j];
		}
	}
}

SpaceShooter::SpaceShooter(const char* saveFilePath) {
	Save saveGame;
	std::ifstream InFile(saveFilePath, std::ios::binary);
	InFile.seekg(0);
	InFile.read((char*)&saveGame, sizeof(saveGame));

	if (saveGame.validityCheck != VALID_SAVE) {
		std::cout << "Invalid save file.\n";
		exit(EXIT_FAILURE);
		delete[] saveFilePath;
	}

	this->difficulty = saveGame.gameDifficulty;
	this->gameProgressDelay = saveGame.gameProgressDelay;
	this->player.increaseScore(saveGame.playerScore);
	this->player.reduceLives(saveGame.playerRemainingLives);
	this->bossFightIsInAction = saveGame.bossFightIsInAction;
	this->noBossHasBeenSpawnedYet = saveGame.noBossHasBeenSpawnedYet;

	if (this->bossFightIsInAction) {
		LevelOneBoss boss(saveGame.bossRemainingLives);
		boss_container.push_back(boss);
	}

	delete[] saveFilePath;
}

void SpaceShooter::generateEnemyProjectiles() {
	static int updatesSinceLastProjectile;

	if (bossFightIsInAction) {
		if (updatesSinceLastProjectile >= gameProgressDelay / 2) {
			generateBossProjectiles();
			updatesSinceLastProjectile = 0;
		}
	}
	else {
		if (updatesSinceLastProjectile >= gameProgressDelay / 2) {
			generateProjectileFromRandomEnemy();
			updatesSinceLastProjectile = 0;
		}
	}

	updatesSinceLastProjectile++;
}

void SpaceShooter::updateScreen() {
	static int updatesSinceLastSpawnedEnemy;
	clearScreenPixelGrid();

	if (bossFightIsInAction) {
		if (updatesSinceLastSpawnedEnemy >= 25) {
			spawnNewEnemy();
			updatesSinceLastSpawnedEnemy = 0;
		}

		checkForCollisionsBetweenProjectilesAndEnemies();
		checkForCollisionsBetweenPlayerAndEnemies();
		checkForCollisionBetweenPlayerAndBoss();
		updateProjectilePositions();
		updateEnemyPositions();
		updateBossPosition();
		updatePlayerPositioningOnScreen();
		checkIfBossDed();
		updatesSinceLastSpawnedEnemy++;
		return;
	}
	else {
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
		return;
	}
}

Player* SpaceShooter::getPlayer() {
	return &player;
}

void SpaceShooter::generateSaveFileName(char name[15]) {
	size_t currentTime = time(0);

	int nameIndex = 9;
	int divisor = 1;
	for (int i = 0; i < 10; ++i) {
		name[nameIndex] = ((currentTime / divisor) % 10) + '0';
		nameIndex--;
		divisor *= 10;
	}

	nameIndex = 10;
	name[nameIndex++] = '.';
	name[nameIndex++] = 'd';
	name[nameIndex++] = 'a';
	name[nameIndex++] = 't';
	name[nameIndex] = '\0';
}

void SpaceShooter::saveGameProgress() {
	char fileName[15];
	generateSaveFileName(fileName);

	Save save;
	save.validityCheck = VALID_SAVE;
	save.bossFightIsInAction = this->bossFightIsInAction;
	save.noBossHasBeenSpawnedYet = this->noBossHasBeenSpawnedYet;
	save.gameDifficulty = this->difficulty;
	save.gameProgressDelay = this->gameProgressDelay;
	save.playerScore = this->player.getScore();
	save.playerRemainingLives = this->player.getRemainingLives();

	if (bossFightIsInAction) {
		save.bossRemainingLives = boss_container.at(0).getRemainingLives();
	}

	std::ofstream OutFile(fileName, std::ios::binary);
	OutFile.write((char*)&save, sizeof(save));

	Renderer::printSavingGame();
	OutFile.close();
}

void SpaceShooter::startBossFight() {
	try {
		LevelOneBoss boss(100);
		boss_container.push_back(boss);

		for (int i = 0; i < enemies_container.size(); i++) {
			enemies_container.erase(enemies_container.begin() + i);
		}

		for (int i = 0; i < projectiles_container.size(); i++) {
			projectiles_container.erase(projectiles_container.begin() + i);
		}

		bossFightIsInAction = true;
		noBossHasBeenSpawnedYet = false;
	}
	catch (std::exception& e) {
		std::cout << e.what();
		system("pause");
	}
}