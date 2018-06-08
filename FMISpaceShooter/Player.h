#pragma once
#include "Entity.h"

//		[\ 
//		[ ==>
//		[/ 

class Player : public Entity {
	int remaningLives;
	int score;
public:
	Player();
	Player(const Player&);
};