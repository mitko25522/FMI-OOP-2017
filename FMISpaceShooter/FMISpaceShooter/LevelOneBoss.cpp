#include "LevelOneBoss.h"
#include "SpaceShooter.h"

//13x7

LevelOneBoss::LevelOneBoss(int remainingLives) {
	this->remainingLives = remainingLives;
	this->width = 14;
	this->height = 7;
	this->xPos = SCREEN_WIDTH - 1 - this->width;
	this->yPos = SCREEN_HEIGHT / 2;

	this->gunPosX[0] = 4;
	this->gunPosX[1] = 2;
	this->gunPosX[2] = 0;
	this->gunPosX[3] = 0;
	this->gunPosX[4] = 0;
	this->gunPosX[5] = 2;
	this->gunPosX[6] = 4;

	for (int i = 0; i < height; i++) {
		this->gunPosY[i] = i;
	}

	this->sprite = new char*[height];
	for (int i = 0; i < this->height; i++) {
		this->sprite[i] = new char[this->width];
	}

	this->sprite[0][0] = ' ';
	this->sprite[0][1] = ' ';
	this->sprite[0][2] = ' ';
	this->sprite[0][3] = ' ';
	this->sprite[0][4] = 'O';
	this->sprite[0][5] = '~';
	this->sprite[0][6] = '~';
	this->sprite[0][7] = '~';
	this->sprite[0][8] = '~';
	this->sprite[0][9] = ' ';
	this->sprite[0][10] = ' ';
	this->sprite[0][11] = ' ';
	this->sprite[0][12] = ' ';
	this->sprite[0][13] = ' ';

	this->sprite[0][14] = ' ';
	this->sprite[0][15] = ' ';
	this->sprite[0][16] = 'O';
	this->sprite[0][17] = '~';
	this->sprite[0][18] = '~';
	this->sprite[0][19] = ' ';
	this->sprite[0][20] = ' ';
	this->sprite[0][21] = ' ';
	this->sprite[0][22] = ' ';
	this->sprite[0][23] = 'O';
	this->sprite[0][24] = '~';
	this->sprite[0][25] = '~';
	this->sprite[0][26] = ' ';
	this->sprite[0][27] = ' ';

	this->sprite[0][28] = 'O';
	this->sprite[0][29] = '~';
	this->sprite[0][30] = '~';
	this->sprite[0][31] = ' ';
	this->sprite[0][32] = ' ';
	this->sprite[0][33] = ' ';
	this->sprite[0][34] = ' ';
	this->sprite[0][35] = ' ';
	this->sprite[0][36] = ' ';
	this->sprite[0][37] = ' ';
	this->sprite[0][38] = ' ';
	this->sprite[0][39] = 'O';
	this->sprite[0][40] = '~';
	this->sprite[0][41] = '~';

	this->sprite[0][42] = 'O';
	this->sprite[0][43] = '~';
	this->sprite[0][44] = '~';
	this->sprite[0][45] = ' ';
	this->sprite[0][46] = ' ';
	this->sprite[0][47] = ' ';
	this->sprite[0][48] = ' ';
	this->sprite[0][49] = ' ';
	this->sprite[0][50] = ' ';
	this->sprite[0][51] = ' ';
	this->sprite[0][52] = ' ';
	this->sprite[0][53] = 'O';
	this->sprite[0][54] = '~';
	this->sprite[0][55] = '~';

	this->sprite[0][56] = 'O';
	this->sprite[0][57] = '~';
	this->sprite[0][58] = '~';
	this->sprite[0][59] = ' ';
	this->sprite[0][60] = ' ';
	this->sprite[0][61] = ' ';
	this->sprite[0][62] = ' ';
	this->sprite[0][63] = ' ';
	this->sprite[0][64] = ' ';
	this->sprite[0][65] = ' ';
	this->sprite[0][66] = ' ';
	this->sprite[0][67] = 'O';
	this->sprite[0][68] = '~';
	this->sprite[0][69] = '~';

	this->sprite[0][70] = ' ';
	this->sprite[0][71] = ' ';
	this->sprite[0][72] = 'O';
	this->sprite[0][73] = '~';
	this->sprite[0][74] = '~';
	this->sprite[0][75] = ' ';
	this->sprite[0][76] = ' ';
	this->sprite[0][77] = ' ';
	this->sprite[0][78] = ' ';
	this->sprite[0][79] = ' ';
	this->sprite[0][80] = 'O';
	this->sprite[0][81] = '~';
	this->sprite[0][82] = '~';
	this->sprite[0][83] = ' ';

	this->sprite[0][84] = ' ';
	this->sprite[0][85] = ' ';
	this->sprite[0][86] = ' ';
	this->sprite[0][87] = ' ';
	this->sprite[0][88] = 'O';
	this->sprite[0][89] = '~';
	this->sprite[0][90] = '~';
	this->sprite[0][91] = '~';
	this->sprite[0][92] = '~';
	this->sprite[0][93] = ' ';
	this->sprite[0][94] = ' ';
	this->sprite[0][95] = ' ';
	this->sprite[0][96] = ' ';
	this->sprite[0][97] = ' ';


}

LevelOneBoss::LevelOneBoss(const LevelOneBoss& other) {
	this->remainingLives = other.remainingLives;
	this->width = other.width;
	this->height = other.height;
	this->yPos = other.yPos;
	this->xPos = other.xPos;

	this->sprite = new char*[height];
	for (int i = 0; i < this->height; i++) {
		this->sprite[i] = new char[20];
	}

	for (int i = 0; i < 98; i++) {
		this->sprite[0][i] = other.sprite[0][i];
	}

	for (int i = 0; i < 7; i++) {
		this->gunPosX[i] = other.gunPosX[i];
		this->gunPosY[i] = other.gunPosY[i];
	}
}

int LevelOneBoss::getGunPosX(int index) {
	return this->gunPosX[index];
}

int LevelOneBoss::getGunPosY(int index) {
	return this->gunPosY[index];
}

void LevelOneBoss::reduceLives(int value) {
	this->remainingLives -= value;
}

int LevelOneBoss::getRemainingLives() {
	return remainingLives;
}
