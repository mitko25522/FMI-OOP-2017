#include "Line.h"
#include <iostream>
#include <string.h>
#include <stdexcept>

Line::Line() {
	letter = new char[1025];
	this->letter[0] = '\0';
}

Line::~Line() {
	delete[] letter;
}

Line::Line(const char* input) {
	letter = new char[1025];
	strcpy_s(this->letter, 1025, input);
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
	this->letter[from] = '#';
}

void Line::makeHeading() {
	shiftRightOnce(0);
	shiftRightOnce(0);
	this->letter[0] = '#';
	this->letter[1] = ' ';
}

void Line::makeItalic(int from, int to) {
	try
	{	
		from = findWordFirstLetterIndex(from);
		shiftRightOnce(from);
		this->letter[from] = '*';
		to = findWordLastLetterIndex(to);
		shiftRightOnce(to+1);
		this->letter[to + 1] = '*';
	}
	catch (const std::exception& except)
	{
		std::cout << "Failed to italicize..\n";
		return;
	}
}

void Line::makeBold(int from, int to) {
	try
	{
		from = findWordFirstLetterIndex(from);
		shiftRightOnce(from);
		shiftRightOnce(from);
		this->letter[from] = '*';
		this->letter[from + 1] = '*';
		to = findWordLastLetterIndex(to);
		shiftRightOnce(to + 1);
		shiftRightOnce(to + 1);
		this->letter[to + 1] = '*';
		this->letter[to + 2] = '*';
	}
	catch (const std::exception& except)
	{
		std::cout << "Failed to bolden..\n";
		return;
	}
}

void Line::makeCombine(int from, int to) {
	try
	{
		makeBold(from, to);
		makeItalic(from, to);
	}
	catch (const std::exception& except)
	{
		std::cout << "Failed to make combined..\n";
		return;
	}
}

int Line::findWordFirstLetterIndex(int wordNumber) {
	try
	{
		if (wordNumber > countWords()) {
			throw std::logic_error("Out of range");
		}
	}
	catch (std::exception& except)
	{
		std::cout << "Error: " << except.what() << std::endl;
		throw;
	}

	if (wordNumber == 1) {
		return 0;
	}

	int spacesCounted = 1;
	for (int i = 0; spacesCounted <= wordNumber; i++) {
		if (this->letter[i] == ' ') {
			spacesCounted++;
		}
		if (spacesCounted == wordNumber) {
			return i + 1;
		}
	}
}

int Line::findWordLastLetterIndex(int wordNumber) {
	try
	{
		if (wordNumber > countWords()) {
			throw std::logic_error("Out of range");
		}
	}
	catch (std::exception& except)
	{
		std::cout << "Error: " << except.what() << std::endl;
		throw;
	}

	int spacesCounted = 1;

	for (int i = 0; spacesCounted <= wordNumber; i++) {
		if (this->letter[i] == ' ') {
			spacesCounted++;
		}
		if (spacesCounted == wordNumber) {
			for (int j = i+1; ; j++) {
				if (this->letter[j] == ' ' || this->letter[j] == '\0') {
					return j - 1;
				}
			}
		}
	}
}

int Line::countWords() {
	int wordsCount = 0;

	if (this->letter[0] != '\0') {
		wordsCount = 1;
	}

	for (int i = 1; this->letter[i] != '\0'; i++) {
		if (this->letter[i] == ' ') {
			wordsCount++;
		}
	}

	return wordsCount;
}

void Line::printLine() {
	std::cout << letter << std::endl;
}