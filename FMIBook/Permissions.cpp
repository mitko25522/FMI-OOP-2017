#include "Permissions.h"
#include <iostream>

Permissions::Permissions() {
	std::cout << "Basic User permissions granted.\n";
	booleanVector = 0;
	booleanVector = USER_PERMISSIONS;
}

Permissions::Permissions(const int permissions_type) {
	booleanVector = 0;
	switch (permissions_type) {
	case USER_PERMISSIONS: booleanVector = USER_PERMISSIONS; break;
	case MOD_PERMISSIONS: booleanVector = MOD_PERMISSIONS; break;
	case ADMIN_PERMISSION: booleanVector = ADMIN_PERMISSION; break;
	}
}

void Permissions::printCurrentState() {
	std::cout << "VIEW_ALL_POSTS    " << canViewAllPosts() << std::endl;
	std::cout << "VIEW_CERTAIN_POST " << canViewCertainPost() << std::endl;
	std::cout << "REMOVE_ANY_POST   " << canRemoveAnyPost() << std::endl;
	std::cout << "REMOVE_OWN_POST   " << canRemoveOwnPost() << std::endl;
	std::cout << "POST_TEXT         " << canPostText() << std::endl;
	std::cout << "POST_URL          " << canPostUrl() << std::endl;
	std::cout << "POST_IMAGE        " << canPostImage() << std::endl;
	std::cout << "UNBLOCK_USER      " << canUnblockUser() << std::endl;
	std::cout << "BLOCK_USER        " << canBlockUser() << std::endl;
	std::cout << "REMOVE_USER       " << canRemoveUser() << std::endl;
	std::cout << "ADD_USER          " << canAddUser() << std::endl;
	std::cout << "ADD_MODERATOR     " << canAddModerator() << std::endl;
}

void Permissions::blockPosting() {
	std::cout << "User has been blocked from posting.\n";
	booleanVector &= ~POST_IMAGE;
	booleanVector &= ~POST_URL;
	booleanVector &= ~POST_TEXT;
}

void Permissions::unblockPosting() {
	std::cout << "User has been unblocked from posting.\n";
	booleanVector |= POST_IMAGE;
	booleanVector |= POST_URL;
	booleanVector |= POST_TEXT;
}

bool Permissions::canViewAllPosts() {
	return booleanVector & VIEW_ALL_POSTS;
}

bool Permissions::canViewCertainPost() {
	return booleanVector & VIEW_CERTAIN_POST;
}

bool Permissions::canRemoveAnyPost() {
	return booleanVector & REMOVE_ANY_POST;
}

bool Permissions::canRemoveOwnPost() {
	return booleanVector & REMOVE_OWN_POST;
}

bool Permissions::canPostText() {
	return booleanVector & POST_TEXT;
}

bool Permissions::canPostUrl() {
	return booleanVector & POST_URL;
}

bool Permissions::canPostImage() {
	return bool(booleanVector & POST_IMAGE);
}

bool Permissions::canUnblockUser() {
	return bool(booleanVector & UNBLOCK_USER);
}

bool Permissions::canBlockUser() {
	return bool(booleanVector & BLOCK_USER);
}

bool Permissions::canRemoveUser() {
	return bool(booleanVector & REMOVE_USER);
}

bool Permissions::canAddUser() {
	return bool(booleanVector & ADD_USER);
}

bool Permissions::canAddModerator() {
	return bool(booleanVector & ADD_MODERATOR);
}