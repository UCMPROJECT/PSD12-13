#include <string.h>

#include "server_user.c"

typedef struct{
	int numUser;
	User *listU;
}LUser;

int serverInit(){
	return 0;
}

User* loadUsers(){
	User* usr = malloc(User);
	LUser *user;
	user->listU[2]->nick = "hola";
}

loadFriends
