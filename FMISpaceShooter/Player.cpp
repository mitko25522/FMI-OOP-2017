#include "Player.h"
#include "SpaceShooter.h"

Player::Player() : Entity(0, SCREEN_HEIGHT / 2, 5, 3) {
	this->remaningLives = 3;
	this->score = 0;
	sprite[0][0] = '[';
	sprite[0][1] = '\\';
	sprite[0][2] = ' ';
	sprite[0][3] = ' ';
	sprite[0][4] = ' ';	

	sprite[1][0] = '[';
	sprite[1][1] = ' ';
	sprite[1][2] = '=';
	sprite[1][3] = '=';
	sprite[1][4] = '>';	
	
	sprite[2][0] = '[';
	sprite[2][1] = '/';
	sprite[2][2] = ' ';
	sprite[2][3] = ' ';
	sprite[2][4] = ' ';
}

Player::Player(const Player & other) {
	this->remaningLives = other.remaningLives;
	this->score = other.score;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			this->sprite[i][j] = other.sprite[i][j];
		}
	}
}
