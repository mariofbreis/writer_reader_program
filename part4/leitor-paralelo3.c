//ler a primeira linha antes de lançar as k threads ver se faz parte das 10 linhas possiveis e se sim continua se não 
//exit() e depois passar a linha como parâmetro

//cada umas das threads lê a sua primeira linha e testa o seu bloco de texto e retorna o valor da primeira linha e 0 
//ou -1 depois o programa testa as k linhas que as threads devolvem e vê se o programa está bem escrito



#include <stdio.h>
#include <stdlib.h>
#include "leitor-paralelo3.h"

#define NUM_READS NB_ENTRIES/NUM_THREADS

pthread_t tid[NUM_THREADS];

Att* atr[NUM_THREADS];
Retu* back[NUM_THREADS];
Retu* returned;

void *interface(void *i){
	returned = malloc(sizeof(Retu));
		
	returned = leitor2(atr[*((int *) i)]);
	
	return (void *) returned;
}


int main(int argc, char *argv[]){
	int i;
	int random = rand() % NUM_FILES;;
	void *status;
	
	for(i=0; i<NUM_THREADS; i++){
		
		atr[i] = (struct atribute *) malloc(sizeof(struct atribute *));
		
		atr[i]->file = random;
		
		atr[i]->start_line = i*NUM_READS+1;
		
		if(i<NUM_THREADS){
			atr[i]->end_line = atr[i]->start_line+NUM_READS-1;	
		}
		if(i==NUM_THREADS-1){
			atr[i]->end_line = NB_ENTRIES;	
		}
		
		int *arg = malloc(sizeof(*arg));
  
     	if ( arg == NULL ) {
        	fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
        	exit(EXIT_FAILURE);
        }
	
		*arg = i;
		
		pthread_create(&(tid[i]),NULL, &interface, arg);
		
	}
	
	for(i=0; i<NUM_THREADS; i++){
		pthread_join(tid[i], &status);
		back[i] = (struct ret *) malloc(sizeof(struct ret *));
		back[i] = status; 
	}
	int j;
	for(i=1; i<NUM_THREADS; i++){
		if(back[i-1]->first!=back[i]->first||back[i-1]->result!=back[i]->result){
			j=-1;
		}
		else{
			j=0;
		}
	}
	printf("%d\n",j);
	return 0;
}
