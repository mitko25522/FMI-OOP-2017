#include "Command.h"
#include "FMIBook.h"

Command::Command(const char* command) {
	//Acces violation when I use this
	//size_t len = strlen(command) + 1;
	//std::cout << "\nLen: " << len << std::endl;
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

	int subjectIndex = 0;

	while (backedUpCommandValue[index] != ' ' && backedUpCommandValue[index] != '\0') {
		subject[subjectIndex] = backedUpCommandValue[index];
		index++;
		subjectIndex++;

		if (backedUpCommandValue[index] == ' ' || backedUpCommandValue[index] == '\0') {
			subject[subjectIndex] = '\0';
		}
	}
}

void Command::determineType() {
	if (strncmp(backedUpCommandValue, "quit", 5) == 0) {
		this->type = QUIT;
		return;
	}
	else if (strncmp(backedUpCommandValue, "info", 5) == 0) {
		this->type = INFO;
		return;
	}



	char* typeStr = new char[1024];
	int index = 0;

	while (backedUpCommandValue[index] != ' ') {
		index++;
		if (backedUpCommandValue[index] == '\0') {
			this->type = INVALID_COMMAND;
			return;
		}
	}

	index++;

	int typeIndex = 0;
	while (backedUpCommandValue[index] != ' ') {
		typeStr[typeIndex] = backedUpCommandValue[index];
		typeIndex++;
		index++;
	}

	typeStr[typeIndex] = '\0';

	if (strcmp(typeStr, "add_moderator") == 0)
		this->type = ADD_MODERATOR;
	else if (strcmp(typeStr, "add_user") == 0)
		this->type = ADD_USER;
	else if (strcmp(typeStr, "remove_user") == 0)
		this->type = REMOVE_USER;
	else if (strcmp(typeStr, "block_user") == 0)
		this->type = BLOCK_USER;
	else if (strcmp(typeStr, "unblock_user") == 0)
		this->type = UNBLOCK_USER;
	else if (strcmp(typeStr, "post_image") == 0)
		this->type = POST_IMAGE;
	else if (strcmp(typeStr, "post_url") == 0)
		this->type = POST_URL;
	else if (strcmp(typeStr, "post_text") == 0)
		this->type = POST_TEXT;
	else if (strcmp(typeStr, "remove_post") == 0)
		this->type = REMOVE_POST;
	else if (strcmp(typeStr, "view_post") == 0)
		this->type = VIEW_CERTAIN_POST;
	else if (strcmp(typeStr, "view_all_posts") == 0)
		this->type = VIEW_ALL_POSTS;
	else if (strcmp(typeStr, "rename") == 0)
		this->type = RENAME;
	else
		this->type = INVALID_COMMAND;

	delete[] typeStr;
}

Command::~Command() {
	//if (hasSubject())
	//{
	//	delete[] subject;
	//}

	//if (hasActor())
	//{
	//	delete[] actor;
	//}


	//delete[] backedUpCommandValue;
}

bool Command::hasActor()
{
	return
		this->type != INFO &&
		this->type != QUIT &&
		this->type != INVALID_COMMAND;
}

bool Command::hasSubject()
{
	return
		this->type == ADD_MODERATOR || this->type == ADD_USER ||
		this->type == REMOVE_USER || this->type == BLOCK_USER ||
		this->type == UNBLOCK_USER || this->type == RENAME;
}

bool Command::hasSubjectAge() {
	return this->type == ADD_MODERATOR || this->type == ADD_USER;
}

bool Command::hasPostId() {
	return
		this->type == REMOVE_USER || this->type == BLOCK_USER ||
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

char* Command::getActor() {
	if (this->hasActor()) {
		return actor;
	}
}

char* Command::getSubject() {
	if (this->hasSubject()) {
		return subject;
	}
}

size_t Command::getSubjectAge() {
	if (this->hasSubjectAge()) {
		return number;
	}
}

size_t Command::getPostId() {
	if (this->hasPostId()) {
		return number;
	}
}

Type Command::getType() {
	return type;
}