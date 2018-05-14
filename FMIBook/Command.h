#pragma once
#include <iostream>
#include "User.h"

enum Type
{
	ADD_MODERATOR,//
	ADD_USER,//
	REMOVE_USER,
	BLOCK_USER,//
	UNBLOCK_USER,//
	POST_IMAGE,
	POST_URL,
	POST_TEXT,
	REMOVE_POST,
	VIEW_CERTAIN_POST,
	VIEW_ALL_POSTS,
	RENAME,
	INFO,//
	QUIT,//
	INVALID_COMMAND//
};

//All commands have an actor except INFO and Quit
class Command {
	Type type;
	char backedUpCommandValue[1024];
	char actor[1024];
	char subject[1024];
	size_t number;

	Command();
	void setActorNameFromInput();
	void setSubjectNameFromInput();
	void determineType();
	bool hasActor();
	bool hasSubject();
	bool hasSubjectAge();
	bool hasPostId();
	void extractNumber();
public:
	Command(const char*);
	~Command();

	char* getActor();
	char* getSubject();
	size_t getSubjectAge();
	size_t getPostId();
	Type getType();
};
