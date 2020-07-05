#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>   
#include "leitor.h"

void leitor(){
	char str[SIZE], buf[MAX], buf2[MAX];
	int i, j, r = rand() % NUM_FILES;
	sprintf(str, "SO2014-%d.txt", r);
	int fp = open(str, O_RDONLY);
	int ch=0, lines=0, letras=0;
	read(fp, buf, MAX);
	for(i=0; i<LINES-1; i++){  	
		read(fp, buf2, MAX);
		for(j=0; j<MAX; j++){
			if(buf[j]!=buf2[j]){
				printf("-1\n");
				break;	
			}
		}
	}
	if(i==(LINES-1)){
		printf("0\n");
	}
}

int main(int argc, char *argv[])
{
	leitor();
	return 0;
}
