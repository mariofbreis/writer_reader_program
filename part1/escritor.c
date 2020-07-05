#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>    
#include "escritor.h"

#define CALLS 5120
#define BUFFSIZE 100
#define TESTES 1024
#define NUM_FILES 5
#define STRINGSIZE 15
#define NUM_LETTERS 10

void escritor(){
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
	char str[STRINGSIZE];
	int r = rand() % NUM_FILES;
	sprintf(str, "SO2014-%d.txt", r);
	int fd = open(str, O_RDWR | O_CREAT | O_APPEND | O_TRUNC, mode);

	char letra[BUFFSIZE];
	int k, l = rand() % NUM_LETTERS;
	for(k=0; k<NUM_LETTERS-1; k++){
		letra[k]='a'+l;			
	}
	letra[NUM_LETTERS-1]='\n';
	letra[NUM_LETTERS]='\0';
	size_t n = strlen(letra);

	write (fd, letra, n);
	
	close(fd);

	int j;
	int fd2 = open(str, O_RDWR | O_APPEND);
	for(j=0;j<TESTES-1;j++){
		write (fd2, letra, n);
	}
	close(fd2);
}

int main(int argc, char *argv[])
{
	int i;
	for(i=0;i<CALLS;i++){		
		escritor();
	}
	return 0;
}