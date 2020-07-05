//escolher 3 ficheiros aleatoriamente e criar 3 threads em que cada thread avalia um ficheiro

#include <stdio.h>
#include <pthread.h>
#include "leitor-paralelo2.h"

pthread_t tid[NUM_THREADS];

void *interface(void *file){
	int a = leitor(*((int *) file));;
	return (void *) a;
}



int main(int argc, char *argv[])
{
	int i, r[NUM_THREADS];
	void *status;

	for(i=0; i<NUM_THREADS; i++){
	
		int *arg = malloc(sizeof(*arg));
  
     		if ( arg == NULL ) {
            		fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
            		exit(EXIT_FAILURE);
        	}
	
		r[i] = rand() % NUM_FILES;
		
		*arg = r[i];

		pthread_create(&(tid[i]),NULL, &interface, arg);
		
	}
	for(i=0; i<NUM_THREADS; i++){
		pthread_join(tid[i], &status);
		printf("%d\n",(int)status);
	}	
	//não consigo chamar a função de outro ficheiro -.- fuck my life 
	
	//
	//
	//não sei quem é que imprime o valor de retorno do leitor neste caso 
	//sleep(5);
	return 0;
}
