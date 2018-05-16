#include "User.h"
#include "Command.h"
#include "FMIBook.h"
#include "Permissions.h"

void permissionTests_block_unblock();
void permissionTests_constructors();

std::vector<User> FMIBook::user_list;
std::vector<Post> FMIBook::post_list;

//TODO:
//Add option to input admin data or use default ones
//Remove post (erase from vector)
//Add enumeration when printing posts list

//Known issues
//Sometimes crashes when removing a user
//Sometimes crashes when blocking a user
//Sometimes crashes when renaming a user (starting to suspect reason is in commands)

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
				return 0;
			}
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

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