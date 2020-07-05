#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>   
#include "interface.h"

int main(int argc, char *argv[])
{
	int c;
	if(argc!=3){
		perror("Exevc not working correctly");		
		exit(-1);
	}else{
		int value = atoi(argv[1]);
		c = leitor(value);
	}
	return c;
}
