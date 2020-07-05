#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <sys/wait.h>
#include <errno.h>
#include "escritor-paralelo.h"

pthread_t tid[NUM_THREADS];
static void signal_handler(int);

int lock=1; //tá a 1 faz lock
int erro=0; //tá a 1 escreve com erros

void *interface(){
	while(TRUE){
		int i = rand() % NUM_FILES;
		escritor(i, lock, erro);
	}
}

static void signal_handler(int signo)
{
    switch( signo ){
        case SIGUSR1:
            printf( "received SIGUSR1 \n");
            if(lock==1){
				lock=0;
			}else{
				lock=1;
			}
            break;
        
        
        case SIGUSR2:
            printf( "received SIGUSR2 \n");
            if(erro==1){
				erro=0;
			}else{
				erro=1;
			}
            break;

		case SIGTSTP:
            printf( "received SIGTSTP \n");
            //exit(1);
			break;
			
        default:
                break;
    }

    return;
}

int main(int argc, char *argv[])
{
	int i;
	
	if( signal( SIGUSR1, signal_handler) == SIG_ERR  ){
		printf("Pærent: Unable to create handler for SIGUSR1\n");
	}
	
	if( signal( SIGUSR2, signal_handler) == SIG_ERR  ){
		printf("Pærent: Unable to create handler for SIGUSR2\n");
	}
	
	if( signal( SIGTSTP, signal_handler) == SIG_ERR  ){
		printf("Pærent: Unable to create handler for SIGTSTP\n");
	}
	
	for(i=0; i<NUM_THREADS; i++){
		if (pthread_create(&(tid[i]),NULL, &interface, NULL) != 0){
			printf("Error creating thread %d", i);
			return -1;
		}
	}
	
	while(1);
	return 0;
}	
