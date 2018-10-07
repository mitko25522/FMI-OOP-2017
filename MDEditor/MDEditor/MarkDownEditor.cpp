#include "MarkDownEditor.h"
#include <fstream>
#include "iostream"
#include <string>

MarkDownEditor::MarkDownEditor(char * fileDirectory) : inputFileDirectory(NULL), outputFileDirectory(NULL) {
	this->inputFileDirectory = new char[strlen(fileDirectory)];
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
	case CommandParser::MAKE_ITALIC: loadedText.line[command.getLine()].makeItalic(command.getFrom(), command.getTo()); break;
	case CommandParser::MAKE_BOLD: loadedText.line[command.getLine()].makeBold(command.getFrom(), command.getTo()); break;
	case CommandParser::MAKE_COMBINE: loadedText.line[command.getLine()].makeCombine(command.getFrom(), command.getTo()); break;
	case CommandParser::ADD_LINE: loadedText.addLine(command.getAddLineText()); break;
	case CommandParser::REMOVE_LINE: loadedText.removeLine(command.getLine() + 1); break;
	}

}

//heap corruption
MarkDownEditor::~MarkDownEditor() {
	/*delete[] inputFileDirectory;
	delete[] outputFileDirectory;*/
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