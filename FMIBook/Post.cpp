#include "Post.h"
#include "FMIBook.h"

Post::Post(Command* command) : type(command->getCommandType()) {
	if (type == POST_IMAGE) {
		strcpy_s(poster, 1024, command->getActor());

		if (FMIBook::user_list.at(FMIBook::findUserPos(poster)).getPermissions()->canPostImage()) {
			strcpy_s(path, 1024, command->getPath());
			text[0] = '\0';
		}
		else {
			throw std::logic_error("User does not have needed permissions.");
		}
	}
	else if (type == POST_URL) {
		strcpy_s(poster, 1024, command->getActor());

		if (FMIBook::user_list.at(FMIBook::findUserPos(poster)).getPermissions()->canPostUrl()) {
			strcpy_s(path, 1024, command->getPath());
			strcpy_s(text, 1024, command->getUrlDescription());
		}
		else {
			throw std::logic_error("User does not have needed permissions.");
		}
	}
	else if (type == POST_TEXT) {
		strcpy_s(poster, 1024, command->getActor());

		if (FMIBook::user_list.at(FMIBook::findUserPos(poster)).getPermissions()->canPostUrl()) {
			strcpy_s(text, 1024, command->getPostText());
			path[0] = '\0';
		}
		else {
			throw std::logic_error("User does not have needed permissions.");
		}
	}
	else {
		throw std::logic_error("Post type not supported");
	}
}


Post::Post(const Post& other) : type(other.type) {
	strcpy_s(this->poster, 1024, other.poster);

	if (hasPath()) {
		strcpy_s(this->path, 1024, other.path);
	}

	if (hasText()) {
		strcpy_s(this->text, 1024, other.text);
	}
}

bool Post::hasPath() {
	return this->type == POST_IMAGE || this->type == POST_URL;
}

bool Post::hasText() {
	return this->type == POST_URL || this->type == POST_TEXT;
}

void Post::printInformationCompact() {
	std::cout << "Type: ";

	switch (type) {
	case POST_IMAGE: std::cout << "image | "; break;
	case POST_URL:	 std::cout << "link  | "; break;
	case POST_TEXT:  std::cout << "text  | "; break;
	}

	std::cout << " Poster: " << poster << " | ";

	if (type == POST_IMAGE) {
		std::cout << " Path: " << path;
	}
	else if (type == POST_URL) {
		std::cout << " Path: " << path << " | ";
		std::cout << " Description: " << text;
	}
	else if (type == POST_TEXT) {
		std::cout << " Text: " << text;
	}

}

bool Post::isPoster(const char* nickname) {
	return (strcmp(poster, nickname) == 0);
}

Post& Post::operator=(const Post& other) {
	if (this == &other) {
		return *this;
	}

	this->type = other.type;
	strcpy_s(this->poster, 1024, other.poster);

	if (hasPath()) {
		strcpy_s(this->path, 1024, other.path);
	}

	if (hasText()) {
		strcpy_s(this->text, 1024, other.text);
	}

	return *this;
}

CommandType Post::getType() {
	return this->type;
}

char* Post::getPoster() {
	return this->poster;
}

char* Post::getPath() {
	if (hasPath()) {
		return this->path;
	}
}

char* Post::getText() {
	if (hasText()) {
		return this->text;
	}
}