#include "soapH.h"
#include "ims.nsmap"
#include <string.h>
#include <stdlib.h>

#define DEBUG_MODE 1
#define MAXFRIENDS 100

char *user;


int main(int argc, char **argv){

	struct soap soap;
	struct Message myMsgA, myMsgB;
	char *serverURL;
	int res;

	printf("Usage: %s http://server:port message\n",argv[0]);

	// Usage
  	if (argc != 2) {
    	   printf("Usage: %s http://server:port message\n",argv[0]);
    	   exit(0);
  	}

	// Init gSOAP environment
  	soap_init(&soap);

	// Obtain server address
	serverURL = argv[1];

	// Obtain message
	//msg = argv[2];
	
	// Debug?
	if (DEBUG_MODE){
		printf ("Server: %s\n", serverURL);
	}

	menuLogin(soap,serverURL);


	//Init the message read from client-side

	// Alloc memory, init to zero and copy the message
	/*myMsgA.msg = (xsd__string) malloc (IMS_MAX_MSG_SIZE);
	bzero (myMsgA.msg, IMS_MAX_MSG_SIZE);
	strcpy (myMsgA.msg, msg);

	// Alloc memory, init to zero and copy the name
	myMsgA.name = (xsd__string) malloc (IMS_MAX_MSG_SIZE);
	bzero (myMsgA.name, IMS_MAX_MSG_SIZE);
	strcpy (myMsgA.name, "Client");



	// Send this message to the server
    soap_call_ims__addUser (&soap, serverURL, "", myMsgA, &res);

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

  	*/
	// Clean the environment
	soap_destroy(&soap);
  	soap_end(&soap);
  	soap_done(&soap);

  return 0;
}

int menuLogin(struct soap soap,char *serverURL){
	int op = -1;
	int res = -1;

	while(op != 0 && res != 0){
		//system("clear");
		printf("1.-Log in.\n");
		printf("2.-Darse de alta.\n");
		printf("0.-Salir.\n");

		scanf("%d",&op);

		switch (op){
		case 1:
			res = login(soap,serverURL);
			if(res == 0){
				menuHome(soap,serverURL);
			}
			break;
		case 2:
			addNewUser(soap,serverURL);
			op = -1;
			break;
		case 0:
			break;
		default:
			printf("Opcion no valida.\n");
			break;
		}
	}

	return res;
}
void menuHome(struct soap soap,char *serverURL){
	int op=-1;
	while(op != 0){
		//system("clear");
		printf("2.-Enviar mensaje.\n");
		printf("3.-Leer mensaje.\n");
		printf("4.-Enviar peticion de amistad\n");
		printf("5.-Ver peticiones de amistad\n");
		printf("6.-Aceptar peticion de amistad\n");
		printf("7.-Ver lista de amigos\n");
		printf("0.-Salir.\n");

		scanf("%d",&op);

		switch (op){
		case 1:
			addNewFriend(soap,serverURL);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			sendFriendRequest(soap,serverURL);
			break;
		case 5:
			getFriendRequest(soap,serverURL);
			break;
		case 6:
			acceptFriendRequest(soap,serverURL);
			break;
		case 7:
			getFriends(soap,serverURL);
			break;
		case 0:
			break;
		default:
			printf("Opcion no valida\n");
			break;
		}
	}

}

//
//
//
void addNewUser(struct soap soap,char *serverURL){

	char* nick,*pass;
	int res;

	nick = (char*)malloc(sizeof(char*));
	pass = (char*)malloc(sizeof(char*));

	//user* usr;
	//system("clear");
	printf("\nNombre\n");
	scanf("%s",nick);
	printf("Contraseña\n");
	scanf("%s",pass);
	soap_call_ims__addUser(&soap, serverURL, "",nick,pass,&res);

	if(res == -1){
		printf("El servidor esta lleno\n");
	}
	else if(res == -2){
		printf("Ese nick esta en uso\n");
	}
	else{
		printf("Usuario añadido con exito\n");
	}

    free(nick);
    free(pass);
}

//
//
//
int login(struct soap soap,char *serverURL){
	char* nick,*pass;
	int res;

	nick = (char*)malloc(sizeof(char*));
	pass = (char*)malloc(sizeof(char*));

	//user* usr;

	printf("\nNombre\n");
	scanf("%s",nick);
	printf("Contraseña\n");
	scanf("%s",pass);

	soap_call_ims__userLogin(&soap, serverURL, "",nick,pass,&res);

	if(res == -1){
		printf("Nombre de usuario o contraseña incorrectos\n");
		free(nick);
	}
	else{
		user = nick;
	}
	free(pass);

	return res;
}

