#pragma once

class Line {
private:
	char* letter;
	void shiftRightOnce(int);
	int countWords();
	int findWordLastLetterIndex(int);
	int findWordFirstLetterIndex(int);
public:
	void makeHeading();
	void makeCombine(int, int);
	void makeItalic(int, int);
	void makeBold(int, int);
	char* getLetterPointer() { return letter; };
	void printLine();

	friend void test_findWordFirstLetterIndex(int);
	friend void test_findWordLastLetterIndex(int);
	friend void test_countWords();
	friend void test_shiftRightOnce(int);
	friend void test_italicize(int, int);
	friend void test_makeBold(int, int);
	friend void test_makeHeading();
	friend void test_makeCombine(int, int);
	Line();
	Line(const char*);
	~Line();
};