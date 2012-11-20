
#include "soapH.h"
#include "ims.nsmap"

#include "server_file_admin.h"

#define DEBUG_MODE 1

LUser *luser;

int main(int argc, char **argv){ 


	/*char* nick;
	char* pass;
	printf("Nombre\n");
	nick = malloc(256*sizeof(char));
	scanf("%s",nick);

	printf("Contraseña\n");
	pass = malloc(256*sizeof(char));
	scanf("%s",pass);


	LUser *luser = (LUser*)malloc(sizeof(LUser));
	serverInit(luser);
	addUsers(luser,nick,pass);
	User *a = luser->listU[0];
	char *nombre="oscar";
	char *pass2="tetas";
	addUsers(luser,nombre,pass2);
	User *b = luser->listU[1];

	addFriend(a,b);
	removeFriend(a,b);
	removeUser(luser,"oscar");
	removeUser(luser,nick);

	serverFree(luser);*/

	int m, s;
	struct soap soap;

	luser = (LUser*)malloc(sizeof(LUser));
	serverInit(luser);

	addUsers(luser,"asd","asd");
	addUsers(luser,"asd1","asd1");
	addUsers(luser,"asd2","asd2");
	addFriendRequestSend(luser->listU[1],"asd");
	addFriendRequestSend(luser->listU[2],"asd");
	addFriendRequestPending(luser->listU[0],"asd1");
	addFriendRequestPending(luser->listU[0],"asd2");

  	if (argc < 2) {
    	printf("Usage: %s <port>\n",argv[0]); 
		exit(-1); 
  	}

	// Init environment
  	soap_init(&soap);

	// Bind to the specified port	
	m = soap_bind(&soap, NULL, atoi(argv[1]), 100);

	// Check result of binding		
	if (m < 0) {
  		soap_print_fault(&soap, stderr); exit(-1); 
	}

	// Listen to next connection
	while (1) { 
		// accept
	  	s = soap_accept(&soap);

	  	if (s < 0) {
			soap_print_fault(&soap, stderr); exit(-1);
	  	}

		// Execute invoked operation
	  	soap_serve(&soap);

		// Clean up!
	  	soap_end(&soap);
	}
	serverFree(luser);
  return 0;
}

//
//
//
int ims__addUser(struct soap *soap, char* nick, char* pass, int *res)
{
	*res = addUsers(luser,nick,pass);
	if(DEBUG_MODE && *res == 0){
		printf("Añadido: %s %s\n",luser->listU[luser->numUser-1]->nick,luser->listU[luser->numUser-1]->pass);
	}

	return SOAP_OK;
}

//
//
//
int ims__userLogin(struct soap *soap, char* nick, char* pass, int *result){
	*result = userLogin(luser,nick,pass);

	if(DEBUG_MODE && *result == 0){
		printf("Se ha logueado: %s\n",nick);
	}
	return SOAP_OK;
}

//
//
//
int ims__addFriend(struct soap *soap, char* user ,char* friend_nick, int *result){
	User *usr = getUser(luser,user);
	User *friend = getUser(luser,friend_nick);

	if(friend == NULL){
		*result = -3;
	}
	else if(usr->online == 1){
		*result = addFriend(usr,friend_nick);
		if(DEBUG_MODE && friend != NULL && *result == 0) printf("Añadido amigo %s al usuario %s\n",friend->nick,usr->nick);
	}
	else{
		*result = -2;
	}

	return SOAP_OK;
}

//
//
//
int ims__sendFriendshipRequest(struct soap *soap, char* user ,char* friend_nick, int *result)
{
	User *usr = getUser(luser,user);
	User *friend = getUser(luser,friend_nick);

	if(friend == NULL)
	{
		*result = -3;
	}else if(usr->online == 1)
	{
		*result = isFriend(usr,friend_nick);
		if(*result == 1){
			*result = -4;
			return SOAP_OK;
		}
		*result = addFriendRequestSend(usr,friend_nick);
		if(*result == 0)
		{
			*result = addFriendRequestPending(friend,user);
			if(DEBUG_MODE && friend != NULL && *result == 0) printf("%s envia peticion de amistad a %s\n",usr->nick,friend->nick);
		}
	}else
	{
		*result = -2;
	}

	return SOAP_OK;
}

