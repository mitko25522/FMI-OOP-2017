#include <iostream>
#include "MarkDownEditor.h"
#include "CommandParser.h"
#include <fstream>
#include <string>

void getFileDirectory(char*);

int main() {
	char* directory = new char[256];
	getFileDirectory(directory);
	MarkDownEditor markdownEditor(directory);
	CommandParser command;
	while (command.promptInput()) {
		markdownEditor.editText(command);
	}
	//markdownEditor.saveChanges();
	return 0;
}

void getFileDirectory(char* dir) {
	std::cout << "Enter file directory: ";
	char directory[256];
	std::cin.getline(directory, 256);
	strcpy_s(dir, 256, directory);
}