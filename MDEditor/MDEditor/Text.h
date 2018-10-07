#pragma once
#include <fstream>
#include "Line.h"
#include <iostream>

class Text {
private:
	unsigned numberOfLines;
public:
	Line* line;

	void addLine(char*);
	void removeLine(int);
	unsigned getNumberOfLines() const;
	void setMemory(unsigned);
	void copyLines(char*, unsigned);
	void print();
	Text();
	Text(const Text&);
	Text& operator=(const Text&);
	~Text();
};