//
//
//
int ims__getFriendshipRequests(struct soap *soap, char* user,Char_vector *friends)
{
	User *usr = getUser(luser,user);

	if(usr->online == 1)
	{
		getFriendRequestsPending(usr,friends->data);

		//printf("%s\n",friends->data[0]);
		if(DEBUG_MODE)
			printf("%s quiere su lista de peticiones pendientes\n",usr->nick);
	}

	return SOAP_OK;
}

//
//
//
int ims__haveFriendshipRequest(struct soap *soap, char* user,int *result)
{
	User *usr = getUser(luser,user);

	if(usr->online == 1)
	{
		*result = usr->numPending;
		if(DEBUG_MODE) printf("Numero de peticiones %d\n",*result);
	}

	return SOAP_OK;
}

//
//
//
int ims__getFriendshipRequest(struct soap *soap, char* user,String* friend_nick)
{
	User *usr = getUser(luser,user);
	if(usr->online == 1)
	{
		//int found =
		//char* aux = (char*)malloc(sizeof(char*));
		getFriendRequestPending(usr,&friend_nick->str);
		//friend_nick->name = aux;
		if(DEBUG_MODE) printf("Peticion %s\n",friend_nick->str);
		//*friend_nick = *aux;
		//printf("Primera peticion %s\n",friend_nick);
	}

	return SOAP_OK;
}

//
//
//
int ims__acceptFriendshipRequest(struct soap *soap, char* user ,char* friend_nick, int *result)
{
	User *usr = getUser(luser,user);
	User *friend = getUser(luser,friend_nick);

	if(usr->online == 1)
	{
		int found = removeFriendRequestPending(usr,friend_nick);
		if(found == 1)
		{
			found = removeFriendRequestSend(friend,user);
			if(found == 1)
			{
				addFriend(usr,friend_nick);
				addFriend(friend,user);
				*result = usr->numPending;
				if(DEBUG_MODE) printf("%s y %s ahora son amigos\n",usr->nick,friend->nick);
			}
		}
	}
	return SOAP_OK;
}

//
//
//
int ims__rejectFriendshipRequest(struct soap *soap, char* user ,char* friend_nick, int *result)
{
	User *usr = getUser(luser,user);
	User *friend = getUser(luser,friend_nick);

	if(usr->online == 1)
	{
		int found = removeFriendRequestPending(usr,friend_nick);
		if(found == 1)
		{
			found = removeFriendRequestSend(friend,user);
			if(found == 1)
			{
				*result = usr->numPending;
				if(DEBUG_MODE) printf("%s y %s ahora NO son amigos\n",usr->nick,friend->nick);
			}
		}
	}

	return SOAP_OK;
}

//
//
//
int ims__getFriends(struct soap *soap, char* user ,Char_vector *friends)
{
	User *usr = getUser(luser,user);

	if(usr->online == 1)
	{
		getFriends(usr,friends->data);

		//printf("%s\n",friends->data[0]);
		if(DEBUG_MODE)
			printf("%s quiere su lista de amigos\n",usr->nick);
	}

	return SOAP_OK;
}

//
//
//
int ims__haveFriends(struct soap *soap, char* user,int *result)
{
	User *usr = getUser(luser,user);

	if(usr->online == 1)
	{
		*result = usr->numFriends;
		if(DEBUG_MODE) printf("Numero de amigos %d\n",*result);
	}

	return SOAP_OK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ims__sendMessage (struct soap *soap, struct Message myMessage, int *result){
	/*char* data[2];
	char *a;
	data = myMessage.msg;*/
	//char* a = data[0];
	printf ("Servidor -> user:%s - msg:%s\n", myMessage.name, myMessage.msg);
	return SOAP_OK;
}

/*int ims__sendMessage (struct soap *soap, struct Message myMessage, int *result){

	printf ("enviando mensaje");
	return SOAP_OK;
}*/


int ims__receiveMessage (struct soap *soap, struct Message *myMessage){

	// Alloc memory, init to zero and copy the message
	myMessage->msg = (xsd__string) malloc (IMS_MAX_MSG_SIZE);
	bzero (myMessage->msg, IMS_MAX_MSG_SIZE);
	strcpy (myMessage->msg, "This is a message from the server!");

	myMessage->name = (xsd__string) malloc (IMS_MAX_MSG_SIZE);
	bzero (myMessage->name, IMS_MAX_MSG_SIZE);
	strcpy (myMessage->name, "Server");	

	return SOAP_OK;
}
