#include "User.h"
#include "Command.h"
#include "FMIBook.h"
#include "Permissions.h"

void permissionTests_block_unblock();
void permissionTests_constructors();

std::vector<User> FMIBook::user_list;

//TODO:
//Add rename command and functions
//Add posts system
//Add youngest & oldest to printInfo
//Add option to input admin data or use default ones

//Known issues
//Sometimes crashes when removing a user

int main() {
	FMIBook::createAdministrator();

	while (true) {
		char* input = new char[1024];
		std::cout << "Enter command: ";
		std::cin.getline(input, 1025);
		Command command(input);
		delete[] input;
		try {
			FMIBook fmiBook(&command);
		}
		catch (const std::exception& e) {
			if (strcmp(e.what(), "Exit") == 0) {
				//FMIBook::clearAllocatedMemory();
				return 0;
			}
			std::cout << e.what() << std::endl;
			//FMIBook::clearAllocatedMemory();
		}
		std::cout << std::endl;
	}

	FMIBook::clearAllocatedMemory();
	return 0;
}

void permissionTests_block_unblock() {
	Permissions perm;
	perm.printCurrentState();
	std::cout << std::endl;

	perm.blockPosting();
	perm.printCurrentState();
	std::cout << std::endl;

	perm.unblockPosting();
	perm.printCurrentState();
	std::cout << std::endl;
}

void permissionTests_constructors() {
	Permissions perm(MOD_PERMISSIONS);
	perm.printCurrentState();
}