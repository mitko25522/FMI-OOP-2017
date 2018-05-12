#include "User.h"
#include "Command.h"
#include "FMIBook.h"
#include "Permissions.h"

void permissionTests_block_unblock();
void permissionTests_constructors();

std::vector<User*> FMIBook::user_list;

int main() {
	FMIBook::createAdministrator();


	User* user = new User("user1", 10, USER_PERMISSIONS);
	FMIBook::user_list.push_back(user);
	User* user2 = new User("user2", 17, USER_PERMISSIONS);
	FMIBook::user_list.push_back(user2);

	FMIBook::user_list[0]->printInformation();
	FMIBook::user_list[1]->printInformation();
	FMIBook::user_list[2]->printInformation();



	//while (true) {
	//	char* input = new char[1024];
	//	std::cin.getline(input, 1025);
	//	Command command(input);
	//	Command* pCommand = &command;
	//	delete[] input;
	//	//FMIBook fmiBook(pCommand);
	//}

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