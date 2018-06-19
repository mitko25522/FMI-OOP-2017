#pragma once
#include <vector>
#include "Player.h"
#include "Entity.h"
#include "Projectile.h"
#include "Enemy.h"
#include "LevelOneBoss.h"

#define SCREEN_WIDTH 60
#define SCREEN_HEIGHT 20

#define DIFFICULTY_EASY 65
#define DIFFICULTY_MEDIUM 32
#define DIFFICULTY_INTERMEDIATE 26

#define PLAYER_MAX_LIVES 3
#define BOSS_SPAWN_SCORE 300

//delta_ticks = 17 hard
//delta_ticks = 32 medium
//delta_ticks = 65 easy

class LevelOneBoss;

class SpaceShooter {
private:
	Player player;
	int difficulty;
	int gameProgressDelay;
	void updatePlayerPositioningOnScreen();
	void updateProjectilePositions();
	void updateEnemyPositions();
	void clearScreenPixelGrid();
	void spawnNewEnemy();
	void checkForCollisionsBetweenProjectilesAndEnemies();
	void checkForCollisionsBetweenPlayerAndEnemies();
	void checkForCollisionBetweenPlayerAndBoss();
	void checkIfEnemySpawnRateNeedsUpdating();
	void reduceGameProgressDelay();
	void generateProjectileFromRandomEnemy();
	void generateBossProjectiles();
	void updateBossPosition();
	void checkIfBossDed();
public:
	bool bossFightIsInAction;
	bool noBossHasBeenSpawnedYet;
	std::vector<Projectile> projectiles_container;
	std::vector<Enemy> enemies_container;
	std::vector<LevelOneBoss> boss_container;
	SpaceShooter();
	SpaceShooter(int);
	SpaceShooter(const SpaceShooter&);
	SpaceShooter(const char*);
	void generateEnemyProjectiles();
	void updateScreen();
	char updatedScreen[SCREEN_HEIGHT][SCREEN_WIDTH];
	char renderedScreen[SCREEN_HEIGHT][SCREEN_WIDTH];
	Player* getPlayer();
	static void printHelp();
	int getDifficulty();
	void generateSaveFileName(char name[15]);
	void saveGameProgress();
	void startBossFight();
};

//save file validity check value 1337
#define VALID_SAVE 1337

struct Save {
	int validityCheck;
	int gameDifficulty;
	int gameProgressDelay;
	int playerScore;
	int playerRemainingLives;
	int bossRemainingLives;
	bool bossFightIsInAction;
	bool noBossHasBeenSpawnedYet;
};