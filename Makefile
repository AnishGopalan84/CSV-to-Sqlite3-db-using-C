all : csvtoDB dTypeAnly

csvtoDB : csvtoDB.o
	gcc csvtoDB.o -o csvtoDB -lsqlite3
csvtoDB.o : csvtoDB.c
	gcc -c csvtoDB.c 

dTypeAnly : dTypeAnly.o
	gcc dTypeAnly.o -o dTypeAnly 
dTypeAnly.o : dTypeAnly.c
	gcc -c dTypeAnly.c 
clean:
	rm -f *.o csvtoDB dTypeAnly