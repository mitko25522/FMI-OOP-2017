#pragma once
#include <iostream>

class User
{
private:
	char* name;
	uint8_t age;
public:
	User();
	User(char*);
	virtual ~User();
	virtual void whoAmI();
	virtual bool compareWith(const char*);
};


//ADD_MODERATOR   -  Admin
//ADD_USER		  -  Admin
//REMOVE_USER	  -  Admin
//BLOCK_USER      -	 Admin | Mod
//UNBLOCK_USER    -  Admin | Mod
//POST_IMAGE      -  Admin | Mod | User
//POST_URL        -  Admin | Mod | User
//POST_TEXT		  -  Admin | Mod | User
//REMOVE_OWN_POST -  Admin | Mod | User
//REMOVE_ANY_POST -  Admin | Mod
//VIEW_CERTAIN_POST       -  Admin | Mod | User
//VIEW_ALL_POSTS  -  Admin | Mod | User

//0000 0000 0000 0000 0000 0000 0000 0000