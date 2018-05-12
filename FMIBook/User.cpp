#include "User.h"

User::User() {
	std::cout << "User constructor called\n";
}

User::User(const char* name, uint8_t age, int permission_preset) : permissions(permission_preset) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1025, name);
	this->age = age;
}

User::~User() {
	std::cout << "User destructor called\n";
}

void User::printInformation() {
	std::cout << "I'm a user\n";
}

bool User::compareWith(const char* name) {
	return strcmp(name, this->name);
}