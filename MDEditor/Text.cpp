#include "Text.h"
#include <iostream>
#include <string>
#include <fstream>

#define NULL 0

Text::Text() {
	this->numberOfLines = 0;
	line = NULL;
}

void Text::setMemory(unsigned numberOfLines) {
	this->numberOfLines = numberOfLines;
	line = new Line[this->numberOfLines];
}

void Text::copyLines(char* fileDirectory, unsigned lineCount) {
	std::ifstream inputFile(fileDirectory);
	int i = 0;
	while (inputFile.getline(line[i].getLetterPointer(), 1025)) {
		i++;
		if (i >= lineCount) {
			break;
		}
	}
	inputFile.close();
}

unsigned Text::getNumberOfLines() {
	return this->numberOfLines;
}

Text::~Text() {
	delete[] line;
}