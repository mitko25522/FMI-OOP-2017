#include "Projectile.h"

Projectile::Projectile(int startPosX, int startPosY, bool isFromPlayer) {
	this->isFromPlayer = isFromPlayer;
	this->xPos = startPosX;
	this->yPos = startPosY;
}

Projectile::Projectile(const Projectile& other) {
	this->isFromPlayer = other.isFromPlayer;
}
