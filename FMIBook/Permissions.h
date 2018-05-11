#pragma once

//ADD_MODERATOR     -  Admin
//ADD_USER		    -  Admin
//REMOVE_USER	    -  Admin
//BLOCK_USER	  	   Admin | Mod
//UNBLOCK_USER      -  Admin | Mod
//POST_IMAGE        -  Admin | Mod | User
//POST_URL          -  Admin | Mod | User
//POST_TEXT		    -  Admin | Mod | User
//REMOVE_OWN_POST   -  Admin | Mod | User
//REMOVE_ANY_POST   -  Admin | Mod
//VIEW_CERTAIN_POST -  Admin | Mod | User
//VIEW_ALL_POSTS    -  Admin | Mod | User

//0000 0000 0000 0000 0000 0000 0000 0000

#define VIEW_ALL_POSTS     0b000000000001
#define VIEW_CERTAIN_POST  0b000000000010
#define REMOVE_ANY_POST    0b000000000100
#define REMOVE_OWN_POST    0b000000001000
#define POST_TEXT          0b000000010000
#define POST_URL           0b000000100000
#define POST_IMAGE         0b000001000000
#define UNBLOCK_USER       0b000010000000
#define BLOCK_USER         0b000100000000
#define REMOVE_USER        0b001000000000
#define ADD_USER           0b010000000000
#define ADD_MODERATOR      0b100000000000

#define USER_PERMISSIONS   0b000001111011
#define MOD_PERMISSIONS    0b000111111111
#define ADMIN_PERMISSION   0b111111111111

//Default constructor grants regular User permissions
class Permissions {
private:
	int booleanVector;
public:
	Permissions();
	Permissions(const int);
	void printCurrentState();
	void blockPosting();
	void unblockPosting();

	bool canViewAllPosts();
	bool canViewCertainPost();
	bool canRemoveAnyPost();
	bool canRemoveOwnPost();
	bool canPostText();
	bool canPostUrl();
	bool canPostImage();
	bool canUnblockUser();
	bool canBlockUser();
	bool canRemoveUser();
	bool canAddUser();
	bool canAddModerator();
};
