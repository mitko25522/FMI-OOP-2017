#pragma once
#include "Text.h"
#include "Directory.h"

class MarkDownEditor {
	void loadText(const char*);
	Text loadedText;
public:
	MarkDownEditor(const char*);
};