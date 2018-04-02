#include "Directory.h"
#include <iostream>
#include <memory>

//Directory's default constructor prompts user to enter
//the directory to the file that will be loaded for the program
//e.g. C:\Documents and Settings\davris\FileSchemeURIs.doc
Directory::Directory() {
	std::cout << "Enter file directory> ";
	std::cin.getline(this->path, 256);
}


Directory::Directory(const Directory &other) {
	for (int i = 0; other.path[i] != '\0'; i++) {
		this->path[i] = other.path[i];
		if (other.path[i + 1] == '\0') {
			this->path[i + 1] = '\0';
		}
	}
}

bool Directory::isValid() {
	if (containsIllegalCharacters()) {
		return false;
	}
	else {
		return true;
	}
}

bool Directory::containsIllegalCharacters() {
	for (int i = 0; this->path[i] != '\0'; i++) {
		if (isIllegalCharacter(this->path[i])) {
			return true;
		}
	}
	return false;
}

bool Directory::isIllegalCharacter(char ch) {
	if ((ch == '<') || (ch == '>') ||
		(ch == '"') || (ch == '|') ||
		(ch == '?') || (ch == '*')) {
		return true;
	}
	else {
		return false;
	}
}

char* Directory::getDirectory() {
	return this->path;
}