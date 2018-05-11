#include "User.h"
#include "Command.h"
#include "FMIBook.h"
#include "Permissions.h"

void permissionTests_block_unblock();

std::vector<User*> FMIBook::user_list;

int main() {
	//FMIBook::createAdministrator();

	//while (true) {
	//	char* input = new char[1024];
	//	std::cin.getline(input, 1025);
	//	Command command(input);
	//	Command* pCommand = &command;
	//	delete[] input;
	//	FMIBook fmiBook(pCommand);
	//}
	permissionTests_block_unblock();
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

}