#include "HtmlGenerator.h"
#include <time.h>
#include "FMIBook.h"
#include <fstream>

void HtmlGenerator::generateNewsFeed() {
	char name[16];
	generateHtmlFileName(name);
	appendHeaderOpener(name);

	size_t postsCount = FMIBook::post_list.size();
	for (int currentPostIndex = 0; currentPostIndex < postsCount; currentPostIndex++) {
		appendToFile(name, &FMIBook::post_list.at(currentPostIndex));
	}

	appendHeaderCloser(name);
	std::cout << "File " << name << " saved" << std::endl;
}

size_t HtmlGenerator::getCurrentTime() {
	return time(0);
}

//1526571477
void HtmlGenerator::generateHtmlFileName(char name[16]) {
	size_t currentTime = getCurrentTime();

	int nameIndex = 9;
	int divisor = 1;
	for (int i = 0; i < 10; ++i) {
		name[nameIndex] = ((currentTime / divisor) % 10) + '0';
		nameIndex--;
		divisor *= 10;
	}

	nameIndex = 10;
	name[nameIndex++] = '.';
	name[nameIndex++] = 'h';
	name[nameIndex++] = 't';
	name[nameIndex++] = 'm';
	name[nameIndex++] = 'l';
	name[nameIndex] = '\0';
}

void HtmlGenerator::appendHeaderOpener(char* destination, const char* source) {
	std::ifstream headerInput(source, std::ios::in);
	std::ofstream outputFile(destination, std::ios::out | std::ios::trunc);

	char buffer[1024];
	while (headerInput.getline(buffer, 1024)) {
		outputFile << buffer << std::endl;
	}

	headerInput.close();
	outputFile.close();
}

void HtmlGenerator::appendToFile(char* destination, Post* post) {
	switch (post->getType()) {
	case POST_IMAGE:	appendImageTemplate(destination, post);	 break;
	case POST_URL:		appendUrlTemplate(destination, post);	 break;
	case POST_TEXT:		appendTextTemplate(destination, post);	 break;
	}
}

// Admin post_image C:\Users\mitko\Desktop\FMIBook\Screenshot_1.png
void HtmlGenerator::appendImageTemplate(char* destination, Post* post, const char* source) {
	std::ifstream imageTemplate(source, std::ios::in);
	std::ofstream outputFile(destination, std::ios::out | std::ios::app);

	char buffer[1024];
	int currentLineIndex = 0;
	while (imageTemplate.getline(buffer, 1024)) {
		if (currentLineIndex == IMAGE_TEMPLATE_POSTER_ROW) {
			outputFile << post->getPoster() << std::endl;
			currentLineIndex++;
			continue;
		}

		if (currentLineIndex == IMAGE_TEMPLATE_PATH_ROW) {
			outputFile << post->getPath() << std::endl;
			currentLineIndex++;
			continue;
		}
		outputFile << buffer << std::endl;
		currentLineIndex++;
	}

	imageTemplate.close();
	outputFile.close();
}

void HtmlGenerator::appendUrlTemplate(char* destination, Post* post, const char* source) {
	std::ifstream imageTemplate(source, std::ios::in);
	std::ofstream outputFile(destination, std::ios::out | std::ios::app);

	char buffer[1024];
	int currentLineIndex = 0;
	while (imageTemplate.getline(buffer, 1024)) {
		if (currentLineIndex == URL_TEMPLATE_POSTER_ROW) {
			outputFile << post->getPoster() << std::endl;
			currentLineIndex++;
			continue;
		}

		if (currentLineIndex == URL_TEMPLATE_PATH_ROW) {
			outputFile << post->getPath() << std::endl;
			currentLineIndex++;
			continue;
		}

		if (currentLineIndex == URL_TEMPLATE_TEXT_ROW) {
			outputFile << post->getText() << std::endl;
			currentLineIndex++;
			continue;
		}

		outputFile << buffer << std::endl;
		currentLineIndex++;
	}

	imageTemplate.close();
	outputFile.close();
}

void HtmlGenerator::appendTextTemplate(char* destination, Post* post, const char* source) {
	std::ifstream imageTemplate(source, std::ios::in);
	std::ofstream outputFile(destination, std::ios::out | std::ios::app);

	char buffer[1024];
	int currentLineIndex = 0;
	while (imageTemplate.getline(buffer, 1024)) {
		if (currentLineIndex == TEXT_TEMPLATE_POSTER_ROW) {
			outputFile << post->getPoster() << std::endl;
			currentLineIndex++;
			continue;
		}

		if (currentLineIndex == TEXT_TEMPLATE_TEXT_ROW) {
			outputFile << post->getText() << std::endl;
			currentLineIndex++;
			continue;
		}
		outputFile << buffer << std::endl;
		currentLineIndex++;
	}

	imageTemplate.close();
	outputFile.close();
}

void HtmlGenerator::appendHeaderCloser(char* destination, const char* source) {
	std::ifstream headerInput(source, std::ios::in);
	std::ofstream outputFile(destination, std::ios::out | std::ios::app);

	char buffer[1024];
	while (headerInput.getline(buffer, 1024)) {
		outputFile << buffer << std::endl;
	}

	headerInput.close();
	outputFile.close();
}

void HtmlGenerator::generateProfilePage(Command* command) {
	if (!(FMIBook::user_list.at(FMIBook::findUserPos(command->getActor())).getPermissions()->canViewAllPosts())) {
		throw std::logic_error("Actor does not have needed permissions");
	}

	if (FMIBook::user_list.at(FMIBook::findUserPos(command->getSubject())).getPostsCount() == 0) {
		throw std::logic_error("Subject does not have any posts or does not exist");
	}

	char fileName[16];
	generateHtmlFileName(fileName);
	appendHeaderOpener(fileName);

	size_t postsCount = FMIBook::post_list.size();
	for (int currentPostIndex = 0; currentPostIndex < postsCount; currentPostIndex++) {
		if (FMIBook::post_list.at(currentPostIndex).isPoster(command->getSubject())) {
			appendToFile(fileName, &FMIBook::post_list.at(currentPostIndex));
		}
	}

	appendHeaderCloser(fileName);
	std::cout << "File " << fileName << " saved" << std::endl;
}

void HtmlGenerator::generateSinglePostPage(Command* command) {
	if (!(FMIBook::user_list.at(FMIBook::findUserPos(command->getActor())).getPermissions()->canViewCertainPost())) {
		throw std::logic_error("Actor does not have needed permissions");
	}

	size_t previewPostIndex = command->getPostId() + 1;
	size_t postsCount = FMIBook::post_list.size();

	if (previewPostIndex > postsCount) {
		throw std::logic_error("No such post exists");
	}

	char fileName[16];
	generateHtmlFileName(fileName);
	appendHeaderOpener(fileName);
	appendToFile(fileName, &FMIBook::post_list.at(previewPostIndex));
	appendHeaderCloser(fileName);
	std::cout << "File " << fileName << " saved" << std::endl;
}