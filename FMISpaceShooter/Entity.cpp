#include <iostream>
#include "Entity.h"
#include "SpaceShooter.h"

Entity::Entity() {
	this->xPos = 0;
	this->yPos = 0;
	this->width = 0;
	this->height = 0;
	sprite = nullptr;
}

int Entity::getPosX() {
	return this->xPos;
}

int Entity::getPosY() {
	return this->yPos;
}

int Entity::getWidth() {
	return this->width;
}

int Entity::getHeight() {
	return this->height;
}

void Entity::moveUp() {
	if (yPos > 0) {
		--yPos;
	}
}

void Entity::moveDown() {
	if (yPos + height < SCREEN_HEIGHT) {
		++yPos;
	}
}

void Entity::moveLeft() {
	if (xPos > 0) {
		--xPos;
	}
}

void Entity::moveRight() {
	if (xPos + width < SCREEN_WIDTH) {
		++xPos;
	}
}

char** Entity::getSprite() {
	return this->sprite;
}

char Entity::getChar(int y, int x) {
	return *(&sprite[0][0] + y * width + x);
}

Entity::Entity(int xPos, int yPos, int width, int height) {
	std::cout << "Entity(int, int, int, int) called\n";
	this->xPos = xPos;
	this->yPos = yPos;
	this->width = width;
	this->height = height;

	this->sprite = new char*[height];
	for (int i = 0; i < height; i++) {
		sprite[i] = new char[width];
	}

	for (int i = 0; i < height; i++) {
		sprite[i][0] = '\0';
	}
}

Entity::Entity(const Entity& other) {
	this->xPos = other.xPos;
	this->yPos = other.yPos;
	this->width = other.width;
	this->height = other.height;

	this->sprite = new char*[height];
	for (int i = 0; i < height; i++) {
		this->sprite[i] = new char[width];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			this->sprite[i][j] = other.sprite[i][j];
		}
	}
}

Entity::~Entity() {
	for (int i = 0; i < height; i++) {
		delete[] sprite[i];
	}
	delete[] sprite;
}