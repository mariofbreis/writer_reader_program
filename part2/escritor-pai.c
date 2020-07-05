#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>  
#include <time.h>  
#include "escritor-pai.h"

int main(int argc, char *argv[])
{
	time_t now, end;
    double time_spent;
	now = time ( NULL );

	char *my_args[5];
	my_args[0] = "escritor.exe";
  	my_args[1] = "arg1";
 	my_args[2] = "arg2";
  	my_args[3] = NULL;

	pid_t pid, pids[NUM_CHILDS];
	int i, n=NUM_CHILDS, status;
	
	for(i=0;i<NUM_CHILDS;i++){
		if ((pids[i] = fork()) < 0) {
			perror("fork");
    			exit(1);
		}else if (pids[i] == 0) {    	
			execv("escritor", my_args);
			exit(0);
		}
	}
	while (n > 0) {
		pid=wait(&status);	
		--n;
	}
	end = time ( NULL );
	time_spent = (double)(end - now);
	printf("O programa demora %f segundos a ser corrido\n",time_spent);	
	
	return 0;
}
