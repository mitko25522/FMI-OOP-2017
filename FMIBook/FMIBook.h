#pragma once
#include <vector>
#include "Post.h"
#include "User.h"
#include "Command.h"
#include "Permissions.h"

class FMIBook {
private:
	FMIBook();
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
	static void printPostList();
	static void createPost(Command*);
	static size_t getLeastPostsUserPos();
	static size_t getMostPostsUserPos();
	static void printMostLeastPostsUsers();
	static void erasePost(size_t);

public:
	static std::vector<User> user_list;
	static std::vector<Post> post_list;
	FMIBook(Command*);
	~FMIBook();
	static void createAdministrator();
	static size_t findUserPos(const char*);
};