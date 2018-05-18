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

	if (hasPath()) {
		setPath();
	}

	if (this->type == POST_URL) {
		extractUrlDescription();
	}

	if (this->type == POST_TEXT) {
		extractPostText();
	}
}

void Command::setActorNameFromInput() {
	size_t sizeOfActorName = 0;

	for (int i = 0; backedUpCommandValue[i] != ' '; i++) {
		this->actor[i] = this->backedUpCommandValue[i];
		if (backedUpCommandValue[i + 1] == ' ') {
			this->actor[i + 1] = '\0';
		}
	}
}

void Command::setSubjectNameFromInput() {
	size_t currentIndex = 0;

	while (backedUpCommandValue[currentIndex] != ' ') {
		currentIndex++;
	}

	currentIndex++;

	while (backedUpCommandValue[currentIndex] != ' ') {
		currentIndex++;
	}

	currentIndex++;

	size_t subjectIndex = 0;
	while (backedUpCommandValue[currentIndex] != ' ' && backedUpCommandValue[currentIndex] != '\0') {
		helperString[subjectIndex] = backedUpCommandValue[currentIndex];
		currentIndex++;
		subjectIndex++;

		if (backedUpCommandValue[currentIndex] == ' ' || backedUpCommandValue[currentIndex] == '\0') {
			helperString[subjectIndex] = '\0';
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
	else if (strncmp(backedUpCommandValue, "post_list", 5) == 0) {
		this->type = VIEW_POST_LIST;
		return;
	}
	else if (strncmp(backedUpCommandValue, "news_feed", 5) == 0) {
		this->type = VIEW_NEWS_FEED;
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
	else if (strcmp(typeStr, "post_image") == 0)
		this->type = POST_IMAGE;
	else if (strcmp(typeStr, "post_url") == 0)
		this->type = POST_URL;
	else if (strcmp(typeStr, "post_text") == 0)
		this->type = POST_TEXT;
	else
		this->type = INVALID_COMMAND;

	delete[] typeStr;
}

Command::~Command() {
	//if (hasSubject())
	//{
	//	delete[] helperString;
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
		this->type != INVALID_COMMAND &&
		this->type != VIEW_POST_LIST &&
		this->type != VIEW_NEWS_FEED;
}

bool Command::hasSubject()
{
	return
		this->type == ADD_MODERATOR || this->type == ADD_USER ||
		this->type == REMOVE_USER || this->type == BLOCK_USER ||
		this->type == UNBLOCK_USER || this->type == RENAME;
}

bool Command::hasSubjectAge() {
	return
		this->type == ADD_MODERATOR || this->type == ADD_USER;
}

bool Command::hasPostId() {
	return
		this->type == REMOVE_USER || this->type == BLOCK_USER ||
		this->type == UNBLOCK_USER || this->type == REMOVE_POST ||
		this->type == VIEW_CERTAIN_POST || this->type == VIEW_ALL_POSTS;
}

bool Command::hasPath() {
	return
		this->type == POST_IMAGE || this->type == POST_URL;
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
		return helperString;
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

CommandType Command::getCommandType() {
	return type;
}

//Admin post_image C:\users\desktop\dzvera.png
void Command::setPath() {
	size_t spaceCounter = 0;
	size_t currentIndex = 0;

	while (spaceCounter < 2) {
		if (backedUpCommandValue[currentIndex] == ' ') {
			spaceCounter++;
		}
		currentIndex++;
	}

	size_t helperStringIndex = 0;
	while (backedUpCommandValue[currentIndex] != '\0' &&backedUpCommandValue[currentIndex] != ' ') {
		helperString[helperStringIndex] = backedUpCommandValue[currentIndex];
		currentIndex++;
		helperStringIndex++;

		if (backedUpCommandValue[currentIndex] == '\0' || backedUpCommandValue[currentIndex] == ' ') {
			helperString[helperStringIndex] = '\0';
		}
	}
}

char* Command::getPath() {
	if (hasPath()) {
		return helperString;
	}
}

//Admin post_url www.google.bg this is a link to google
void Command::extractUrlDescription() {
	size_t spaceCounter = 0;
	size_t currentIndex = 0;

	while (spaceCounter < 3) {
		if (backedUpCommandValue[currentIndex] == ' ') {
			spaceCounter++;
		}
		currentIndex++;
	}

	size_t helperStringIndex = 0;
	while (backedUpCommandValue[currentIndex] != '\0') {
		helperStringTwo[helperStringIndex] = backedUpCommandValue[currentIndex];
		currentIndex++;
		helperStringIndex++;

		if (backedUpCommandValue[currentIndex] == '\0') {
			helperStringTwo[helperStringIndex] = '\0';
		}
	}
}

char* Command::getPostText() {
	return helperString;
}

void Command::extractPostText() {
	int currentIndex = 0;

	while (backedUpCommandValue[currentIndex] != ' ') {
		currentIndex++;
	}

	currentIndex++;

	while (backedUpCommandValue[currentIndex] != ' ') {
		currentIndex++;
	}

	currentIndex++;

	int postTextIndex = 0;

	while (backedUpCommandValue[currentIndex] != '\0') {
		helperString[postTextIndex] = backedUpCommandValue[currentIndex];
		currentIndex++;
		postTextIndex++;

		if (backedUpCommandValue[currentIndex] == '\0') {
			helperString[postTextIndex] = '\0';
		}
	}
}

char* Command::getUrlDescription() {
	if (this->type == POST_URL) {
		return helperStringTwo;
	}
}