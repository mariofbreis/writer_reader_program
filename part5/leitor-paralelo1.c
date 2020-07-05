#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>  
#include <time.h>  
#include <sys/wait.h>
#include "leitor-paralelo1.h"

int main(int argc, char *argv[])
{
	
	char *my_args[5], *ptr;
	pid_t pid, pids[NUM_CHILDS];
	int i, n=NUM_CHILDS, status;
	
	for(i=0;i<NUM_CHILDS;i++){
		int r = rand() % NUM_FILES; 
		if ((pids[i] = fork()) < 0) {
			perror("fork");
    			exit(1);
		}
		else if (pids[i] == 0) {   
			sprintf(ptr, "%d", r);
			my_args[0] = "interface.exe";
		  	my_args[1] = ptr;
		 	my_args[2] = "arg2";
		  	my_args[3] = NULL; 	
			execv("interface", my_args);
			exit(0);
		}
	}

	while (n > 0) {
		pid=wait(&status);	
		--n;
		if (WEXITSTATUS(status)==255){
			printf("-1\n");
		}else{
			printf("%d\n", WEXITSTATUS(status));
		}
	}
	
	return 0;
}
