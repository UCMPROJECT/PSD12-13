#include "soapH.h"
#include "ims.nsmap"
#include <string.h>

#define DEBUG_MODE 1



int main(int argc, char **argv){

  struct soap soap;
  struct Message myMsgA, myMsgB;
  char *serverURL;
  char *msg;
  int res;

	// Usage
  	if (argc != 3) {
    	   printf("Usage: %s http://server:port message\n",argv[0]);
    	   exit(0);
  	}

	// Init gSOAP environment
  	soap_init(&soap);
  	
	// Obtain server address
	serverURL = argv[1];
	
	// Obtain message
	msg = argv[2];
	
	// Debug?
	if (DEBUG_MODE){
		printf ("Server: %s\n", serverURL);
		printf ("Message: %s\n", msg);
	}

	//Init the message read from client-side
	
		// Alloc memory, init to zero and copy the message
		myMsgA.msg = (xsd__string) malloc (IMS_MAX_MSG_SIZE);
		bzero (myMsgA.msg, IMS_MAX_MSG_SIZE);
		strcpy (myMsgA.msg, msg);

		// Alloc memory, init to zero and copy the name
		myMsgA.name = (xsd__string) malloc (IMS_MAX_MSG_SIZE);
		bzero (myMsgA.name, IMS_MAX_MSG_SIZE);
		strcpy (myMsgA.name, "Client");

	// Send this message to the server
    soap_call_ims__sendMessage (&soap, serverURL, "", myMsgA, &res);
	  		
 	// Check for errors...
  	if (soap.error) {
      	soap_print_fault(&soap, stderr); 
		exit(1);
  	}


	// Receive a message from the server
    soap_call_ims__receiveMessage (&soap, serverURL, "", &myMsgB);

	// Check for errors...
  	if (soap.error) {
      	soap_print_fault(&soap, stderr); 
		exit(1);
  	}
	else
		printf ("Server message -> user:%s - msg:%s\n", myMsgB.name, myMsgB.msg);    

  	
	// Clean the environment
	soap_destroy(&soap);
  	soap_end(&soap);
  	soap_done(&soap);

  return 0;
}

void menuLogin(){
	printf("1.-Log in.\n");
	printf("1.-Darse de alta.\n");

	int op;
	scanf("%d",op);

	switch (op){
	case 1:

		break;
	case 2:
		break;
	default:
		printf("Opcion no valida.\n");
		break;
	}
}
void menuHome(){
	printf("1.-Añadir amigo.\n");
	printf("2.-Enviar mensaje.\n");
	printf("3.-Leer mensaje.\n");
	printf("0.-Salir.\n");

	int op;
	scanf("%d",op);

	switch (op){
	case 1:

		break;
	case 2:
		break;
	case 3:
		break;
	default:
		printf("Opcion no valida\n");
		break;
	}

}
void newUser(){

	char* nick,pass;
	nick = "";
	pass = "";

	printf("Nombre\n");
	scanf("%s",nick);
	printf("Contraseña\n");
	scanf("%s",pass);

}

