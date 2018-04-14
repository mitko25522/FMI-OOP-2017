#pragma once

class Line {
private:
	char* letter;
public:
	char* getLetterPointer() { return letter; };
	Line();
	~Line();
};