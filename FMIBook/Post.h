#pragma once
#include "Command.h"

class Post {
private:
	const CommandType type;
	char poster[1024];
	char path[1024];
	char text[1024];
public:
	Post(Command*);
	//Post(const Post&);
};