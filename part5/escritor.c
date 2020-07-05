#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/file.h>

#include "escritor.h"


#define NB_ITERATIONS 512
#define NB_STRINGS 10

char mystrings[STRING_SZ][NB_STRINGS] = { "aaaaaaaaa\n", 
				"bbbbbbbbb\n",
				"ccccccccc\n",
				"ddddddddd\n",
				"eeeeeeeee\n",
				"fffffffff\n",
				"ggggggggg\n",
				"hhhhhhhhh\n",
				"iiiiiiiii\n",
				"jjjjjjjjj\n" };

char* myfiles[NB_FILES] = { "SO2014-0.txt", 
			    "SO2014-1.txt",
			    "SO2014-2.txt",
			    "SO2014-3.txt",
			    "SO2014-4.txt" };


int main (int argc, char** argv) {
	int   i;
  
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	/* Initialize the seed of random number generator */
  	srandom ((unsigned) time(NULL));

  
  	for (i=0; i<NB_ITERATIONS; i++) {
    		char  *file_to_open = myfiles[get_random(NB_FILES)];
    		int   fd  = open (file_to_open, O_RDWR | O_CREAT, mode);

    		if (fd == -1) {
      			perror ("Error opening file");
      			exit (-1);
    		}
    		else {
			if(flock(fd, LOCK_EX)<0){
				perror("Error locking file\n");
				exit(-1);
			}

			char *string_to_write  = mystrings[get_random(NB_STRINGS)];
			int  j;

			for (j=0; j<NB_ENTRIES; j++) {
				if (write (fd, string_to_write, STRING_SZ) == -1) {
					perror ("Error writing file");
					exit (-1);
				}
			}
    		}
		if(flock(fd, LOCK_UN)<0){
				perror("Error locking file\n");
				exit(-1);
		}
    		if (close (fd) == -1)  {
			perror ("Error closing file");
			exit (-1);
    		}
  	}
  	return 0;
}
