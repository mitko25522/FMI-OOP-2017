#pragma once
#include <iostream>

#define SCREEN_HEIGTH 20
#define SCREEN_WIDTH 60


class Renderer {
private:
	static void printTextFmi();
	static void printTextSpace();
	static void printTextShooter();
	static void printGameOptions();
	static void printEmptyRows(int);
	static void printAnimation();
	static void printStaticStartScreen();
public:
	static void renderStartScreen();
	Renderer();
	~Renderer();
};

