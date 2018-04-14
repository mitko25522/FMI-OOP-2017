#include "CommandParser.h"
#include <iostream>

CommandParser::CommandParser() {
	text = new char[1024];
	type = NOT_SET;
}

bool CommandParser::promptInput() {
	std::cout << "Enter command>";
	std::cin.getline(text, 1024);
	if (!isValid()) {
		std::cout << "Invalid command.\n";
		promptInput();
	}
	if (areEqual(this->text, "exit")) {
		return false;
	}
	return true;
}

bool CommandParser::isValid() {
	//check for input validity here
	return true;
}

bool CommandParser::areEqual(char* input, const char* base) {
	for (int i = 0; base[i] != '\0'; i++) {
		if (input[i] != base[i]) {
			return false;
		}
		if (base[i + 1] == '\0' && input[i + 1] != '\0') {
			return false;
		}
	}
	return true;
}

CommandParser::~CommandParser() {
	delete[] text;
}