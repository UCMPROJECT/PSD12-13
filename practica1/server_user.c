#include <string.h>

typedef struct{
	char* nick;
	char* pass;
	int numFriends;
	char** friends;
}User;

User* userInit(char* nick,char* pass,int numFriends,char** friends){
	User *usr;
	usr->nick = nick;
	usr->pass = pass;
	usr->numFriends = numFriends;
	usr->friends = friends;
	return usr;
}

void userFree(User *usr){
	free(usr->nick);
	free(usr->pass);
	int i ;
	for (i = 0; i < usr->numFriends; i++) {
		free(usr->friends[i]);
	}
	free(usr->friends);
}

void setNick(User* usr,char* nick){
	usr->nick = nick;
}

void setPass(User* usr,char* pass){
	usr->pass  = pass;
}

int addFriend(User* usr,char* name){
	int i = 0;
	int found = 0;
	while(i < usr->numFriends && found != 1){
		if(strcasecmp(usr->friends[i],name) == 1){
			found = 1;
		}
	}
	if(found == 0){
		usr->friends[usr->numFriends] = name;
		usr->numFriends++;
	}
	return found;
}

int removeFriend(User* usr,char* name){
	int i = 0;
	int found = 0;
	while(i < usr->numFriends && found != 1){
		if(strcasecmp(usr->friends[i],name) == 1){
			found = 1;
		}
	}
	if(found == 1){
		int j;
		for(j = i; j < usr->numFriends;j++){
			usr->friends[j] = usr->friends[j+1];
		}
		free(usr->friends[j]);
		usr->numFriends--;
	}
	return found;
}
