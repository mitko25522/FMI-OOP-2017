#pragma once
#include "Command.h"
#include "User.h"

class Post {
private:
	CommandType type;
	char poster[1024];
	char path[1024];
	char text[1024];

	bool hasPath();
	bool hasText();
	Post();
public:
	Post(Command*);
	Post(const Post&);
	Post& operator=(const Post&);
	bool isPoster(const char*);
	void printInformationCompact();
	CommandType getType();
	char* getPoster();
	char* getPath();
	char* getText();
};