#include "FMIBook.h"
#include "Permissions.h"

//May throw invalid_agrument if such user does not exist in the user list
//size_t FMIBook::getUserPosition(const char* name) {
//	for (int i = 0; i < user_list.size(); i++) {
//		if (user_list[i]->compareByName(name)) {
//			return i;
//		}
//	}
//	throw std::invalid_argument("User does not exist");
//}

FMIBook::FMIBook(Command* command) {
	if (command->getType() == QUIT) {
		throw std::logic_error("Exit");
	}

	//try {
	//size_t actor_pos = findUserPos(command->getActor());

	//}
	//catch (const std::exception&) {

	//}
}

void FMIBook::createAdministrator() {
	User* administrator = new User("Admin", 20, ADMIN_PERMISSIONS);
	FMIBook::user_list.push_back(administrator);
}


FMIBook::~FMIBook() {

}

void FMIBook::clearAllocatedMemory() {
	int numberOfUsers = FMIBook::user_list.size();
	for (int i = 0; i < numberOfUsers; i++) {
		delete FMIBook::user_list.at(i);
	}
}

size_t FMIBook::findUserPos(const char* other) {
	int numberOfUsers = FMIBook::user_list.size();
	for (int i = 0; i < numberOfUsers; i++) {
		//check for equal names
		if (FMIBook::user_list[i]->compareWith(other)) {
			return i;
		}
	}
	throw std::logic_error("No such user in database\n");
}