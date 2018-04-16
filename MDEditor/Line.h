#pragma once

class Line {
private:
	char* letter;
	void shiftRightOnce(int);
	int findWordFirstLetterIndex(int);
	int findWordLastLetterIndex(int);
public:
	void makeHeading();
	void italicize(int, int);
	char* getLetterPointer() { return letter; };
	Line();
	~Line();
};