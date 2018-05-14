#include "FMIBook.h"
#include "Permissions.h"


FMIBook::FMIBook(Command* command) {
	switch (command->getType()) {
	case INVALID_COMMAND:	std::cerr << "Invalid command." << std::endl; break;
	case QUIT:				throw std::logic_error("Exit"); break; //????????
	case ADD_MODERATOR:		addModerator(command); break;
	case ADD_USER:			addUser(command); break;
	case BLOCK_USER:		blockUser(command); break;
	case UNBLOCK_USER:		unblockUser(command); break;
	case INFO:				printInfo(); break;
	case REMOVE_USER:		removeUser(command); break;
	case RENAME:			renameUser(command); break;
	}

}

void FMIBook::createAdministrator() {
	User administrator("Admin", 20, ADMIN_PERMISSIONS);
	FMIBook::user_list.push_back(administrator);
}


FMIBook::~FMIBook() {

}

size_t FMIBook::findUserPos(const char* userName) {
	if (FMIBook::userExists(userName)) {
		size_t numberOfUsers = FMIBook::user_list.size();

		for (int i = 0; i < numberOfUsers; i++) {
			if (FMIBook::user_list[i].compareWith(userName)) {
				return i;
			}
		}
	}
	else {
		throw std::logic_error("No such user in database");
	}
}

void FMIBook::printInfo() {
	size_t numberOfUsers = FMIBook::user_list.size();
	for (int i = 0; i < numberOfUsers; i++) {
		FMIBook::user_list[i].printInformationCompact();
	}
	std::cout << "Oldest user: " << FMIBook::user_list[getOldestUserIndex()].getNickname();
	std::cout << ", " << FMIBook::user_list[getOldestUserIndex()].getAge() << std::endl;
	std::cout << "Youngest user: " << FMIBook::user_list[getYoungestUserIndex()].getNickname();
	std::cout << ", " << FMIBook::user_list[getYoungestUserIndex()].getAge() << std::endl;;
	std::cout << "Blocked users: ";
	listBlockedUsers();
	std::cout << std::endl;
}

void FMIBook::addModerator(Command* command) {
	size_t actor_pos = findUserPos(command->getActor());

	if (userExists(command->getSubject())) {
		throw std::logic_error("Subject already exists in database");
	}
	if (FMIBook::user_list.at(actor_pos).getPermissions()->canAddModerator()) {
		size_t subjectAge = command->getSubjectAge();
		User newUser(command->getSubject(), subjectAge, MOD_PERMISSIONS);
		FMIBook::user_list.push_back(newUser);
		std::cout << "Moderator added to database\n";
	}
	else {
		throw std::logic_error("Actor does not have needed permissions");
	}
}

void FMIBook::addUser(Command* command) {
	size_t actor_pos = findUserPos(command->getActor());

	if (userExists(command->getSubject())) {
		throw std::logic_error("Subject already exists in database");
	}

	if (FMIBook::user_list.at(actor_pos).getPermissions()->canAddUser()) {
		size_t subjectAge = command->getSubjectAge();
		User newUser(command->getSubject(), subjectAge, USER_PERMISSIONS);
		FMIBook::user_list.push_back(newUser);
		std::cout << "User added to database\n";
	}
	else {
		throw std::logic_error("Actor does not have needed permissions");
	}
}

void FMIBook::blockUser(Command* command) {
	size_t actor_pos = findUserPos(command->getActor());
	size_t subject_pos = findUserPos(command->getSubject());

	if (FMIBook::user_list.at(actor_pos).getPermissions()->canBlockUser()) {
		if (FMIBook::user_list.at(actor_pos).getPermissions()->canBlockUser()) {
			FMIBook::user_list.at(subject_pos).getPermissions()->blockPosting();
		}
	}
	else {
		throw std::logic_error("Actor does not have needed permissions");
	}
}

