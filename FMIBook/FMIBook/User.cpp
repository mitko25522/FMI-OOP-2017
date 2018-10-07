#include "User.h"
#include "FMIBook.h"

User::User() {
	//std::cout << "		User constructor called\n";
}

User::User(const char* nickname, int age, int permission_preset) : permissions(permission_preset) {
	//Using this makes program throw exceptions for some reason
	//int len = std::strlen(nickname) + 1;
	//this->nickname = new char[len];
	strcpy_s(this->nickname, 1024, nickname);
	this->age = age;
}

User::~User() {
	//std::cout << "		User destructor called\n";
}

void User::printInformation() {
	std::cout << "Permissions: ";

	switch (permissions.getCurrentPermissions()) {
	case USER_PERMISSIONS: std::cout << "USER\n"; break;
	case MOD_PERMISSIONS: std::cout << "MODERATOR\n"; break;
	case ADMIN_PERMISSIONS: std::cout << "ADMINISTRATOR\n"; break;
	}

	std::cout << "Name: " << nickname << std::endl;
	std::cout << "Age: " << this->age << std::endl << std::endl;
}

void User::printInformationCompact() {
	std::cout << "Name: " << this->nickname << " | ";
	std::cout << "Age: "<< this->age << " | ";
	std::cout << "Permissions: ";

	switch (permissions.getCurrentPermissions()) {
	case USER_PERMISSIONS: std::cout << "USER | "; break;
	case MOD_PERMISSIONS: std::cout << "MODERATOR | "; break;
	case ADMIN_PERMISSIONS: std::cout << "ADMINISTRATOR | "; break;
	}

	std::cout << "Blocked: " << (this->getPermissions()->isBlockedFromPosting() ? "Yes | " : "No | ");
	std::cout << "Posts: "<< getPostsCount();
	std::cout << std::endl;
}


Permissions* User::getPermissions() {
	return &permissions;
}

char * User::getNickname() {
	return nickname;
}

int User::getAge() {
	return this->age;
}

User::User(const User& other) {
	this->permissions = other.permissions;

	for (int i = 0; other.nickname[i] != '\0'; i++) {
		this->nickname[i] = other.nickname[i];
		if (other.nickname[i + 1] == '\0') {
			this->nickname[i + 1] = '\0';
		}
	}

	this->age = other.age;
}

bool User::compareWith(const char* nickname) {
	return strcmp(nickname, this->nickname) == 0;
}

size_t User::getPostsCount() {
	size_t totalPostsCount = FMIBook::post_list.size();
	size_t currentUserPostCount = 0;

	for (int i = 0; i < totalPostsCount; i++) {
		if (FMIBook::post_list.at(i).isPoster(nickname)) {
			currentUserPostCount++;
		}
	}

	return currentUserPostCount;
}