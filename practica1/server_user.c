#ifndef server_user
#define server_user

#include <string.h>
#include "server_user.h"

//
// Create a new User
//
User* userInit(char* nick,char* pass){
	User *user = (User*)malloc(sizeof(User));
	user->nick = (char*)malloc(sizeof(char*));
	strcpy (user->nick, nick);
	user->pass = (char*)malloc(sizeof(char*));
	strcpy (user->pass, pass);

	/*user->nick = nick;
	user->pass = pass;*/

	int i;
	for(i = 0;i < MAXFRIENDS;i++){
		user->friends[i] = NULL;
		user->friends_request_pending[i] = NULL;
		user->friends_request_send[i] = NULL;
	}
	user->online = 0;

	return user;
}

//
// Free the memory
//
void userFree(User* usr){
	free(usr->nick);
	*usr->nick = NULL;
	free(usr->pass);
	*usr->pass = NULL;
	free(usr);
}

//
//
//
void setNick(User* usr,char* nick){
	usr->nick = nick;
}

//
//
//
void setPass(User* usr,char* pass){
	usr->pass  = pass;
}

//
// Add a new friend to the friends list
//
int addFriend(User* usr,char* friend_nick){
	int i = 0;
	int j = -1;
	int found = 0;

	if(strcmp(usr->nick,friend_nick) == 0){
		return -1;
	}

	char* aux;
	while( i < MAXFRIENDS && found == 0){
		aux = usr->friends[i];
		if(aux != NULL){
			if(strcasecmp(aux,friend_nick) == 0){
				found = 1;
			}
		}
		else if(j == -1){
				j = i;
		}
		i++;
	}
	if(found == 0){
		usr->friends[j] = (char*)malloc(sizeof(char*));
		strcpy(usr->friends[j] , friend_nick);
		//printf("%s\n",usr->friends[j]);
	}
	return found;
}

//
//
//
int removeFriend(User* usr,char* friend_nick){
	int i = 0;
	int found = 0;
	User* aux;
	while(i < MAXFRIENDS && found == 0){
		aux = usr->friends[i];
		if(aux != NULL){
			if(strcasecmp(aux->nick,friend_nick) == 0){
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

//
//
//
int isFriend(User* usr,char *friend_nick){
	int found = 0;
	int i = 0;
	char* aux;

	while(found == 0 && i < MAXFRIENDS){
		if(usr->friends[i] != NULL){
			aux = usr->friends[i];
			if(strcasecmp(aux,friend_nick) == 0){
				found = 1;
			}
		}
		i++;
	}
	return found;
}

//
// Add a new friend to the friends_request_send list
//
int addFriendRequestSend(User* usr,char* friend_nick)
{
	int i = 0;
	int j = -1;
	int found = 0;

	if(strcmp(usr->nick,friend_nick) == 0) return -1;

	char* aux;
	while( i < MAXFRIENDS && found == 0)
	{
		aux = usr->friends_request_send[i];
		if(aux != NULL)
		{
			if(strcasecmp(aux,friend_nick) == 0){
				found = 1;
			}
		}else if(j == -1)
		{
				j = i;
		}
		i++;
	}
	if(found == 0){
		usr->friends_request_send[j] = (char*)malloc(sizeof(char*));
		strcpy(usr->friends_request_send[j] , friend_nick);
		//printf("%s\n",usr->friends[j]);
	}
	return found;
}

//
//
//
int removeFriendRequestSend(User* usr,char* friend_nick)
{
	return 0;
}

//
//
//
int isFriendRequestSend(User* usr,char* friend_nick)
{
	int found = 0;
	int i = 0;
	char* aux;

	while(found == 0 && i < MAXFRIENDS){
		if(usr->friends_request_send[i] != NULL){
			aux = usr->friends_request_send[i];
			if(strcasecmp(aux,friend_nick) == 0){
				found = 1;
			}
		}
		i++;
	}
	return found;
}

//
// Add a new friend to the friends_request_pending list
//
int addFriendRequestPending(User* usr,char* friend_nick)
{
	int i = 0;
	int j = -1;
	int found = 0;

	if(strcmp(usr->nick,friend_nick) == 0) return -1;

	char* aux;
	while( i < MAXFRIENDS && found == 0)
	{
		aux = usr->friends_request_pending[i];
		if(aux != NULL)
		{
			if(strcasecmp(aux,friend_nick) == 0){
				found = 1;
			}
		}else if(j == -1)
		{
				j = i;
		}
		i++;
	}
	if(found == 0){
		usr->friends_request_pending[j] = (char*)malloc(sizeof(char*));
		strcpy(usr->friends_request_pending[j] , friend_nick);
		//printf("%s\n",usr->friends[j]);
	}
	return found;
}

//
//
//
int removeFriendRequestPending(User* usr,char* friend_nick)
{
	return 0;
}

//
//
//
int isFriendRequestPending(User* usr,char* friend_nick)
{
	int found = 0;
	int i = 0;
	char* aux;

	while(found == 0 && i < MAXFRIENDS){
		if(usr->friends[i] != NULL){
			aux = usr->friends_request_pending[i];
			if(strcasecmp(aux,friend_nick) == 0){
				found = 1;
			}
		}
		i++;
	}
	return found;
}

//
//
//
int getFriendRequestPending(User* usr,char* friends[MAXFRIENDS])
{
	char* aux;
	int i;

	for(i = 0; i < MAXFRIENDS; i++)
	{
		aux = usr->friends_request_pending[i];

		if(aux != NULL)
		{
			friends[i] = (char*)malloc(sizeof(char*));
			strcpy(friends[i],aux);
			//friends->data[i] = aux;
			printf("%s\n",friends[i]);
		}
	}
	return 0;
}

#endif
