#pragma once
#include "Entity.h"

class Projectile : public Entity {
	bool isFromPlayer;
	Projectile();
public:
	Projectile(int startPosX, int startPosY, bool isFromPlayer);
	Projectile(const Projectile&);
	~Projectile();
	bool isItFromPlayer();
};