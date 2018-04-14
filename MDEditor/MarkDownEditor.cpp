#include "MarkDownEditor.h"
#include <fstream>
#include "iostream"
#include <string>

MarkDownEditor::MarkDownEditor(char * fileDirectory) {
	this->fileDirectory = new char[strlen(fileDirectory + 1)];
	for (int i = 0; fileDirectory[i] != '\0'; i++) {
		this->fileDirectory[i] = fileDirectory[i];
		if (fileDirectory[i + 1] == '\0') {
			this->fileDirectory[i + 1] = '\0';
		}
	}
	loadText();
}

void MarkDownEditor::loadText() {
	int lineCount = countLines();
	loadedText.setMemory(lineCount);
	loadedText.copyLines(fileDirectory, lineCount);
}


int MarkDownEditor::countLines() {
	std::ifstream inputFile(fileDirectory);
	std::string temp;
	int count = 0;

	while (std::getline(inputFile, temp)) {
		count++;
	}

	inputFile.close();
	return count;
}

void MarkDownEditor::editText(CommandParser& command) {
	std::cout << command.text;
}

MarkDownEditor::~MarkDownEditor() {
	delete[] fileDirectory;
}