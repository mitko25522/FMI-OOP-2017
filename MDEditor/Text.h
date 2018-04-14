#pragma once
#include <fstream>
#include "Line.h"

class Text {
private:
	unsigned numberOfLines;
	Line* line;
public:
	void setMemory(unsigned);
	void copyLines(char*, unsigned);
	Text();
	~Text();
};