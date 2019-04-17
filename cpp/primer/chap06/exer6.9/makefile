CC = clang++ -c

main.o: fact.o factMain.o
	clang++ fact.o factMain.o -o main

clean:
	rm -f *.o

fact.o:
	$(CC) fact.cc

factMain.o:
	$(CC) factMain.cc

