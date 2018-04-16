#pragma once

class CommandParser {
private:
	char* text;
	int line;
	int from;
	int to;

	bool areExactlyEqual(const char*);
	void determineType();
	bool arePartialyEqual(const char*);
	void setLine();
	void setFrom();
	void setTo();
	bool isNumber(char);
public:
	enum Type{
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
	int getLine() { return line; }
	int getFrom() { return from; }
	int getTo() { return to; }
	bool promptInput();
	void clearData();
	char* getText();
	CommandParser();
	~CommandParser();
};