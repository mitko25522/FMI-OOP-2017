#pragma once
#include <iostream>
#include "User.h"

enum CommandType
{
	ADD_MODERATOR,//
	ADD_USER,//
	REMOVE_USER,
	BLOCK_USER,//
	UNBLOCK_USER,//
	POST_IMAGE,//
	POST_URL,//
	POST_TEXT,//
	REMOVE_POST,
	VIEW_CERTAIN_POST,
	VIEW_NEWS_FEED,
	VIEW_ALL_POSTS,
	VIEW_POST_LIST,//
	RENAME,//
	INFO,//
	QUIT,//
	INVALID_COMMAND//
};

///All commands have an actor except INFO and Quit
class Command {
	CommandType type;
	char backedUpCommandValue[1024];
	char actor[1024];
	char helperString[1024];
	char helperStringTwo[1024];
	size_t number;

	Command();
	void determineType();
	void setActorNameFromInput();
	void setSubjectNameFromInput();
	void extractNumber();
	void extractUrlDescription();
	void extractPostText();
	void setPath();
	bool hasActor();
	bool hasSubject();
	bool hasSubjectAge();
	bool hasPostId();
	bool hasPath();

public:
	Command(const char*);
	~Command();

	char* getActor();
	char* getSubject();
	size_t getSubjectAge();
	size_t getPostId();
	char* getPath();
	char* getPostText();
	char* getUrlDescription();
	CommandType getCommandType();
};
