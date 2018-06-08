#pragma once
#include "Entity.h"
#include "SpaceShooter.h"

class Projectile : public Entity {
	bool isByPlayer;
	Projectile();
public:
	Projectile(int x, int y, bool isByPlayer);
	Projectile(const Projectile&);
};