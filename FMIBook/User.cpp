#include "User.h"

User::User() {
	std::cout << "User constructor called\n";
}

User::User(char*) {

}

User::~User() {
	std::cout << "User destructor called\n";
}

void User::whoAmI() {
	std::cout << "I'm a user\n";
}

bool User::compareWith(const char* name) {
	return strcmp(name, this->name);
}