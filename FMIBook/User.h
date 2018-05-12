#pragma once
#include "Permissions.h"
#include <iostream>

class User {
private:
	Permissions permissions;
	char* name;
	int age;

	User();
public:
	User(const char*, int, int);
	~User();
	void printInformation();
	bool compareWith(const char*);
};	