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
	int getGunPosX();
	int getGunPosY();
	Player();
	Player(const Player&);
};
