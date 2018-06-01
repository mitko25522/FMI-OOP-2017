#include "SpaceShooter.h"
#include <iostream>
#include <windows.h>

char * SpaceShooter::getSavePath()
{
	std::cout << "Please enter game save file path> ";
	char* path = new char[1024];
	std::cin.getline(path, 1024);
	return path;
}

void SpaceShooter::printHelp() {

}

SpaceShooter::SpaceShooter() {
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			pixelGrid[SCREEN_HEIGHT][SCREEN_WIDTH] = '*';
		}
	}
	std::cout << "Starting new game\n";
	Sleep(2000);
}

SpaceShooter::SpaceShooter(const char* saveFilePath) {
	std::cout << "Error loading \"" << saveFilePath << "\"\n";
	delete[] saveFilePath;
}
