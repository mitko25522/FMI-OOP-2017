#pragma once
#include "Entity.h"

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
	int getGunPosX();
	int getGunPosY();
	Player();
	Player(const Player&);
};
