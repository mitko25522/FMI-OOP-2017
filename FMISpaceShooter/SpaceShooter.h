#pragma once
#include <vector>
#include "SpaceShooter.h"
#include "Player.h"
#include "Entity.h"
#include "Projectile.h"
#include "Enemy.h"

#define SCREEN_WIDTH 60
#define SCREEN_HEIGHT 20

#define DIFFICULTY_EASY 65
#define DIFFICULTY_MEDIUM 32
#define DIFFICULTY_INTERMEDIATE 16

//delta_ticks = 17 hard
//delta_ticks = 32 medium
//delta_ticks = 65 easy

class SpaceShooter {
private:
	Player player;
	int difficulty;
	char pixelGrid[SCREEN_HEIGHT][SCREEN_WIDTH];
	void updatePlayerPositioningOnScreen();
	void updateProjectilePositions();
	void updateEnemyPositions();
	void clearScreenPixelGrid();
	void spawnNewEnemy();
public:
	std::vector<Projectile> projectiles_container;
	std::vector<Enemy> enemies_container;
	SpaceShooter();
	SpaceShooter(int);
	SpaceShooter(const SpaceShooter&);
	SpaceShooter(const char*);
	void updateScreen();
	void spawnPlayer();
	char* getPixelGrid();
	Player* getPlayer();
	static void printHelp();
	int getDifficulty();
};