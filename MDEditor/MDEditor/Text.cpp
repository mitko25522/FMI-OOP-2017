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

unsigned Text::getNumberOfLines() const {
	return this->numberOfLines;
}

Text::~Text() {
	delete[] line;
}

Text::Text(const Text& text) {
	this->numberOfLines = text.getNumberOfLines();
	line = new Line[this->numberOfLines];
	for (int i = 0; i < this->numberOfLines; i++) {
		strcpy_s(this->line[i].getLetterPointer(), 1025, text.line[i].getLetterPointer());
	}
}

void Text::addLine(char* newLine) {
	Text tempTextCopy(*this);
	delete[] this->line;
	numberOfLines++;
	this->line = new Line[numberOfLines];
	*this = tempTextCopy;
	strcpy_s(this->line[numberOfLines - 1].getLetterPointer(), 1025, newLine);
}

Text& Text :: operator=(const Text& other) {
	if (this == &other) {
		return *this;
	}
	else {
		for (int i = 0; i < other.numberOfLines; i++) {
			strcpy_s(this->line[i].getLetterPointer(), 1025, other.line[i].getLetterPointer());
		}
		return *this;
	}
}

void Text::print() {
	for (int i = 0; i < this->numberOfLines; i++) {
		std::cout << this->line[i].getLetterPointer();
	}
}

void Text::removeLine(int index) {
	Text tempTextCopy(*this);
	delete[] this->line;
	numberOfLines--;
	this->line = new Line[numberOfLines];
	for (int i = 0, j = 0; i <= this->numberOfLines; i++) {
		if (i == index - 1) {
			continue;
		}
		strcpy_s(this->line[j].getLetterPointer(), 1025, tempTextCopy.line[i].getLetterPointer());
		j++;
	}
}