
#include <string.h>

#include "server_file_admin.h"


int serverInit(LUser luser){
	luser.numUser = 0;
	return 0;
}

int addUsers(LUser luser,char* nick,char* pass){
	if(luser.numUser >= MAXUSER){
		return -1;
	}
	int found = 0;
	int i = 0;
	while(i < luser.numUser && found == 0){
		if(strcmp(nick,luser.listU[i].nick) == 0){
			found = 1;
		}
	}
	if(found == 1){
		return -2;
	}
	User usr = userInit(nick,pass);
	luser.listU[luser.numUser] = usr;
	luser.numUser++;
	return 0;
}

int removeUser(LUser luser,char* nick){
	int i;
	int found = 0;
	for(i = 0;i < luser.numUser;i++){
		if(found == 0){
			if(strcmp(nick,luser.listU[i].nick) == 0){
				found = 1;
				luser.listU[i] = luser.listU[i+1];
			}
		}
		else{
			luser.listU[i] = luser.listU[i+1];
		}
	}
	luser.numUser--;
	return 0;

}

