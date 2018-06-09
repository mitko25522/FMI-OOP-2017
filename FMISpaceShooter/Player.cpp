#include "Player.h"
#include "SpaceShooter.h"

Player::Player() : Entity(0, SCREEN_HEIGHT / 2, 5, 3) {
	this->remaningLives = 3;
	this->score = 0;
	this->gunPosX = 5;
	this->gunPosY = 1;
	sprite[0][0] = '[';
	sprite[0][1] = '\\';
	sprite[0][2] = ' ';
	sprite[0][3] = ' ';
	sprite[0][4] = ' ';	
	sprite[0][5] = '[';
	sprite[0][6] = ' ';
	sprite[0][7] = '=';
	sprite[0][8] = '=';
	sprite[0][9] = '>';
	sprite[0][10] = '[';
	sprite[0][11] = '/';
	sprite[0][12] = ' ';
	sprite[0][13] = ' ';
	sprite[0][14] = ' ';
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

//Player moveLeft overrides Entity moveLeft to move twice as fast
void Player::moveLeft() {
	if (xPos > 1) {
		--xPos;
		--xPos;
	}
	else if (xPos > 0) {
		--xPos;
	}
}

//Player moveRight overrides Entity moveRight to move twice as fast
void Player::moveRight() {
	if (xPos + width < SCREEN_WIDTH - 1) {
		xPos++;
		xPos++;
	}
	else if (xPos + width < SCREEN_WIDTH) {
		xPos++;
	}
}

int Player::getGunPosX() {
	return this->gunPosX;
}

int Player::getGunPosY() {
	return this->gunPosY;
}
