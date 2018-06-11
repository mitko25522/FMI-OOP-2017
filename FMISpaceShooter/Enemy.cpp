#include "Enemy.h"
#include "SpaceShooter.h"

Enemy::Enemy() {
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
}

Enemy::Enemy(int startPosY) {
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
}
