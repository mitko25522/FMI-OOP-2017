#pragma once

class CommandParser {
private:
	char* text;
	char* addLineText;
	int line;
	int from;
	int to;

	bool areExactlyEqual(const char*);
	void determineType();
	bool arePartialyEqual(const char*);
	void setLine();
	void setFrom();
	void setTo();
	void setAddLineText();
	bool isNumber(char);
public:
	enum Type {
		NOT_SET,
		MAKE_HEADING,
		MAKE_ITALIC,
		MAKE_BOLD,
		MAKE_COMBINE,
		ADD_LINE,
		REMOVE_LINE,
		EXIT
	} type;
	Type getType() { return type; }
	int getLine() { return line - 1; }
	int getFrom() { return from - 1; }
	int getTo() { return to - 1; }
	bool promptInput();
	void clearData();
	char* getText();
	char* getAddLineText();
	CommandParser();
	~CommandParser();
};