void FMIBook::unblockUser(Command* command) {
	size_t actor_pos = findUserPos(command->getActor());
	size_t subject_pos = findUserPos(command->getSubject());

	if (FMIBook::user_list.at(actor_pos).getPermissions()->canUnblockUser()) {
		if (FMIBook::user_list.at(actor_pos).getPermissions()->canUnblockUser()) {
			FMIBook::user_list.at(subject_pos).getPermissions()->unblockPosting();
		}
	}
	else {
		throw std::logic_error("Actor does not have needed permissions");
	}
}

bool FMIBook::userExists(const char* userName) {
	size_t numberOfUsers = FMIBook::user_list.size();

	bool doesExist = false;
	for (int i = 0; i < numberOfUsers; i++) {
		if (FMIBook::user_list[i].compareWith(userName)) {
			doesExist = true;
			break;
		}
	}

	return doesExist;
}

void FMIBook::removeUser(Command* command) {
	size_t actor_pos = findUserPos(command->getActor());
	size_t subject_pos = findUserPos(command->getSubject());

	if (FMIBook::user_list[actor_pos].getPermissions()->canRemoveUser()) {
		FMIBook::user_list.erase(FMIBook::user_list.begin() + subject_pos);
		std::cout << "User has been removed";
	}
	else {
		throw std::logic_error("Actor does not have needed permissions");
	}
}

void FMIBook::renameUser(Command* command) {
	size_t actor_pos = findUserPos(command->getActor());

	char* oldName = FMIBook::user_list.at(actor_pos).getNickname();
	char* newName = command->getSubject();

	if (userExists(newName)) {
		throw std::logic_error("New name already exists in database");
	}

	for (int i = 0; newName[i] != '\0'; i++) {
		oldName[i] = newName[i];
		if (newName[i + 1] == '\0') {
			oldName[i + 1] = '\0';
		}
	}

	std::cout << "User has been renamed";
}

size_t FMIBook::getOldestUserIndex() {
	size_t numberOfUsers = FMIBook::user_list.size();
	size_t currentOldestIndex = 0;

	for (int i = 0; i < numberOfUsers; i++) {
		if (FMIBook::user_list.at(i).getAge() > FMIBook::user_list.at(currentOldestIndex).getAge()) {
			currentOldestIndex = i;
		}
	}

	return currentOldestIndex;
}

size_t FMIBook::getYoungestUserIndex() {
	size_t numberOfUsers = FMIBook::user_list.size();
	size_t currentOldestIndex = 0;

	for (int i = 0; i < numberOfUsers; i++) {
		if (FMIBook::user_list.at(i).getAge() < FMIBook::user_list.at(currentOldestIndex).getAge()) {
			currentOldestIndex = i;
		}
	}

	return currentOldestIndex;
}

size_t FMIBook::getBlockedUsersCount() {
	size_t numberOfUsers = FMIBook::user_list.size();
	size_t blockedUsersCount = 0;

	for (int i = 0; i < numberOfUsers; i++) {
		if (FMIBook::user_list.at(i).getPermissions()->isBlockedFromPosting()) {
			blockedUsersCount++;
		}
	}

	return blockedUsersCount;
}

void FMIBook::listBlockedUsers() {
	size_t blockedUsersCount = getBlockedUsersCount();

	if (blockedUsersCount == 0) {
		std::cout << "N/A" << std::endl;
	}
	else if (blockedUsersCount > 0) {
		int* blockedUsersIndexes = new int[blockedUsersCount];
		getBlockedUsersIndexes(blockedUsersIndexes);

		for (int i = 0; i < blockedUsersCount; i++) {
			std::cout << FMIBook::user_list.at(blockedUsersIndexes[i]).getNickname();
			if (i + 1 != blockedUsersCount) {
				std::cout << ", ";
			}
		}

		delete[] blockedUsersIndexes;
	}
}

void FMIBook::getBlockedUsersIndexes(int* blockedUsersIndexesArray) {
	size_t currentArrayIndex = 0;
	size_t numberOfUsers = FMIBook::user_list.size();

	for (int i = 0; i < numberOfUsers; i++) {
		if (FMIBook::user_list.at(i).getPermissions()->isBlockedFromPosting()) {
			blockedUsersIndexesArray[currentArrayIndex] = i;
			currentArrayIndex++;
		}
	}
}