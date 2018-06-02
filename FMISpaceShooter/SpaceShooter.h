#pragma once

#define SCREEN_WIDTH 60
#define SCREEN_HEIGHT 20

#define DIFFICULTY_EASY 65
#define DIFFICULTY_MEDIUM 32
#define DIFFICULTY_INTERMEDIATE 17

//delta_ticks = 17 hard
//delta_ticks = 32 medium
//delta_ticks = 65 easy

class SpaceShooter {
private:
	int difficulty;
	char pixelGrid[SCREEN_WIDTH][SCREEN_HEIGHT];
public:
	SpaceShooter();
	SpaceShooter(int);
	SpaceShooter(const char*);
	static void printHelp();
};