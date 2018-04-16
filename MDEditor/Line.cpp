#include "Line.h"

Line::Line() {
	letter = new char[1025];
	this->letter[0] = '\0';
}

Line::~Line() {
	delete[] letter;
}

void Line::makeHeading() {
	shiftRightOnce(0);
	shiftRightOnce(0);
	this->letter[0] = '#';
	this->letter[1] = ' ';
}

//possibly not working
void Line::shiftRightOnce(int from) {
	int index = 0;
	while (this->letter[index] != '\0') {
		index++;
	}
	for (int i = index + 1; i > from; i--) {
		this->letter[i] = this->letter[index];
		index--;
	}
}

//not working
void Line::italicize(int from, int to) {
	from = findWordFirstLetterIndex(from);
	to = findWordLastLetterIndex(to);
	shiftRightOnce(findWordFirstLetterIndex(from));
	this->letter[from] = '*';
	shiftRightOnce(findWordLastLetterIndex(to));
	this->letter[to] = '*';
}

//not working
int Line::findWordFirstLetterIndex(int wordNumber) {
	int spacesCounted = 1;
	for (int i = 0; spacesCounted <= wordNumber; i++) {
		if (this->letter[i] == ' ') {
			spacesCounted++;
		}
		if (spacesCounted == wordNumber) {
			return i;
		}
	}
}

//not working
int Line::findWordLastLetterIndex(int wordNumber) {
	int spacesCounted = 1;
	for (int i = 0; spacesCounted <= wordNumber; i++) {
		if (this->letter[i] == ' ') {
			spacesCounted++;
		}
		if (spacesCounted == wordNumber) {
			for (int j = i; this->letter[i] != ' '; j++) {
				if (this->letter[i] == ' ') {
					return j;
				}
			}
		}
	}
}