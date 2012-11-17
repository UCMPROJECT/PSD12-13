/*
 * server_file_admin.h
 *
 *  Created on: 13/11/2012
 *      Author: roni
 */

#ifndef SERVER_FILE_ADMIN_H_
#define SERVER_FILE_ADMIN_H_

#include "server_user.h"
#define  MAXUSER 100

typedef struct{
	int numUser;
	User listU[MAXUSER];
}LUser;

int serverInit(LUser* luser);
int addUsers(LUser* luser,char* nick,char* pass);
int removeUser(LUser luser,char* nick);

#endif /* SERVER_FILE_ADMIN_H_ */
