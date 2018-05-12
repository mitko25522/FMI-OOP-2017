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
	static std::vector<User*> user_list;
	static void createAdministrator();
	static void clearAllocatedMemory();
};