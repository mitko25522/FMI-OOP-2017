#pragma once
#include "Entity.h"
#include "Enemy.h"

class Projectile : public Entity {
	bool isFromPlayer;
	Projectile();
public:
	Projectile(int startPosX, int startPosY, bool isFromPlayer);
	Projectile(const Projectile&);
	Projectile(const Enemy&);
	~Projectile();
	bool isItFromPlayer();
};