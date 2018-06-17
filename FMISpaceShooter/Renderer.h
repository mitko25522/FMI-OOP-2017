#pragma once
#include <iostream>
#include "SpaceShooter.h"

class Renderer {
private:
	static void printTextFmi();
	static void printTextSpace();
	static void printTextShooter();
	static void printTextFmiWithRocket();
	static void printTextSpaceWithRocket();
	static void printTextShooterWithRocket();
	static void printMainMenu();
	static void printEmptyRows(int);
	static void printAnimation();
	static void printDifficultyOptions();
public:
	static void printGameOverScreen(SpaceShooter*);
	static void printStaticStartScreen();
	static void renderStartScreen();
	static void renderDifficultySelectionScreen();
	static void renderGameScreen(SpaceShooter*);
	static void printSavingGame();
	static void clearScreen();
};

