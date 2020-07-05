# Conteudo da Makefile
main: escritor.o leitor.o
	gcc -g -o escritor escritor.o
	gcc -g -o leitor leitor.o	

escritor.o: escritor.c escritor.h
	gcc -g -c escritor.c

leitor.o: leitor.c leitor.h
	gcc -g -c leitor.c
