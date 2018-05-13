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
	}

}

void FMIBook::createAdministrator() {
	User administrator("Admin", 20, ADMIN_PERMISSIONS);
	FMIBook::user_list.push_back(administrator);
}


FMIBook::~FMIBook() {

}

void FMIBook::clearAllocatedMemory() {
	/*int numberOfUsers = FMIBook::user_list.size();

	for (int i = 0; i < numberOfUsers; i++) {
		delete FMIBook::user_list.at(i);
	}*/
}

size_t FMIBook::findUserPos(const char* userName) {
	if (FMIBook::userExists(userName)) {
		int numberOfUsers = FMIBook::user_list.size();

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
	int numberOfUsers = FMIBook::user_list.size();

	for (int i = 0; i < numberOfUsers; i++) {
		FMIBook::user_list[i].printInformationCompact();
	}
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
		throw std::logic_error("Actor does not have needed permissions.");
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
		throw std::logic_error("Actor does not have needed permissions.");
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
		throw std::logic_error("Actor does not have needed permissions.");
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
		throw std::logic_error("Actor does not have needed permissions.");
	}
}

bool FMIBook::userExists(const char* userName) {
	int numberOfUsers = FMIBook::user_list.size();

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
		throw std::logic_error("Actor does not have needed permissions.");
	}
}