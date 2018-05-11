#pragma once
#include <iostream>
#include "User.h"

//All commands have an actor except INFO and Quit
class Command {
	char* backedUpCommandValue;
	char* actor;
	char* subject;
	size_t number;
	enum Type
	{
		ADD_MODERATOR,
		ADD_USER,
		REMOVE_USER,
		BLOCK_USER,
		UNBLOCK_USER,
		POST_IMAGE,
		POST_URL,
		POST_TEXT,
		REMOVE_POST,
		VIEW_CERTAIN_POST,
		VIEW_ALL_POSTS,
		INFO,
		QUIT,
		INVALID_COMMAND
	}type;

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
};
