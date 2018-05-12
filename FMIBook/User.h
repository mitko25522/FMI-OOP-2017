#pragma once
#include "Permissions.h"
#include <iostream>

class User {
private:
	Permissions permissions;
	char* name;
	uint8_t age;

	User();
public:
	User(const char*, uint8_t, int);
	virtual ~User();
	virtual void printInformation();
	virtual bool compareWith(const char*);
};