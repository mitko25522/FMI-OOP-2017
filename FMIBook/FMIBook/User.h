#pragma once
#include "Permissions.h"
#include <iostream>

class User {
private:
	Permissions permissions;
	char nickname[1024];
	int age;

	User();
public:
	User(const char* nickname, int age, int permission_preset);
	User(const User& other);
	~User();
	void printInformation();
	void printInformationCompact();
	Permissions* getPermissions();
	char* getNickname();
	int getAge();
	size_t getPostsCount();
	bool compareWith(const char* nickname);
};	