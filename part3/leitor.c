#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>   
#include "leitor.h"

int leitor(){
	char str[SIZE], buf[MAX], buf2[MAX];
	int i, j, r = rand() % NUM_FILES;
	sprintf(str, "SO2014-%d.txt", r);
	int fp = open(str, O_RDONLY);
	if (fp == -1) {
		perror ("Error opening file");
		exit (-1);
	}else{
		if(flock(fp, LOCK_SH)<0){
			perror("Error locking file\n");
			exit(-1);
		}
		else{
			if(read(fp, buf, MAX) == -1){
				perror("Error reading file");
				exit(-1);
			}
			for(i=0; i<LINES-1; i++){  	
				if(read(fp, buf2, MAX) == -1){
					perror("Error reading file");
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
		perror ("Error closing file");
		exit (-1);
	}
}	
int main(int argc, char *argv[])
{
	printf("%d\n",leitor());
	return 0;
}
