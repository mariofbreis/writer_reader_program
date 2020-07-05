#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10
#define LINES 1024
#define SIZE 15
#define NUM_FILES 5

typedef struct atribute{
	int file, start_line, end_line;
}Att;

typedef struct ret{
	char first;
	int result;
}Retu;
/* Retu == struct ret */

Retu* leitor2(Att *ptr);
