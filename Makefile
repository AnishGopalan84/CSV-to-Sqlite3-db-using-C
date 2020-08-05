all : csvtoDB dTypeAnly

csvtoDB : csvtoDB.o
	gcc csvtoDB.o -o csvtoDB -lsqlite3
csvtoDB.o : csvtoDB.c
	gcc -c csvtoDB.c 

clean:
	rm -f *.o csvtoDB dTypeAnly
