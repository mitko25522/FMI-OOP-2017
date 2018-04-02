#pragma once
#include "Line.h"

class Text {
	unsigned numberOfLines;
	Line* line;
public:
	Text();
	Text(unsigned);
	~Text();
};
	