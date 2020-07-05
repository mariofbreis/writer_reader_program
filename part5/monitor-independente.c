#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "monitor-independente.h"

pthread_mutex_t mutex;

void sair(){}

void leitor(char* item){
	printf("leitor");
}

void escritor(char* item){
	printf("escritor");
}

int main(){
	char* item;
	char buf[BUF_SIZE];
	
	while(TRUE) {
		//read(0, &buf, sizeof(char));
		scanf( "%s" , buf );
		pthread_mutex_lock(&mutex);
		item = strtok (buf, " ");
		while (item != NULL){
		
			if (strlen(item)==12){leitor(item);}
			if (strlen(item)==2){escritor(item);}
			if (strlen(item)==4){sair();}

			item = strtok (NULL, " ");
		}
		
		pthread_mutex_unlock(&mutex);
	}
	return 0;
}
