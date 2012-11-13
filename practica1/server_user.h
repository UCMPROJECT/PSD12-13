/*
 * server_user.h
 *
 *  Created on: 13/11/2012
 *      Author: roni
 */

#ifndef SERVER_USER_H_
#define SERVER_USER_H_


#define MAXFRIENDS 100

typedef struct{
	char* nick;
	char* pass;
	struct User* friends[MAXFRIENDS];
}User;

User userInit(char* nick,char* pass);
void userFree(User usr);
void setNick(User* usr,char* nick);
void setPass(User* usr,char* pass);
int addFriend(User usr,User* friend);
int removeFriend(User usr,User* friend);

#endif /* SERVER_USER_H_ */
