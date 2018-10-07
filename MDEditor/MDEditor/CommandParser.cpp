#include "CommandParser.h"
#include <iostream>

CommandParser::CommandParser() {
	text = new char[1024];
	type = NOT_SET;
	line = -1;
	from = -1;
	to = -1;
}

bool CommandParser::promptInput() {
	std::cout << "Enter command>";
	std::cin.getline(text, 1024);
	determineType();
	if (type == NOT_SET) {
		std::cout << "Invalid command.\n";
		promptInput();
	}
	if (type == EXIT) {
		return false;
	}
	return true;
}

void CommandParser::determineType() {
	if (arePartialyEqual("makeHeading")) {
		type = MAKE_HEADING;
		setLine();

	}
	else if (arePartialyEqual("makeItalic")) {
		type = MAKE_ITALIC;
		setLine();
		setFrom();
		setTo();
	}
	else if (arePartialyEqual("makeBold")) {
		type = MAKE_BOLD;
		setLine();
		setFrom();
		setTo();
	}
	else if (arePartialyEqual("makeCombine")) {
		type = MAKE_COMBINE;
		setLine();
		setFrom();
		setTo();
	}
	else if (arePartialyEqual("addLine")) {
		type = ADD_LINE;
		setAddLineText();
	}
	else if (arePartialyEqual("removeLine")) {
		type = REMOVE_LINE;
		setLine();
	}
	else if (areExactlyEqual("exit")) {
		type = EXIT;
	}
}

//issue here?
void CommandParser::setLine() {
	int index = 0;
	while (this->text[index] != ' ') {
		index++;
	}
	index++;
	while (isNumber(this->text[index])) {
		index++;
	}
	index--;
	int lineIndex = 0;
	for (int j = 1; isNumber(this->text[index]); j *= 10) {
		lineIndex += (this->text[index] - '0')*j;
		index--;
	}
	this->line = lineIndex;
}

void CommandParser::setFrom() {
	int index = 0;
	while (this->text[index] != '\0') {
		index++;
	}
	while (this->text[index] != ' ') {
		index--;
	}
	index--;
	int fromIndex = 0;
	for (int j = 1; isNumber(this->text[index]); j *= 10) {
		fromIndex += (this->text[index] - '0')*j;
		index--;
	}
	this->from = fromIndex;
}

void CommandParser::setTo() {
	int index = 0;
	while (this->text[index] != '\0') {
		index++;
	}
	index--;
	int toIndex = 0;
	for (int j = 1; isNumber(this->text[index]); j *= 10) {
		toIndex += (this->text[index] - '0')*j;
		index--;
	}
	this->to = toIndex;
}

bool CommandParser::isNumber(char ch) {
	return ch >= '0' && ch <= '9';
}

void CommandParser::clearData() {
	this->type = NOT_SET;
	line = -1;
	from = -1;
	to = -1;
}

bool CommandParser::arePartialyEqual(const char* base) {
	unsigned toIndex = strlen(base) - 1;
	for (int i = 0; i <= toIndex; i++) {
		if (this->text[i] != base[i]) {
			return false;
		}
	}
	return true;
}

bool CommandParser::areExactlyEqual(const char* base) {
	for (int i = 0; base[i] != '\0'; i++) {
		if (this->text[i] != base[i]) {
			return false;
		}
		if (base[i + 1] == '\0' && this->text[i + 1] != '\0') {
			return false;
		}
	}
	return true;
}

char* CommandParser::getText() {
	return this->text;
}

CommandParser::~CommandParser() {
	delete[] text;
}

char* CommandParser::getAddLineText() {
	return this->addLineText;
}

void CommandParser::setAddLineText() {
	for (int i = 0; this->text[i] != '\0'; i++) {
		if (this->text[i] == ' ') {
			addLineText = &text[i + 1];
			return;
		}
	}
}