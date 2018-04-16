#include "MarkDownEditor.h"
#include <fstream>
#include "iostream"
#include <string>

MarkDownEditor::MarkDownEditor(char * fileDirectory) {
	this->inputFileDirectory = new char[strlen(fileDirectory + 1)];
	this->outputFileDirectory = new char[strlen(fileDirectory)];

	for (int i = 0; fileDirectory[i] != '\0'; i++) {
		this->inputFileDirectory[i] = fileDirectory[i];
		if (fileDirectory[i + 1] == '\0') {
			this->inputFileDirectory[i + 1] = '\0';
		}
	}
	setOuputFileDirectory();
	loadText();
}

void MarkDownEditor::loadText() {
	int lineCount = countLines();
	loadedText.setMemory(lineCount);
	loadedText.copyLines(inputFileDirectory, lineCount);
}

int MarkDownEditor::countLines() {
	std::ifstream inputFile(inputFileDirectory);
	std::string temp;
	int count = 0;

	while (std::getline(inputFile, temp)) {
		count++;
	}

	inputFile.close();
	return count;
}

void MarkDownEditor::editText(CommandParser& command) {
	switch (command.getType()) {
	case CommandParser::MAKE_HEADING: loadedText.line[command.getLine()].makeHeading(); break;
	case CommandParser::MAKE_ITALIC: loadedText.line[command.getLine()].italicize(command.getFrom(), command.getTo()); break;
	}

}

MarkDownEditor::~MarkDownEditor() {
	delete[] inputFileDirectory;
	delete[] outputFileDirectory;
}

void MarkDownEditor::saveChanges() {
	std::ofstream outFile(outputFileDirectory);
	for (int i = 0; i < loadedText.getNumberOfLines(); i++) {
		outFile << loadedText.line[i].getLetterPointer() << std::endl;
	}
	outFile.close();
}

void MarkDownEditor::setOuputFileDirectory() {
	int i = 0;
	while (inputFileDirectory[i] != '\0') {
		outputFileDirectory[i] = inputFileDirectory[i];
		i++;
	}
	i--;
	outputFileDirectory[i] = '\0';
	i--;
	outputFileDirectory[i] = 'd';
	i--;
	outputFileDirectory[i] = 'm';
}