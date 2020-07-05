#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "escritor2.h"

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

char myerrorstrings[STRING_SZ][NB_STRINGS] = { "zaaaaaaaa\n", 
				"xbbbbbbbb\n",
				"ycccccccc\n",
				"wdddddddd\n",
				"teeeeeeee\n",
				"uffffffff\n",
				"vgggggggg\n",
				"khhhhhhhh\n",
				"qiiiiiiii\n",
				"pjjjjjjjj\n" };



void escritor(int file, int lock, int erro) {
	char str[SIZE];
	sprintf(str, "SO2014-%d.txt", file);
  
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

  	int   fd  = open (str, O_RDWR | O_CREAT, mode);
    
    if (fd == -1) {
    	perror ("Error opening file");
    	exit (-1);
    }else {
    	if(lock==1){
			if(flock(fd, LOCK_EX)<0){
				perror("Error locking file\n");
				exit(-1);
			}
		}
		char *string_to_write;
		if(erro==0){
			string_to_write  = mystrings[get_random(NB_STRINGS)];
		}else{
			string_to_write  = myerrorstrings[get_random(NB_STRINGS)];
		}
		int  j;
	
		for (j=0; j<NB_ENTRIES; j++) {
			if (write (fd, string_to_write, STRING_SZ) == -1) {
				perror ("Error writing file");
				exit (-1);
			}
		}
	}
	if(lock==1){
		if(flock(fd, LOCK_UN)<0){
				perror("Error locking file\n");
				exit(-1);
		}
	}
	if (close (fd) == -1)  {
		perror ("Error closing file");
		exit (-1);
	}
}
