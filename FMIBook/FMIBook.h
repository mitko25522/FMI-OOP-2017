#pragma once
#include <vector>
#include "User.h"
#include "Command.h"

class FMIBook {
private:
	FMIBook();
public:
	FMIBook(Command*);
	~FMIBook();
	static std::vector<User> user_list;
	static void createAdministrator();
	static void clearAllocatedMemory();
	static size_t findUserPos(const char*);
	static bool userExists(const char*);
	static void printInfo();
	static void addModerator(Command*);
	static void addUser(Command*);
	static void blockUser(Command*);
	static void unblockUser(Command*);
	static void removeUser(Command*);
};