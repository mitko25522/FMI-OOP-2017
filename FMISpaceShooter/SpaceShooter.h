#pragma once

#define SCREEN_WIDTH 60
#define SCREEN_HEIGHT 20

class SpaceShooter {
private:
	char pixelGrid[SCREEN_WIDTH][SCREEN_HEIGHT];
public:
	SpaceShooter();
	SpaceShooter(const char*);
	static char* getSavePath();
	static void printHelp();
};