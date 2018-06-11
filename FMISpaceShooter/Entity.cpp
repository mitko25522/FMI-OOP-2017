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

bool Entity::isInCollisionWith(const Entity& other) {
	return ((other.yPos >= this->yPos) && (other.yPos < this->yPos + this->height)) &&
	       ((other.xPos >= this->xPos) && (other.xPos < this->xPos + this->width));
}

int Entity::getPosX() const {
	return this->xPos;
}

int Entity::getPosY() const {
	return this->yPos;
}

int Entity::getWidth() const {
	return this->width;
}

int Entity::getHeight() const {
	return this->height;
}

void Entity::moveUp(int offset) {
	if (yPos > offset) {
		yPos -= offset;
		return;
	}

	while (offset > 0) {
		if (yPos > 0) {
			yPos--;
		}
		offset--;
	}
}

void Entity::moveDown(int offset) {
	if (yPos + height < SCREEN_HEIGHT - offset) {
		yPos += offset;
		return;
	}

	while (offset > 0) {
		if (yPos + height < SCREEN_HEIGHT) {
			yPos++;
		}
		offset--;
	}
}

void Entity::moveLeft(int offset) {
	if (xPos > offset) {
		xPos -= offset;
		return;
	}

	while (offset > 0) {
		if (xPos > 0) {
			xPos--;
		}
		offset--;
	}
}

void Entity::moveRight(int offset) {
	if (xPos + width < SCREEN_WIDTH - offset) {
		xPos += offset;
		return;
	}

	while (offset > 0) {
		if (xPos + width < SCREEN_WIDTH) {
			xPos++;
		}
		offset--;
	}
}

char** Entity::getSprite() {
	return this->sprite;
}

char Entity::getChar(int y, int x) {
	return *(&sprite[0][0] + y * width + x);
}

Entity::Entity(int xPos, int yPos, int width, int height) {
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
	/*if (sprite != nullptr) {
		for (int i = 0; i < height; i++) {
			delete[] sprite[i];
		}
		delete[] sprite;
	}*/
}