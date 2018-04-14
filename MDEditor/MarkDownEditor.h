#pragma once
#include "Text.h"
#include "CommandParser.h"
#include <fstream>

class MarkDownEditor {
private:
	Text loadedText;
	char* fileDirectory;
	void loadText();
	int countLines();
public:
	MarkDownEditor();
	MarkDownEditor(char*);
	~MarkDownEditor();
	void editText(CommandParser&);
};	