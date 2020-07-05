#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>  
#include <sys/types.h>
#include "leitor2.h"

Retu* leitor2(Att *ptr){
	char buf[MAX], buf2[MAX];
	char str[SIZE];
	int loop;
	
	Retu *turn = malloc(sizeof(Retu));
	
	sprintf(str, "SO2014-%d.txt", ptr->file);
	
	int fp = open(str, O_RDONLY);	
	if (fp == -1) {
		perror ("Error opening file");
		exit (-1);
	}else{
		if (ptr->start_line==1){
			if(lseek(fp,0,SEEK_SET)<0){
				perror("Error with lseek");
				exit(-1);
			}
		}else{
			if(lseek(fp,(ptr->start_line)*10,SEEK_SET)<0){
				perror("Error with lseek");
				exit(-1);
			}
		}
		if(read(fp, buf, MAX) == -1){
			perror("Error reading file");
			exit(-1);
		}
		
		turn->first = buf[0];
		int i, j;

		for(i=0; i<(ptr->end_line)-(ptr->start_line); i++){  	
			if(read(fp, buf2, MAX) == -1){
				perror("Error reading file");
				exit(-1);
			}	
			for(j=0; j<MAX; j++){
				if(buf[j]!=buf2[j]){	
					turn->result = 1;	
				}
			}
		}
		if (close (fp) == -1)  {
			perror ("Error closing file");
			exit (-1);
		}
		
	}
	return turn;
}
