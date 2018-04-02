#include "Text.h"
#define NULL 0

Text::Text() {
	this->numberOfLines = 0;
	line = NULL;
}

Text::Text(unsigned) {
	this->numberOfLines;
	line = new Line[numberOfLines];
}

Text::~Text() {
	delete[] line;
}