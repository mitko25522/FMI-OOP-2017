#include "Player.h"
#include "SpaceShooter.h"

Player::Player() : Entity(0, SCREEN_HEIGHT / 2, 5, 3) {
	this->remainingLives = PLAYER_MAX_LIVES;
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
	this->remainingLives = other.remainingLives;
	this->score = other.score;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			this->sprite[i][j] = other.sprite[i][j];
		}
	}
}

void Player::increaseScore(int increase) {
	this->score += increase;
}

void Player::reduceLives(int) {
	this->remainingLives--;
}

int Player::getScore() {
	return this->score;
}

int Player::getRemainingLives()
{
	return this->remainingLives;
}

int Player::getGunPosX() {
	return this->gunPosX;
}

int Player::getGunPosY() {
	return this->gunPosY;
}
