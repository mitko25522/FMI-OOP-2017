#include "Projectile.h"

Projectile::Projectile(int startPosX, int startPosY, bool isFromPlayer) {
	this->isFromPlayer = isFromPlayer;
	this->xPos = startPosX;
	this->yPos = startPosY;
	this->width = 1;
	this->height = 1;
	this->sprite = new char*[1];
	sprite[0] = new char[1];
	sprite[0][0] = '-';
}

Projectile::Projectile(const Projectile& other) {
	this->isFromPlayer = other.isFromPlayer;
	this->xPos = other.xPos;
	this->yPos = other.yPos;
	this->width = other.width;
	this->height = other.height;
	this->sprite = new char*[1];
	sprite[0] = new char[1];
	sprite[0][0] = other.sprite[0][0];
}

bool Projectile::isItFromPlayer() {
	return isFromPlayer;
}
