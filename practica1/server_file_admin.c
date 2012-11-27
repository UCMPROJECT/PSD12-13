
#include "server_file_admin.h"



int serverInit(LUser* luser){
	DIR *dir,*user_dir,*dir_user;
	FILE *user_pass_file;
	struct dirent   *dit,*dit_user;
	char *aux_path,*pass, *name;
	//char path[100];
	int num_user = 0,num_friends = 0;
	User *user;

	// Abrir el directorio server_data
	if ((dir = opendir(DATA_PATH)) == NULL){
		perror("opendir");
		return 0;
	}
	if(DEBUG_MODE) printf("serverInit -> Directorio: %s\n",DATA_PATH);
	// Recorrer el directorio server_data
	while ((dit = readdir(dir)) != NULL){

		if(strcmp(dit->d_name,".") != 0 && strcmp(dit->d_name,"..") != 0){
			//LEER CLAVE
			num_user++;
			// Directorio del pass del usuario = aux_path
			sprintf(aux_path,"%s%s/.pass",DATA_PATH,dit->d_name);

			if((user_pass_file = fopen(aux_path, "r")) == NULL){
				perror("Error abriendo fichero");
				return 0;
			}

			pass = (char*)malloc(256*sizeof(char));
			fscanf( user_pass_file, "%s\\n", pass);

			addUsers(luser,dit->d_name,pass);
			if(DEBUG_MODE){
				printf("serverInit -> Se ha añadido: %s %s\n",dit->d_name,pass);
			}

			if(fclose(user_pass_file) == -1){
				perror("Error cerrando fichero");
			}

			// LEER peticiones enviadas

			// Directorio de la lista de enviados = aux_path
			sprintf(aux_path,"%s%s/.send",DATA_PATH,dit->d_name);

			if((user_pass_file = fopen(aux_path, "r")) == NULL) perror("Error abriendo fichero");

			name = (char*)malloc(256*sizeof(char));

			while(!feof(user_pass_file))
			{
				if(fgets(name,100,user_pass_file) != NULL)
				{
					//fscanf(user_pass_file,"%s\\n",name);
					name[strlen(name)-1] = '\0';
					if(DEBUG_MODE) printf("serverInit -> Send: %s\n",name);
					user = luser->listU[num_user-1];// Coger el usuario actual
					addFriendRequestSend(user,name);
				}
			}

			if(fclose(user_pass_file) == -1) perror("Error abriendo fichero");

			// LEER peticiones recibidas

			// Directorio de la lista de enviados = aux_path
			sprintf(aux_path,"%s%s/.pending",DATA_PATH,dit->d_name);

			if((user_pass_file = fopen(aux_path, "r")) == NULL) perror("Error abriendo fichero");

			while(!feof(user_pass_file))
			{
				if(fgets(name,100,user_pass_file) != NULL)
				{
					//fscanf(user_pass_file,"%s\\n",name);
					name[strlen(name)-1] = '\0';
					if(DEBUG_MODE) printf("serverInit -> Pending: %s\n",name);
					user = luser->listU[num_user-1];// Coger el usuario actual
					addFriendRequestPending(user,name);
				}
			}

			if(fclose(user_pass_file) == -1) perror("Error abriendo fichero");

			//LEER AMIGOS
			// Directorio del usuario = aux_path
			sprintf(aux_path,"%s%s/",DATA_PATH,dit->d_name);

			if ((dir_user = opendir(aux_path)) == NULL){
				perror("opendir");
				return 0;
			}
			num_friends = 0;
			user = luser->listU[num_user-1];// Coger el usuario actual

			// Recorrer el directorio del usuario para añadir los amigos
			while ((dit_user = readdir(dir_user)) != NULL){
				if(strcmp(dit_user->d_name,".") != 0 && strcmp(dit_user->d_name,"..") != 0 && strcmp(dit_user->d_name,".pass") != 0
				   && strcmp(dit_user->d_name,".pending") != 0 && strcmp(dit_user->d_name,".send") != 0){
					addFriend(user,dit_user->d_name);
					if(DEBUG_MODE){
						printf("serverInit -> %s añade a %s\n",user->nick,dit_user->d_name);
					}
					num_friends++;
				}

			}

			if (closedir(dir_user) == -1){
				perror("closedir");
				return 0;
			}
			user->numFriends = num_friends;
				 /*printf("\n%s", dit->d_name);
				 printf(" %d", dit->d_reclen);*/
		}
	 }

	/* int closedir(DIR *dir);
	 *
	 * Close the stream to argv[1]. And check for errors. */
	if (closedir(dir) == -1){
		perror("closedir");
		return 0;
	}


	luser->numUser = num_user;

	if(DEBUG_MODE) printf("serverInit -> Exit Directorio: %s Users: %d\n",DATA_PATH,luser->numUser);

	return 0;
}

void serverFree(LUser* luser){
	int i;
	User *usr;
	for(i = 0;i<luser->numUser;i++){
		usr = luser->listU[1];
		userFree(usr);
	}
	free(luser);
}

int addUsers(LUser* luser,char* nick,char* pass){
	if(luser->numUser >= MAXUSER){
		return -1;
	}
	int found = 0;
	int i = 0;

	while(i < luser->numUser && found == 0){
		if(strcmp(nick,luser->listU[i]->nick) == 0){
			found = 1;
		}
		i++;

	}
	if(found == 1){
		return -2;
	}
	User *usr = userInit(nick,pass);
	luser->listU[luser->numUser] = usr;
	luser->numUser++;

	if(DEBUG_MODE)printf("addUser -> Usuario %s creado en memoria\n",nick);
	return 0;
}

int removeUser(LUser *luser,char* nick){
	int i;
	int found = 0;
	User *usr;
	for(i = 0;i < luser->numUser;i++){
		if(found == 0){
			if(strcmp(nick,luser->listU[i]->nick) == 0){
				found = 1;
				usr = luser->listU[i];
				luser->listU[i] = luser->listU[i+1];
			}
		}
		else{
			luser->listU[i] = luser->listU[i+1];
		}
	}
	if(found == 1){
		userFree(usr);
	}
	luser->numUser--;
	return 0;

}

User* getUser(LUser* luser,char* nick){
	int found = 0;
	int i = 0;
	User *user = NULL;

	while(i < luser->numUser && found == 0){
		if(strcmp(nick,luser->listU[i]->nick) == 0){
			found = 1;
			user = luser->listU[i];
		}
		i++;
	}

	return user;
}

int userLogin(LUser* luser,char* nick,char* pass){
	int found = 0;
	int i = 0;
	User *user = NULL;
	while(i < luser->numUser && found == 0){
		if(strcmp(nick,luser->listU[i]->nick) == 0){
			found = 1;
			user = luser->listU[i];
		}
		i++;
	}
	if(found == 1 && strcmp(pass,user->pass) == 0){
		user->online = 1;
		return 0;
	}

	return -1;
}

int userLogout(LUser* luser,char* nick,char* pass){
	int found = 0;
	int i = 0;
	User *user = NULL;
	while(i < luser->numUser && found == 0){
		if(strcmp(nick,luser->listU[i]->nick) == 0){
			found = 1;
			user = luser->listU[i];
		}
		i++;
	}
	if(found == 1 && strcmp(pass,user->pass) == 0){
		user->online = 0;
		closeFiles(user);
		return 0;
	}

	return -1;
}


