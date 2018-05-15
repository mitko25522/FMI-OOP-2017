#pragma once
#include <vector>
#include "User.h"
#include "Command.h"
#include "Permissions.h"
#include "Post.h"
class FMIBook {
private:
	FMIBook();
	static std::vector<User> user_list;
	static std::vector<Post> post_list;
	static size_t findUserPos(const char*);
	static bool userExists(const char*);
	static void printInfo();
	static void addModerator(Command*);
	static void addUser(Command*);
	static void blockUser(Command*);
	static void unblockUser(Command*);
	static void removeUser(Command*);
	static void renameUser(Command*);
	static size_t getOldestUserIndex();
	static size_t getYoungestUserIndex();
	static size_t getBlockedUsersCount();
	static void listBlockedUsers();
	static void getBlockedUsersIndexes(int*);
	static void postImage(Command*);
	
public:
	FMIBook(Command*);
	~FMIBook();
	static void createAdministrator();
};