#include "Permissions.h"
#include <iostream>

//Default constructor sets permissions to basic user. 
Permissions::Permissions() {
	booleanVector = 0;
	std::cout << "Basic User permissions granted.\n";
	booleanVector = USER_PERMISSIONS;
}

//Use one of the permisson presets:
//        -USER_PERMISSIONS 
//        -MOD_PERMISSIONS  
//        -ADMIN_PERMISSIONS
Permissions::Permissions(const int permissions_preset) {
	booleanVector = 0;
	switch (permissions_preset) {
	case USER_PERMISSIONS: setPermissions(USER_PERMISSIONS); break;
	case MOD_PERMISSIONS: setPermissions(MOD_PERMISSIONS); break;
	case ADMIN_PERMISSIONS: setPermissions(ADMIN_PERMISSIONS); break;
	default: 
		std::cerr << "Invalid permissions request. Basic User permissions granted." << std::endl;
		booleanVector = USER_PERMISSIONS;
	}
}

Permissions::~Permissions() {
	std::cout << "Permissions destructor called.\n";
}

void Permissions::setPermissions(const int permissions_preset) {
	if (permissions_preset == USER_PERMISSIONS) {
		std::cout << "Basic user permissions granted." << std::endl;
		booleanVector = USER_PERMISSIONS;
	}
	else if (permissions_preset == MOD_PERMISSIONS) {
		std::cout << "Moderator permissions granted." << std::endl;
		booleanVector = MOD_PERMISSIONS;
	}
	else if (permissions_preset == ADMIN_PERMISSIONS) {
		std::cout << "Administrator permissions granted." << std::endl;
		booleanVector = ADMIN_PERMISSIONS;
	}
}

void Permissions::printCurrentState() {
	std::cout << "PERMISSION_VIEW_ALL_POSTS    " << canViewAllPosts() << std::endl;
	std::cout << "PERMISSION_VIEW_CERTAIN_POST " << canViewCertainPost() << std::endl;
	std::cout << "PERMISSION_REMOVE_ANY_POST   " << canRemoveAnyPost() << std::endl;
	std::cout << "PERMISSION_REMOVE_OWN_POST   " << canRemoveOwnPost() << std::endl;
	std::cout << "PERMISSION_POST_TEXT         " << canPostText() << std::endl;
	std::cout << "PERMISSION_POST_URL          " << canPostUrl() << std::endl;
	std::cout << "PERMISSION_POST_IMAGE        " << canPostImage() << std::endl;
	std::cout << "PERMISSION_UNBLOCK_USER      " << canUnblockUser() << std::endl;
	std::cout << "PERMISSION_BLOCK_USER        " << canBlockUser() << std::endl;
	std::cout << "PERMISSION_REMOVE_USER       " << canRemoveUser() << std::endl;
	std::cout << "PERMISSION_ADD_USER          " << canAddUser() << std::endl;
	std::cout << "PERMISSION_ADD_MODERATOR     " << canAddModerator() << std::endl;
}

void Permissions::blockPosting() {
	std::cout << "User has been blocked from posting.\n";
	booleanVector &= ~PERMISSION_POST_IMAGE;
	booleanVector &= ~PERMISSION_POST_URL;
	booleanVector &= ~PERMISSION_POST_TEXT;
}

void Permissions::unblockPosting() {
	std::cout << "User has been unblocked from posting.\n";
	booleanVector |= PERMISSION_POST_IMAGE;
	booleanVector |= PERMISSION_POST_URL;
	booleanVector |= PERMISSION_POST_TEXT;
}

bool Permissions::canViewAllPosts() {
	return booleanVector & PERMISSION_VIEW_ALL_POSTS;
}

bool Permissions::canViewCertainPost() {
	return booleanVector & PERMISSION_VIEW_CERTAIN_POST;
}

bool Permissions::canRemoveAnyPost() {
	return booleanVector & PERMISSION_REMOVE_ANY_POST;
}

bool Permissions::canRemoveOwnPost() {
	return booleanVector & PERMISSION_REMOVE_OWN_POST;
}

bool Permissions::canPostText() {
	return booleanVector & PERMISSION_POST_TEXT;
}

bool Permissions::canPostUrl() {
	return booleanVector & PERMISSION_POST_URL;
}

bool Permissions::canPostImage() {
	return booleanVector & PERMISSION_POST_IMAGE;
}

bool Permissions::canUnblockUser() {
	return booleanVector & PERMISSION_UNBLOCK_USER;
}

bool Permissions::canBlockUser() {
	return booleanVector & PERMISSION_BLOCK_USER;
}

bool Permissions::canRemoveUser() {
	return booleanVector & PERMISSION_REMOVE_USER;
}

bool Permissions::canAddUser() {
	return booleanVector & PERMISSION_ADD_USER;
}

bool Permissions::canAddModerator() {
	return booleanVector & PERMISSION_ADD_MODERATOR;
}