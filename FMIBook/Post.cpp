#include "Post.h"

Post::Post(Command* command) : type(command->getCommandType()) {
	if (type == POST_IMAGE) {
		strcpy_s(poster, 1024, command->getActor());
		strcpy_s(path, 1024, command->getPath());
		text[0] = '\0';
	}
	else if (type == POST_URL) {
		strcpy_s(poster, 1024, command->getActor());
		strcpy_s(path, 1024, command->getPath());
		strcpy_s(text, 1024, command->getUrlDescription());
	}
	else if (type == POST_TEXT) {
		strcpy_s(poster, 1024, command->getActor());
		strcpy_s(text, 1024, command->getPostText());
	}
	else {
		throw std::logic_error("Post type not supported");
	}
}
//
//Post::Post(const Post& other) : {
//
//}