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

void FMIBook::createAdministrator() {
	User administrator("Admin", 20, ADMIN_PERMISSIONS);
	FMIBook::user_list.push_back(&administrator);
}