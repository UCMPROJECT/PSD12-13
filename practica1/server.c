
#include "soapH.h"
#include "ims.nsmap"

#include "server_file_admin.h"

int main(int argc, char **argv){ 


	char* nick;
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

	serverFree(luser);
	/*
  int m, s;
  struct soap soap;

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
*/
  return 0;
}

int ims__sendMessage (struct soap *soap, struct Message myMessage, int *result){

	printf ("Servidor -> user:%s - msg:%s\n", myMessage.name, myMessage.msg);
	return SOAP_OK;
}


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



