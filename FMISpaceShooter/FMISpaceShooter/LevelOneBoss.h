#pragma once
#include "SpaceShooter.h"
#include "Entity.h"

//		    O~~~~     
//		  O~~    O~~  
//		O~~        O~~
//		O~~        O~~
//		O~~        O~~
//		  O~~     O~~ 
//		    O~~~~     

class LevelOneBoss : public Entity {
private:
	int remainingLives;
	int gunPosX[7];
	int gunPosY[7];
public:
	LevelOneBoss(int);
	LevelOneBoss(const LevelOneBoss& other);
	int getGunPosX(int index);
	int getGunPosY(int index);
	void reduceLives(int);
	int getRemainingLives();
};