#include "Command.h"
#include "FMIBook.h"

Command::Command(const char* command) {
	this->backedUpCommandValue = new char[strlen(command) + 1];
	strcpy_s(this->backedUpCommandValue, 1025, command);
	determineType();

	if (hasActor()) {
		setActorNameFromInput();
	}

	if (hasSubject()) {
		setSubjectNameFromInput();
	}

	if (hasSubjectAge() || hasPostId()) {
		extractNumber();
	}
}

void Command::setActorNameFromInput() {
	int sizeOfActorName = 0;
	for (int i = 0; backedUpCommandValue[i] != ' '; i++) {
		sizeOfActorName++;
	}

	actor = new char[sizeOfActorName + 1];

	for (int i = 0; backedUpCommandValue[i] != ' '; i++) {
		this->actor[i] = this->backedUpCommandValue[i];
		if (backedUpCommandValue[i + 1] == ' ') {
			this->actor[i + 1] = '\0';
		}
	}
}

void Command::setSubjectNameFromInput() {
	int index = 0;

	while (backedUpCommandValue[index] != ' ') {
		index++;
	}

	index++;

	while (backedUpCommandValue[index] != ' ') {
		index++;
	}

	index++;

	int sizeOfSubjectName = 0;

	while (backedUpCommandValue[index] != ' ') {
		sizeOfSubjectName++;
		index++;
	}

	index -= sizeOfSubjectName;
	subject = new char[sizeOfSubjectName + 1];

	int subjectIndex = 0;

	while (backedUpCommandValue[index] != ' ') {
		subject[subjectIndex] = backedUpCommandValue[index];
		index++;
		subjectIndex++;

		if (backedUpCommandValue[index] == ' ') {
			subject[subjectIndex] = '\0';
		}
	}
}

void Command::determineType() {
	char* type = new char[1024];
	int index = 0;

	while (backedUpCommandValue[index] != ' ') {
		index++;
	}

	index++;

	int typeIndex = 0;
	while (backedUpCommandValue[index] != ' ') {
		type[typeIndex] = backedUpCommandValue[index];
		typeIndex++;
		index++;
	}

	type[typeIndex] = '\0';

	if (strcmp(type, "add_moderator") == 0)
		this->type = ADD_MODERATOR;
	else if (strcmp(type, "add_user") == 0)
		this->type = ADD_USER;
	else if (strcmp(type, "remove_user") == 0)
		this->type = REMOVE_USER;
	else if (strcmp(type, "block_user") == 0)
		this->type = BLOCK_USER;
	else if (strcmp(type, "unblock_user") == 0)
		this->type = UNBLOCK_USER;
	else if (strcmp(type, "post_image") == 0)
		this->type = POST_IMAGE;
	else if (strcmp(type, "post_url") == 0)
		this->type = POST_URL;
	else if (strcmp(type, "post_text") == 0)
		this->type = POST_TEXT;
	else if (strcmp(type, "remove_post") == 0)
		this->type = REMOVE_POST;
	else if (strcmp(type, "view_post") == 0)
		this->type = VIEW_CERTAIN_POST;
	else if (strcmp(type, "view_all_posts") == 0)
		this->type = VIEW_ALL_POSTS;
	else if (strcmp(type, "info") == 0)
		this->type = INFO;
	else if (strcmp(type, "quit") == 0)
		this->type = QUIT;
	else
		this->type = INVALID_COMMAND;

	delete[] type;
}

Command::~Command() {
	if (hasSubject())
	{
		delete[] subject;
	}

	if (hasActor())
	{
		delete[] actor;
	}


	delete[] backedUpCommandValue;
}

bool Command::hasActor()
{
	return this->type != INFO &&
		this->type != QUIT &&
		this->type != INVALID_COMMAND;
}

bool Command::hasSubject()
{
	return this->type == ADD_MODERATOR || this->type == ADD_USER ||
		this->type == REMOVE_USER || this->type == BLOCK_USER ||
		this->type == UNBLOCK_USER;
}

bool Command::hasSubjectAge() {
	return this->type == ADD_MODERATOR || this->type == ADD_USER;
}

bool Command::hasPostId() {
	return this->type == REMOVE_USER || this->type == BLOCK_USER ||
		this->type == UNBLOCK_USER || this->type == REMOVE_POST ||
		this->type == VIEW_CERTAIN_POST || this->type == VIEW_ALL_POSTS;
}

void Command::extractNumber() {
	int index = 0;
	while (backedUpCommandValue[index] != '\0') {
		index++;
	}

	index--;

	size_t number = 0;

	for (int j = 1; backedUpCommandValue[index] != ' '; index--, j *= 10) {
		number += (backedUpCommandValue[index] - '0') * j;
	}

	this->number = number;
}