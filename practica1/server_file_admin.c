
#include <string.h>

#include "server_file_admin.h"


int serverInit(LUser* luser){
	LUser aux = *luser;
	aux.numUser = 0;
	luser = &aux;
	return 0;
}

int addUsers(LUser* luser,char* nick,char* pass){
	LUser aux = *luser;
	if(aux.numUser >= MAXUSER){
		return -1;
	}
	int found = 0;
	int i = 0;
	while(i < aux.numUser && found == 0){
		if(strcmp(nick,aux.listU[i].nick) == 0){
			found = 1;
		}
	}
	if(found == 1){
		return -2;
	}
	User usr = userInit(nick,pass);
	aux.listU[aux.numUser] = usr;
	aux.numUser++;
	luser = &aux;
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

