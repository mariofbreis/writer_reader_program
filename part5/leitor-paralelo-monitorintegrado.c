#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include "buffer.h"
#include "leitor-paralelo-monitorintegrado.h"

pthread_mutex_t mutex;
sem_t full, empty;
buffer_item buffer[BUFFER_SIZE];
int counter=0;

pthread_t tid;
pthread_attr_t attr;


int insert_item(buffer_item item) {
	if(counter < BUFFER_SIZE) {
		buffer[counter] = malloc(sizeof(char)*strlen(item));
   		strcpy(buffer[counter], item);
   		counter++;
      	return 0;
   }else { 
      	return -1;
   }
}

int remove_item(buffer_item *item) {
	if(counter > 0) {
	    *item = buffer[(counter-1)];
    	counter--;
    	return 0;
	}else {
    	return -1;
   }
}

void *filhos(){
	buffer_item item;
	
	while(TRUE) {
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		if(remove_item(&item)) {
        	fprintf(stderr, "child report error condition\n \n");
      	}else {
         	printf("child read file - %s\n \n", item);
      	}
		int a = leitor(item);
		printf(" the file %s after been reed returned %d\n", item, a);
		sleep(5);
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}

void *pai(){
	char buf[BUF_SIZE];
	char* item;
	int i;

	for(i=0; i<THREADS_FILHOS; i++){
		pthread_create(&tid,NULL,&filhos,NULL);
	}

	while(TRUE) {
		//read(0, &buf, sizeof(char));
		scanf( "%s" , buf );
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		item = strtok (buf, " ");
		while (item != NULL){
			
			if(insert_item(item)) {
				fprintf(stderr, " father report error condition\n \n");
			}else {
				printf("father introduced file - %s\n \n", item);
			}

			item = strtok (NULL, " ");
		}
		
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}
	

void initializeData() {
   	pthread_mutex_init(&mutex, NULL);
   	sem_init(&full, 0, 0);
   	sem_init(&empty, 0, BUFFER_SIZE);
   	pthread_attr_init(&attr);
   	counter = 0;
}

int main(int argc, char *argv[]) {
	
	initializeData();
	
	pthread_create(&tid,NULL,&pai,NULL);
	while(TRUE){
		sleep(30);
	}
   	printf("Exit the program\n \n");
   	exit(0);
}
