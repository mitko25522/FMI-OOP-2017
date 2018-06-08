#pragma once
#include "SpaceShooter.h"
#include "Entity.h"
#include "Projectile.h"
//		[\ 
//		[ ==>
//		[/ 

class Player : public Entity {
	int remaningLives;
	int score;
	int gunPosX;
	int gunPosY;
public:
	void moveLeft();
	void moveRight();
	int getRemaningLives();
	int getScore();
	//void shootProjectile(SpaceShooter&);
	Player();
	Player(const Player&);
};