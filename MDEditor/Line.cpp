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

void Line::italicize(int from, int to) {
	from = findWordFirstLetterIndex(from);
	to = findWordLastLetterIndex(to);
	//implement
}

int Line::findWordFirstLetterIndex(int wordNumber) {
	//implement
}

int Line::findWordLastLetterIndex(int wordNumber) {
	//implement
}