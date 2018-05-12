#pragma once

//PERMISSION_ADD_MODERATOR     -  Admin
//PERMISSION_ADD_USER		   -  Admin
//PERMISSION_REMOVE_USER	   -  Admin
//PERMISSION_BLOCK_USER	  	   -  Admin | Mod
//PERMISSION_UNBLOCK_USER      -  Admin | Mod
//PERMISSION_POST_IMAGE        -  Admin | Mod | User
//PERMISSION_POST_URL          -  Admin | Mod | User
//PERMISSION_POST_TEXT		   -  Admin | Mod | User
//PERMISSION_REMOVE_OWN_POST   -  Admin | Mod | User
//PERMISSION_REMOVE_ANY_POST   -  Admin | Mod
//PERMISSION_VIEW_CERTAIN_POST -  Admin | Mod | User
//PERMISSION_VIEW_ALL_POSTS    -  Admin | Mod | User

#define PERMISSION_VIEW_ALL_POSTS     0b000000000001
#define PERMISSION_VIEW_CERTAIN_POST  0b000000000010
#define PERMISSION_REMOVE_ANY_POST    0b000000000100
#define PERMISSION_REMOVE_OWN_POST    0b000000001000
#define PERMISSION_POST_TEXT          0b000000010000
#define PERMISSION_POST_URL           0b000000100000
#define PERMISSION_POST_IMAGE         0b000001000000
#define PERMISSION_UNBLOCK_USER       0b000010000000
#define PERMISSION_BLOCK_USER         0b000100000000
#define PERMISSION_REMOVE_USER        0b001000000000
#define PERMISSION_ADD_USER           0b010000000000
#define PERMISSION_ADD_MODERATOR      0b100000000000


///Predefined permission presets
#define USER_PERMISSIONS   0b000001111011
#define MOD_PERMISSIONS    0b000111111111
#define ADMIN_PERMISSIONS  0b111111111111


class Permissions {
private:
	int booleanVector;
	void setPermissions(const int permissions_preset);
public:
	Permissions();
	~Permissions();
	Permissions(const int permissions_preset);
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
