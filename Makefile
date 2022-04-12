all: main

codage.o: codage.c codage.h tree.h
	gcc -o codage.o -c codage.c

analyse.o: analyse.c analyse.h
	gcc -o analyse.o -c analyse.h

tree.o: tree.c tree.h
	gcc -o tree.o -c tree.c

main: main.o codage.o analyse.o
	gcc -o main main.o tree.o analyse.o codage.o
	
clean:
	rm -f prog *.o