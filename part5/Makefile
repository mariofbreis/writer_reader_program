COPTS = -g #-Wall

# Conteúdo da Makefile
main: escritor.o leitor.o escritor-pai.o leitor-paralelo1.o leitor-paralelo2.o leitor-paralelo3.o interface.o leitor-paralelo-monitorintegrado.o escritor-paralelo.o monitor-independente.o
	gcc  -o interface interface.o $(COPTS)
	gcc  -o escritor escritor.o $(COPTS)	
	gcc  -o escritor-pai escritor-pai.o $(COPTS)
	gcc  -o leitor-paralelo1 leitor-paralelo1.o $(COPTS)
	gcc  -o leitor-paralelo2 leitor-paralelo2.o -lpthread $(COPTS)
	gcc  -o leitor-paralelo3 leitor-paralelo3.o -lpthread $(COPTS)
	gcc  -o leitor-paralelo-monitorintegrado leitor-paralelo-monitorintegrado.o -lpthread $(COPTS)
	gcc  -o escritor-paralelo escritor-paralelo.o -lpthread $(COPTS)
	gcc  -o monitor-independente monitor-independente.o $(COPTS)

monitor-independente.o: monitor-independente.c monitor-independente.h
	gcc -c monitor-independente.c $(COPTS)

escritor-paralelo.o: escritor-paralelo.c escritor-paralelo.h
	gcc  -c escritor-paralelo.c $(COPTS)

leitor-paralelo-monitorintegrado.o: leitor-paralelo-monitorintegrado.c leitor-paralelo-monitorintegrado.h buffer.h
	gcc  -c leitor-paralelo-monitorintegrado.c $(COPTS)
	
leitor-paralelo1.o: leitor-paralelo1.c leitor-paralelo1.h
	gcc  -c leitor-paralelo1.c $(COPTS)

leitor-paralelo2.o: leitor-paralelo2.c leitor-paralelo2.h
	gcc  -c leitor-paralelo2.c $(COPTS)

leitor-paralelo3.o: leitor-paralelo3.c leitor-paralelo3.h
	gcc  -c leitor-paralelo3.c $(COPTS)
	
escritor-pai.o:escritor-pai.c escritor-pai.h
	gcc  -c escritor-pai.c $(COPTS)

escritor.o: escritor.c escritor.h
	gcc  -c escritor.c $(COPTS)

leitor.o: leitor.c leitor.h
	gcc  -c leitor.c $(COPTS)
	
interface.o: interface.c interface.h
	gcc  -c interface.c $(COPTS)

clean :
	rm leitor-paralelo-monitorintegrado.o leitor-paralelo1.o leitor-paralelo2.o interface.o escritor-pai.o escritor.o leitor.o leitor-paralelo1 leitor-paralelo2 interface escritor-pai escritor SO2014-0.txt SO2014-1.txt SO2014-2.txt SO2014-3.txt SO2014-4.txt leitor-paralelo3 leitor-paralelo3.o escritor-paralelo escritor-paralelo.o monitor-independente.o leitor5 leitor-paralelo-monitorintegrado monitor-independente leitor5.o
