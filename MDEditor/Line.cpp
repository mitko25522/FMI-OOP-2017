#include "Line.h"

Line::Line() {
	letter = new char[1025];
	this->letter[0] = '\0';
}

Line::~Line() {
	delete[] letter;
}