#pragma once
#include "Text.h"
#include "CommandParser.h"
#include <fstream>

class MarkDownEditor {
private:
	Text loadedText;
	char* inputFileDirectory;
	char* outputFileDirectory;

	void loadText();
	int countLines();
	void setOuputFileDirectory();
public:
	MarkDownEditor(char*);
	~MarkDownEditor();
	void saveChanges();
	void editText(CommandParser&);
};