#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>   
#include <sys/file.h>
#include "leitor3.h"

int leitor(char* file){
	printf("file - %s\n\n", file);
	char buf[MAX], buf2[MAX];
	int i, j;
	int fp = open(file, O_RDONLY);
	if (fp == -1) {
		perror ("Error opening file\n");
		exit (-1);
	}else{
		if(flock(fp, LOCK_SH)<0){
			perror("Error locking file\n");
			exit(-1);
		}
		else{
			if(read(fp, buf, MAX) == -1){
				perror("Error reading file\n");
				exit(-1);
			}
			for(i=0; i<LINES-1; i++){  	
				if(read(fp, buf2, MAX) == -1){
					perror("Error reading file\n");
					exit(-1);
				}	
				for(j=0; j<MAX; j++){
					if(buf[j]!=buf2[j]){	
						return -1;
						exit(-1);	
					}
				}
			}
			if(i==(LINES-1)){
				return 0;
			}else{
				return -1;
			}
		}
	}
	if(flock(fp, LOCK_UN)<0){
			perror("Error locking file\n");
			exit(-1);
		}
	if (close (fp) == -1)  {
		perror ("Error closing file\n");
		exit (-1);
	}
}
