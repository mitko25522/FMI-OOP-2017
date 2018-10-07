#pragma once
#include <vector>
#include "Post.h"
#include "User.h"
#include "Command.h"
#include "Permissions.h"

class FMIBook {
private:
	FMIBook();
	void printInfo();
	void addModerator(Command*);
	void addUser(Command*);
	void blockUser(Command*);
	void unblockUser(Command*);
	void removeUser(Command*);
	void renameUser(Command*);
	size_t getOldestUserIndex();
	size_t getYoungestUserIndex();
	size_t getBlockedUsersCount();
	void listBlockedUsers();
	void getBlockedUsersIndexes(int*);
	void printPostList();
	void createPost(Command*);
	size_t getLeastPostsUserPos();
	size_t getMostPostsUserPos();
	void printMostLeastPostsUsers();
	void removePost(Command*);
	void removeAllPosts(const char*);
	size_t findPosterPos(size_t);


public:
	static std::vector<User> user_list;
	static std::vector<Post> post_list;
	FMIBook(Command*);
	~FMIBook();
	static void createAdministrator();
	static bool userExists(const char*);
	static size_t findUserPos(const char*);
};