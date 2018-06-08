#include "SpaceShooter.h"
#include <iostream>
#include <windows.h>
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

void SpaceShooter::updatePlayer() {
	int playerPrevPosX = player.getPosX();
	int playerPrevPosY = player.getPosY();

	int currentPlayerIndexX = 0;
	int currentPlayerIndexY = 0;

	for (int i = playerPrevPosY; i < playerPrevPosY + player.getHeight(); i++) {
		for (int j = playerPrevPosX; j < playerPrevPosX + player.getWidth(); j++) {
			this->pixelGrid[i][j] = player.getSprite()[currentPlayerIndexY][currentPlayerIndexX];
			currentPlayerIndexX++;
		}
		currentPlayerIndexY++;
	}
}

SpaceShooter::SpaceShooter() {
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			pixelGrid[i][j] = ' ';
		}
	}

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
	updatePlayer();
}

void SpaceShooter::spawnPlayer() {
	//this->player = Player();
	//entities.push_back(player);
}

char* SpaceShooter::getPixelGrid() {
	return &(pixelGrid[0][0]);
}