//
//
//
void addNewFriend(struct soap soap,char *serverURL){
	char* friend_nick = (char*)malloc(sizeof(char*));
	int result;
	system("clear");
	printf("\nNombre del amigo:\n");
	scanf("%s",friend_nick);

	soap_call_ims__addFriend(&soap, serverURL, "",user ,friend_nick, &result);

	if(result == 0){
		printf("Solicitud enviada\n");
	}
	else if(result == 1){
		printf("Ese usuario ya es tu amido\n");
	}
	else if(result == -1){
		printf("No te puedes añadir a ti mismo\n");
	}
	else if(result == -2){
		printf("No estas logueado\n");
	}
	else if(result == -3){
		printf("Ese usuario no existe\n");
	}
	else{
		printf("Invitacion enviada correctamente:\n");
	}
}

//
//
//
void sendFriendRequest(struct soap soap,char *serverURL)
{
	char* friend_nick = (char*)malloc(sizeof(char*));
	int result;
	system("clear");
	printf("\nNombre del amigo:\n");
	scanf("%s",friend_nick);

	soap_call_ims__sendFriendshipRequest(&soap, serverURL, "",user ,friend_nick, &result);

	if(result == 0){
		printf("Solicitud enviada\n");
	}
	else if(result == 1){
		printf("Ese usuario ya es tu amido\n");
	}
	else if(result == -1){
		printf("No te puedes añadir a ti mismo\n");
	}
	else if(result == -2){
		printf("No estas logueado\n");
	}
	else if(result == -3){
		printf("Ese usuario no existe\n");
	}
	else{
		printf("Invitacion enviada correctamente:\n");
	}
}

//
//
//
void getFriendRequest(struct soap soap,char *serverURL)
{
	Char_vector *friends = (Char_vector*)malloc(sizeof(Char_vector));

	int i;
	int numRequestPending = 0;
	soap_call_ims__haveFriendshipRequest(&soap, serverURL,"",user,&numRequestPending);
	if(numRequestPending > 0)
	{
		soap_call_ims__getFriendshipRequests(&soap, serverURL, "",user ,friends);

		system("clear");
		printf("Lista de amistades sin aceptar:\n");

		for(i=0;i < MAXFRIENDS;i++){
			if(friends->data[i] != NULL){
				printf("%d: %s\n",i,friends->data[i]);
			}
		}
	}else
	{
		system("clear");
		printf("No tienes peticiones de amistad\n");
	}
}

//
//
//
void acceptFriendRequest(struct soap soap,char* serverURL)
{
	system("clear");

	int numRequestPending = 0;
	String friend_nick;// = (xsd__string*)malloc(sizeof(xsd__string*));
	char* op = (char*)malloc(sizeof(char*));

	soap_call_ims__haveFriendshipRequest(&soap, serverURL,"",user,&numRequestPending);

	while(numRequestPending > 0)
	{
		soap_call_ims__getFriendshipRequest(&soap,serverURL,"",user,&friend_nick);

		printf("%s te ha enviado una peticion de amistad\n",friend_nick.str);
		printf("Aceptar? (y/n) \n");
		scanf("%s",op);

		if(strcasecmp(op,"y") == 0 || strcasecmp(op,"yes") == 0)
		{
			soap_call_ims__acceptFriendshipRequest(&soap, serverURL,"",user,friend_nick.str,&numRequestPending);
		}else if(strcasecmp(op,"n") == 0 || strcasecmp(op,"no") == 0)
		{
			soap_call_ims__rejectFriendshipRequest(&soap, serverURL,"",user ,friend_nick.str,&numRequestPending);
		}else
		{
			printf("Opcion no valida\n");
		}
	}
	//soap_call_ims__acceptFriendshipRequest(&soap,serverURL,"",user);
}

//
//
//
void getFriends(struct soap soap,char *serverURL)
{
	Char_vector *friends = (Char_vector*)malloc(sizeof(Char_vector));

	int i;
	int numFriends = 0;
	soap_call_ims__haveFriends(&soap, serverURL,"",user,&numFriends);
	if(numFriends > 0)
	{
		soap_call_ims__getFriends(&soap, serverURL, "",user ,friends);

		system("clear");
		printf("Lista de amigos:\n");

		for(i=0;i < MAXFRIENDS;i++){
			if(friends->data[i] != NULL){
				printf("%d: %s\n",i,friends->data[i]);
			}
		}
	}else
	{
		system("clear");
		printf("No tienes amigos!\n");
	}
}
