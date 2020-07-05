# Conteúdo da Makefile
main: escritor.o leitor.o escritor-pai.o
	gcc -g -o escritor escritor.o
	gcc -g -o leitor leitor.o	
	gcc -g -o escritor-pai escritor-pai.o

escritor-pai.o:escritor-pai.c escritor-pai.h
	gcc -g -c escritor-pai.c

escritor.o: escritor.c escritor.h
	gcc -g -c escritor.c

leitor.o: leitor.c leitor.h
	gcc -g -c leitor.c
