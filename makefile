.c:
	gcc -pthread -o $* $< csapp.o

csapp.o: csapp.c
	gcc -c csapp.c