#pragma once
#include "Post.h"

#define IMAGE_TEMPLATE_TIME_ROW 5
#define IMAGE_TEMPLATE_POSTER_ROW 9
#define IMAGE_TEMPLATE_PATH_ROW 15
#define URL_TEMPLATE_TIME_ROW 6
#define URL_TEMPLATE_POSTER_ROW 10
#define URL_TEMPLATE_PATH_ROW 16
#define URL_TEMPLATE_TEXT_ROW 18
#define TEXT_TEMPLATE_TIME_ROW 5
#define TEXT_TEMPLATE_POSTER_ROW 9
#define TEXT_TEMPLATE_TEXT_ROW 14



class HtmlGenerator {
public:
	static size_t getCurrentTime();
	static void generateHtmlFileName(char[16]);
	static void generateNewsFeed();
	static void appendHeaderOpener(char*, const char* = "headerOpenerTemplate.html");
	static void appendToFile(char*, Post*);
	static void appendImageTemplate(char*, Post*, const char* = "imageTemplate.html");
	static void appendUrlTemplate(char*, Post*, const char* = "urlTemplate.html");
	static void appendTextTemplate(char*, Post*, const char* = "textTemplate.html");
	static void appendHeaderCloser(char*, const char* = "headerCloserTemplate.html");
};