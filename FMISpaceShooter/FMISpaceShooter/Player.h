#pragma once
#include "Entity.h"

//		[\ 
//		[ ==>
//		[/

class Player : public Entity {
private:
	int remainingLives;
	int score;
	int gunPosX;
	int gunPosY;
public:
	void increaseScore(int);
	void reduceLives(int);
	int getScore();
	int getRemainingLives();
	int getGunPosX();
	int getGunPosY();
	Player();
	Player(const Player&);
};
