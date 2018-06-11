#pragma once
#include "Entity.h"

//<(~~~)

class Enemy : public Entity {
	int remainingLives;
	int gunPosX;
	int gunPosY;
public:
	Enemy();
	Enemy(int startPosY);
	Enemy(const Enemy&);
	int getGunPosX();
	int getGunPosY();
	bool isInCollisionWith(const Enemy&);
};