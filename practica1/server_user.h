/*
 * server_user.h
 *
 *  Created on: 13/11/2012
 *      Author: roni
 */

#ifndef SERVER_USER_H_
#define SERVER_USER_H_

#include "soapH.h"

#define MAXFRIENDS 100

typedef struct{
	char* nick;
	char* pass;
	int online;//0 - offline 1 - online

	char* friends[MAXFRIENDS];//friends who accepted your friendship request
	char* friends_request_send[MAXFRIENDS];//friends that you've sent friendship request
	char* friends_request_pending[MAXFRIENDS];//friends who have sent friendship request to you

}User;

User* userInit(char* nick,char* pass);
void userFree(User* usr);

void setNick(User* usr,char* nick);
void setPass(User* usr,char* pass);

int addFriend(User* usr,char* friend_nick);
int removeFriend(User* usr,char* friend_nick);
int isFriend(User* usr,char *friend_nick);

int addFriendRequestSend(User* usr,char* friend_nick);
int removeFriendRequestSend(User* usr,char* friend_nick);
int isFriendRequestSend(User* usr,char* friend_nick);

int addFriendRequestPending(User* usr,char* friend_nick);
int removeFriendRequestPending(User* usr,char* friend_nick);
int isFriendRequestPending(User* usr,char* friend_nick);
int getFriendRequestPending(User* usr,char* friends[MAXFRIENDS]);

#endif /* SERVER_USER_H_ */
