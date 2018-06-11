#include "Enemy.h"
#include "SpaceShooter.h"

Enemy::Enemy() {
	this->remainingLives = 1;
	this->width = 6;
	this->height = 1;
	this->yPos = 0;
	this->xPos = SCREEN_WIDTH - 1 - this->width;
	this->sprite = new char*[height];
	this->sprite[0] = new char[width];

	this->sprite[0][0] = '<';
	this->sprite[0][1] = '(';
	this->sprite[0][2] = '~';
	this->sprite[0][3] = '~';
	this->sprite[0][4] = '~';
	this->sprite[0][5] = ')';
	this->gunPosX = -1;
	this->gunPosY = yPos;
}

Enemy::Enemy(int startPosY) {
	this->remainingLives = 1;
	this->width = 6;
	this->height = 1;
	this->yPos = startPosY;
	this->xPos = SCREEN_WIDTH - 1 - this->width;
	this->sprite = new char*[height];
	this->sprite[0] = new char[width];

	this->sprite[0][0] = '<';
	this->sprite[0][1] = '(';
	this->sprite[0][2] = '~';
	this->sprite[0][3] = '~';
	this->sprite[0][4] = '~';
	this->sprite[0][5] = ')';
	this->gunPosX = -1;
	this->gunPosY = yPos;
}

Enemy::Enemy(const Enemy& other) {
	this->width = other.width;
	this->height = other.height;
	this->yPos = other.yPos;
	this->xPos = other.xPos;
	this->sprite = new char*[height];
	this->sprite[0] = new char[width];

	for (int i = 0; i < width; i++) {
		this->sprite[0][i] = other.sprite[0][i];
	}

	this->remainingLives = other.remainingLives;
	this->gunPosX = other.gunPosX;
	this->gunPosY = other.gunPosY;
}

int Enemy::getGunPosX() {
	return gunPosX;
}

int Enemy::getGunPosY() {
	return gunPosY;
}

bool Enemy::isInCollisionWith(const Enemy& other) {
	return (this->yPos == other.yPos) && ((other.xPos >= this->xPos) && (other.xPos <= this->xPos + this->width));
}
