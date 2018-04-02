#pragma once

class Directory {
	char path[256];
	bool containsIllegalCharacters();
	bool isIllegalCharacter(char);
public:
	bool isValid();
	Directory();
	Directory(const Directory&);
	char* getDirectory();
};