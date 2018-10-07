#include "Test.h"
#include <iostream>
#include "Line.h"

void test_findWordFirstLetterIndex(int wordIndex) {
	Line test("aaa bbb ccc ddd eee");
	try
	{
		std::cout << "Index of first letter of word " << wordIndex << " is: " << test.findWordFirstLetterIndex(wordIndex) << std::endl;
	}
	catch (std::exception& except)
	{
		return;
	}
}

void test_findWordLastLetterIndex(int wordIndex) {
	Line test("aaa bbb ccc ddd eee");
	try
	{
		std::cout << "Index of last letter of word " << wordIndex << " is: " << test.findWordLastLetterIndex(wordIndex) << std::endl;
	}
	catch (std::exception& except)
	{
		return;
	}
}

void test_countWords() {
	Line test("one two three four");
	std::cout << test.countWords() << std::endl;
}

void test_shiftRightOnce(int from) {
	Line test("one two three four");
	std::cout << "Before edit: ";
	test.printLine();
	test.shiftRightOnce(0);
	std::cout << "After edit : ";
	test.printLine();
}

void test_italicize(int from, int to) {
	Line test("one two three four");
	std::cout << "Before edit: ";
	test.printLine();
	test.makeItalic(from, to);
	std::cout << "After edit : ";
	test.printLine();

}

void test_makeBold(int from, int to) {
	Line test("one two three four");
	std::cout << "Before edit: ";
	test.printLine();
	test.makeBold(from, to);
	std::cout << "After edit : ";
	test.printLine();
}

void test_makeHeading() {
	Line test("one two three four");
	std::cout << "Before edit: ";
	test.printLine();
	test.makeHeading();
	std::cout << "After edit : ";
	test.printLine();
}

void test_makeCombine(int from, int to) {
	Line test("one two three four");
	std::cout << "Before edit: ";
	test.printLine();
	test.makeCombine(from, to);
	std::cout << "After edit : ";
	test.printLine();
}