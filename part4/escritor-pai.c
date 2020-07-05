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
	struct timeval tvstart; /* start date */
	struct timeval tvend; /* end date */
	struct timeval tvduration; /* difference between both dates */
	unsigned int duration; /* difference between both dates in microseconds */

	time_t curtime; /* time in time_t format for format conversion */
	char buffer[30]; /* to write the date in a readable format */

	if (gettimeofday(&tvstart, NULL) == -1) {
		perror("Could not get time of day, exiting.");
		exit(-1);
	}
	curtime = tvstart.tv_sec;
	strftime(buffer,30,"%m-%d-%Y  %T.",localtime(&curtime));
	printf("Start: %s%ld\n",buffer,tvstart.tv_usec);
  
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
	if (gettimeofday(&tvend, NULL) == -1) {
		perror("Could not get time of day, exiting.");
		exit(-1);
	}

	curtime=tvend.tv_sec;
	strftime(buffer,30,"%m-%d-%Y  %T.",localtime(&curtime));

	printf("End: %s%ld\n",buffer,tvend.tv_usec);

	tvduration.tv_sec = tvend.tv_sec - tvstart.tv_sec;
	tvduration.tv_usec = tvend.tv_usec - tvstart.tv_usec;
	duration = tvduration.tv_sec * 1000000 + tvduration.tv_usec;
	printf("Duration: %f seconds\n", (float)duration/1000000);
	
	return 0;
}
