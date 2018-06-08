#include "Projectile.h"

Projectile::Projectile(int x, int y, bool isByPlayer) : Entity(x, y, 1, 1) {
	this->isByPlayer = isByPlayer;
	sprite[0][0] = '-';
}

Projectile::Projectile(const Projectile& other) {
	this->isByPlayer = other.isByPlayer;
}
