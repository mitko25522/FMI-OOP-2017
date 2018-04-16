#pragma once
#include <fstream>
#include "Line.h"

class Text {
private:
	unsigned numberOfLines;
public:
	Line* line;
	unsigned getNumberOfLines();
	void setMemory(unsigned);
	void copyLines(char*, unsigned);
	Text();
	~Text();
};