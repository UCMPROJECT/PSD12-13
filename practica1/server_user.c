#ifndef server_user
#define server_user

#include <string.h>
#include "server_user.h"

User* userInit(char* nick,char* pass){
	User *user;
	user->nick = nick;
	user->pass = pass;

	int i;
	for(i = 0;i < MAXFRIENDS;i++){
		user->friends[i] = NULL;
	}
	return user;
}

void userFree(User* usr){
	free(usr->nick);
	free(usr->pass);
	free(usr);
}

void setNick(User* usr,char* nick){
	usr->nick = nick;
}

void setPass(User* usr,char* pass){
	usr->pass  = pass;
}

int addFriend(User* usr,User* friend){
	int i,j = 0;
	int found = 0;
	User *aux;
	while( i < MAXFRIENDS && found == 0){
		aux = usr->friends[i];
		if(aux != NULL){
			if(strcasecmp(aux->nick,friend->nick) == 1){
				found = 1;
			}
		}else if(j == 0){
				j = i;
		}
		i++;
	}
	if(found == 0){
		usr->friends[j] = friend;
	}
	return found;
}

int removeFriend(User* usr,User* friend){
	int i = 0;
	int found = 0;
	User* aux;
	while(i < MAXFRIENDS && found == 0){
		aux = usr->friends[i];
		if(aux != NULL){
			if(strcasecmp(aux->nick,friend->nick) == 1){
				found = 1;
			}
		}
		i++;
	}
	if(found == 1){
		usr->friends[i] = NULL;
	}
	return found;
}

#endif
