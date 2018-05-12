#include "User.h"

User::User() {
	std::cout << "User constructor called\n";
}

User::User(const char* name, int age, int permission_preset) : permissions(permission_preset) {
	//Using this makes program throw exceptions for some reason
	//int len = std::strlen(name) + 1;
	//this->name = new char[len];
	this->name = new char[1025];
	strcpy_s(this->name, 1025, name);
	this->age = age;
}

User::~User() {
	std::cout << "User destructor called\n";
}

void User::printInformation() {
	std::cout << "Permissions: ";
	switch (permissions.getCurrentPermissions()) {
	case USER_PERMISSIONS: std::cout << "USER\n"; break;
	case MOD_PERMISSIONS: std::cout << "MODERATOR\n"; break;
	case ADMIN_PERMISSIONS: std::cout << "ADMINISTRATOR\n"; break;
	}
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << this->age << std::endl << std::endl;

}

bool User::compareWith(const char* name) {
	return strcmp(name, this->name);
}